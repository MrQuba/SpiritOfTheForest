#include "collisions.h"

bool collisions::borderCollision(sf::Sprite& sprite, sf::RenderWindow& window){

if(sprite.getPosition().x <= 0) {
        sprite.setPosition(0.f, sprite.getPosition().y);
        return true;

}
else if(sprite.getPosition().x + sprite.getGlobalBounds().width >= window.getSize().x) {

        sprite.setPosition(window.getSize().x - sprite.getGlobalBounds().width, sprite.getPosition().y);
        return true;
}
else return false;
}
