#include "../playerClass.h"
collisions col;
void player::arrowUpdate(sf::Sprite& aSprite, bool& isA, float g, sf::RenderWindow& window, sf::Sprite& pSprite, bool aFL){

if(!isA && aFL) aSprite.move(-10.f, 5 * g);
else if(!isA && !aFL) aSprite.move(10.f, 5 * g);

if(isA) aSprite.setPosition(pSprite.getPosition().x + pSprite.getGlobalBounds().width, pSprite.getPosition().y);


if(col.borderCollision(aSprite, window) || col.groundCollision(aSprite, window)) isA = true;



}
