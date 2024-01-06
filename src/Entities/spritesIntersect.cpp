#include "entitiesClass.h"

bool entities::spritesIntersect(sf::Sprite& s1, sf::Sprite& s2){

if(s1.getGlobalBounds().intersects(s2.getGlobalBounds()))
return true;

else return false;

}
