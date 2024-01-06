#include "collisions.h"

bool collisions::groundCollision(sf::Sprite& sprite, sf::RenderWindow& window){

    if(sprite.getPosition().y + sprite.getGlobalBounds().height >= window.getSize().y - 54) return true;
    else return false;

}
