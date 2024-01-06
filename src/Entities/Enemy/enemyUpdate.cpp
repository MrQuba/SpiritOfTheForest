#include "enemyClass.h"
movement mv;
entities ent(1);
collisions cols;
using namespace std;
bool enemy::enemyUpdate(sf::Sprite& eSprite, sf::RenderWindow& window, sf::Sprite& pSprt, sf::RenderWindow& wind, sf::Sprite& ePsprt, sf::Sprite& aSprt, int pDmg, bool isA, bool pFL){

    enemyBrain(pSprt, eSprite, attackCooldownClock, coneCooldownClock, pFL);

    mv.gravitationForce(ent.gravity, enemyVelocity);
        if(this->enemyVelocity.x >= 1 || this->enemyVelocity.x <= -1)
        this->isEnemyMoving = true;
        else this->isEnemyMoving = false;
        if(isEnemyMoving){
        this->enemyMovementAnimationFrame++;
            if(this->enemyMovementAnimationFrame <= 10  && this->enemyMovementAnimationFrame >! 10){
        this->enemyTexture.loadFromFile("txt/Enemy/enemySprite.png", sf::IntRect(0, 0, 16, 16));
            }
           else if(this->enemyMovementAnimationFrame <= 20 && this->enemyMovementAnimationFrame >! 20 ||this->enemyMovementAnimationFrame <= 40 && this->enemyMovementAnimationFrame > 30 ){
        this->enemyTexture.loadFromFile("txt/Enemy/enemySprite.png", sf::IntRect(16, 0, 16, 16));
            }
           else if(this->enemyMovementAnimationFrame <= 30 && this->enemyMovementAnimationFrame > 20){
        this->enemyTexture.loadFromFile("txt/Enemy/enemySprite.png", sf::IntRect(32, 0, 16, 16));
            }
          else if(this->enemyMovementAnimationFrame > 40) this->enemyMovementAnimationFrame = 0;
    }
    if(!isEnemyMoving)
        this->enemyTexture.loadFromFile("txt/Enemy/enemySprite.png", sf::IntRect(16, 0, 16, 16));


    if(enemyFacesLeft && !enemyRotatedLeft){
        enemyRotatedLeft = true;
        eSprite.scale(-1.f, 1.f);
        enemyProjectileFacesLeft = true;
    }
    else if(!enemyFacesLeft && enemyRotatedLeft){
        enemyRotatedLeft = false;
        eSprite.scale(-1.f, 1.f);
        enemyProjectileFacesLeft = false;
    }
    eSprite.move(this->enemyVelocity);

        if(cols.groundCollision(eSprite, window)) {
        eSprite.setPosition(eSprite.getPosition().x, window.getSize().y - eSprite.getGlobalBounds().height - 54);
    }
    cols.borderCollision(eSprite, window);

    eSprite.setPosition(eSprite.getPosition());

    enemyProjectileUpdate(enemyProjectileSprite, isProjectileAvalible, enemyProjectileFacesLeft, enemyAttacked, enemyAttackCooldownClock, enemyAttackHasCooldown, wind, pSprt, eSprite, pineCone);

        if(ent.spritesIntersect(eSprite, aSprt)){

        enemyHealthBar(this->enemyHealthRepresentation, window);
        enemyHitDetection(ent.enemyInvincibilityClock, pDmg, enemyWasHit, this->enemyHealthRepresentation, window, this->enemySprite);

    }

    if(ent.spritesIntersect(ePsprt, pSprt)) this->isProjectileAvalible = true;
    if(ent.spritesIntersect(this->pineCone, pSprt)) this->isConeAvalible = true;

    if(this->enemyHealth <= 0) enemyHealth = 0;
    if(this->enemyHealth <= 0) return false;
    else return true;
}

