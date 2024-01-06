#include "enemyClass.h"

void enemy::enemyHitDetection(sf::Clock& eInvClock, int pDmg, bool enemyWasHit, sf::RectangleShape& eHR, sf::RenderWindow& window, sf::Sprite& sprite){
            if(rand() % 100 + 1 >= 90){
                this->damageTaken = 2*pDmg;
                this->enemyHealth -= 2*pDmg;}

            else {
                this->enemyHealth -= pDmg;
                this->damageTaken = pDmg; }
                if(enemyFacesLeft)
                    sprite.move(100, 0.f);
                else if(!enemyFacesLeft)
                    sprite.move(-100, 0.f);

    }
