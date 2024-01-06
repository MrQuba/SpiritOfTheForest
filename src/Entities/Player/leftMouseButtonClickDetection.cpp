#include "playerClass.h"

void player::leftMouseButtonClickDetection(bool& isA, bool& aFL){
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && isA){
        isArrowAvalible = false;

        if(facesLeft) aFL = true;
        if(!facesLeft) aFL = false;

    }
}
