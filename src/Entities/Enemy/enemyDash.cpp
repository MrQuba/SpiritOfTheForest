#include "enemyClass.h"

void enemy::enemyDash(sf::Sprite& pSprite, sf::Sprite& eSprite){
if (pSprite.getPosition().x - eSprite.getPosition().x >= 600) { eSprite.setPosition(pSprite.getPosition().x - 300, eSprite.getPosition().y); enemyDashed = true;}
if (pSprite.getPosition().x - eSprite.getPosition().x <= -600) { eSprite.setPosition(pSprite.getPosition().x + 300, eSprite.getPosition().y); enemyDashed = true;}
}
