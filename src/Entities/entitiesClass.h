#include <SFML/Graphics.hpp>
#pragma once
class entities{
public:
    entities(bool e){
    gravity = 0.098f;
    }
    float gravity;

    bool spritesIntersect(sf::Sprite& s1, sf::Sprite& s2);

        sf::Clock invincibilityClock;
        sf::Clock enemyInvincibilityClock;

protected:

};
