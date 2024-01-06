#include "playerClass.h"

void player::spacePressDetection(bool& isJ, sf::Vector2f& v2f, float jH, float g, bool& dJ, int& jC){
    if(!dJ){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isJ){

        isJ = true;
        v2f.y = -sqrt(5 * g * jH);
    }
    }
    else if(dJ){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && jC <= 2){

        jC++;
        v2f.y = -sqrt(5 * g * jH);
    }
    }

}
