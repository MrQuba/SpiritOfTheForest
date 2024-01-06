#include "enemyClass.h"

void enemy::enemyBrain(sf::Sprite& pSprt, sf::Sprite& eSprt, sf::Clock& attCClock, sf::Clock& coneCClock, bool pFL){

    if(this->enemyHealth <= this->enemyHealth / 2){
        attackCooldown /= 2;
        coneCooldown /= 2;
        speedMultiplier = 1.5;
    }
        if(this->enemyHealth <= this->enemyHealth / 4){
        attackCooldown /= 2;
        coneCooldown /= 2;
        speedMultiplier = 2.25;
    }

if(isProjectileAvalible && attCClock.getElapsedTime().asSeconds() >= attackCooldown){
                attCClock.restart();
            isProjectileAvalible = false;
    }
        if(isConeAvalible && coneCClock.getElapsedTime().asSeconds() >= coneCooldown){
                coneCClock.restart();
            isConeAvalible = false;
            if(pFL)
            pineCone.setPosition(pSprt.getPosition().x + pSprt.getLocalBounds().width, 0);
            else if(!pFL)
            pineCone.setPosition(pSprt.getPosition().x - pSprt.getLocalBounds().width, 0);
        }
if(pSprt.getPosition().x - eSprt.getPosition().x <= 0) {
    this->enemyVelocity.x = speedMultiplier * -1.2f;
    enemyFacesLeft = true;
}
if(pSprt.getPosition().x - eSprt.getPosition().x >= 0) {
    this->enemyVelocity.x = speedMultiplier * 1.2f;
    enemyFacesLeft = false;
}

if(pSprt.getPosition().x - eSprt.getPosition().x <= 100 && pSprt.getPosition().x - eSprt.getPosition().x >= 50 || pSprt.getPosition().x - eSprt.getPosition().x >= 100 && pSprt.getPosition().x - eSprt.getPosition().x <= 150) {
this->gravityMultiplier = 75;
}
else this->gravityMultiplier = 10;
 eSprt.move(this->enemyVelocity);
}
