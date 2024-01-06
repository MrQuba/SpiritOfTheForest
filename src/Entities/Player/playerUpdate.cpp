#include "playerClass.h"
movement m;
entities e(1);
collisions c;
enemy enmy(1);
bool player::playerUpdate(sf::Sprite& sprite, sf::RenderWindow& window, sf::Sprite& eSprite, sf::Sprite& ePSprite, sf::Sprite& pC){

    spacePressDetection(isJumping, playerVelocity, jumpHeight, e.gravity, doubleJump, jumpCount);

    rightPressDetection(playerVelocity, playerSpeed, e.gravity, sprite, facesLeft);
    leftPressDetection(playerVelocity, playerSpeed, e.gravity, sprite, facesLeft);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        playerVelocity.y = e.gravity * 100;

    leftMouseButtonClickDetection(isArrowAvalible, arrowFacesLeft);

    m.gravitationForce(e.gravity, playerVelocity);
    if(this->playerVelocity.x >= 1 || this->playerVelocity.x <= -1)
        this->isMoving = true;
    else this->isMoving = false;
    if(isMoving){
        this->movementAnimationFrame++;
            if(this->movementAnimationFrame <= 10  && this->movementAnimationFrame >! 10){
        this->playerTexture.loadFromFile("txt/Player/playerSprite.png", sf::IntRect(0, 0, 16, 16));
            }
           else if(this->movementAnimationFrame <= 20 && this->movementAnimationFrame >! 20 ||this->movementAnimationFrame <= 40 && this->movementAnimationFrame > 30 ){
        this->playerTexture.loadFromFile("txt/Player/playerSprite.png", sf::IntRect(16, 0, 16, 16));
            }
           else if(this->movementAnimationFrame <= 30 && this->movementAnimationFrame > 20){
        this->playerTexture.loadFromFile("txt/Player/playerSprite.png", sf::IntRect(32, 0, 16, 16));
            }
          else  if(this->movementAnimationFrame > 40) this->movementAnimationFrame = 0;
    }
    if(!isMoving)
        this->playerTexture.loadFromFile("txt/Player/playerSprite.png", sf::IntRect(16, 0, 16, 16));

    if(facesLeft && !rotatedLeft){
        rotatedLeft = true;
        sprite.scale(-1.f, 1.f);
    }
    else if(!facesLeft && rotatedLeft){
        rotatedLeft = false;
        sprite.scale(-1.f, 1.f);
    }

    sprite.move(playerVelocity);

    playerVelocity.x /= 2;

    if(c.groundCollision(sprite, window)) {
        sprite.setPosition(sprite.getPosition().x, window.getSize().y - sprite.getGlobalBounds().height - 54);
        isJumping = false;
        jumpCount = 0;
    }
    if(c.borderCollision(sprite, window)) isJumping = false;

    arrowUpdate(arrowSprite, isArrowAvalible, e.gravity, window, sprite, arrowFacesLeft);


    if(e.spritesIntersect(arrowSprite, eSprite)){
        isArrowAvalible = true;
    }
        if(e.spritesIntersect(sprite, eSprite)){
        if(!playerIsInvincible) {
            playerHealth--;
            if(facesLeft)
            sprite.move(100 * playerVelocity.x, sprite.getPosition().y);
            if(!facesLeft)
            sprite.move(-100 * playerVelocity.x, sprite.getPosition().y);

            playerWasHit = true;
        }
    }
            if(e.spritesIntersect(sprite, ePSprite)){
        if(!playerIsInvincible) {
            playerHealth --;
            if(facesLeft)
            sprite.move(50 * playerVelocity.x, sprite.getPosition().y);
            if(!facesLeft)
            sprite.move(-50 * playerVelocity.x, sprite.getPosition().y);
            playerWasHit = true;
        }
    }
    if(e.spritesIntersect(sprite, pC)){
            this->playerHealth -= 5;
            playerWasHit = true;

    }
    if(playerWasHit){
        playerIsInvincible = true;
        if(e.invincibilityClock.getElapsedTime().asMilliseconds() >= 200){ playerIsInvincible = false;
        playerWasHit = false;}
    }


            this->playerHealthRepresentation.setSize(sf::Vector2f(this->playerHealth * 10, this->playerHealthRepresentation.getSize().y));
    if(playerHealth <= 0) {
        playerHealth = 0;
        return false;
    }
    else return true;
}
