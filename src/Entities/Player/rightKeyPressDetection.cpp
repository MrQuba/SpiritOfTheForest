#include "playerClass.h"

void player::rightPressDetection(sf::Vector2f& v2f, float pS, float g, sf::Sprite& sprite, bool& isL){

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        v2f.x = pS * g;
        isL = false;
    }
}
