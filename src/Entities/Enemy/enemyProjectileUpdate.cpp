#include "enemyClass.h"
entities et(1);
collisions cl;
void enemy::enemyProjectileUpdate(sf::Sprite& ePSprite, bool isPA, bool ePFL, bool eA, sf::Clock& aCl, bool aC, sf::RenderWindow& window, sf::Sprite& pSprt, sf::Sprite& eSprt, sf::Sprite& pC){

 if(this->enemyHealth < phaseRequirement1 && phase == 1){
        phase++;
    this->attackSpeedMultiplier = 1.5;
    this->coneSpeedMultiplier = 1.5;
 }
 else if(this->enemyHealth < phaseRequirement2 && phase == 2){
      phase++;
    this->attackSpeedMultiplier = 1.75;
    this->coneSpeedMultiplier = 2;
 }
  else if(this->enemyHealth < phaseRequirement3 && phase == 3){
    this->attackSpeedMultiplier =  2;
    this->coneSpeedMultiplier = 2.5;
 }
if(!isPA && ePFL){
    ePSprite.move(this->attackSpeedMultiplier * -10.f, gravityMultiplier * et.gravity);
}
if(!isPA && !ePFL){
    ePSprite.move(this->attackSpeedMultiplier * 10.f, gravityMultiplier * et.gravity);
}


if(cl.borderCollision(ePSprite, window) || cl.groundCollision(ePSprite, window)) isPA = true;

if(isPA) ePSprite.setPosition(enemySprite.getPosition().x + enemySprite.getGlobalBounds().width, enemySprite.getPosition().y);

if(!isConeAvalible){
    pC.move(0, this->coneSpeedMultiplier * 100 * et.gravity);
}


if(cl.borderCollision(pC, window) || cl.groundCollision(pC, window)) isConeAvalible = true;

if(isConeAvalible) pC.setPosition(enemySprite.getPosition().x + enemySprite.getGlobalBounds().width, enemySprite.getPosition().y);
}
