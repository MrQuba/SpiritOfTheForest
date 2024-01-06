#include "playerClass.h"

void player::leftPressDetection(sf::Vector2f& v2f, float pS, float g, sf::Sprite& sprite, bool& isL){

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        v2f.x = -pS * g;
        isL = true;
    }
}
