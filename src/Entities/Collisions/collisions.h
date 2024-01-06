#include <SFML/Graphics.hpp>
#pragma once
class collisions{
public:
    bool groundCollision(sf::Sprite& sprite, sf::RenderWindow& window);
    bool borderCollision(sf::Sprite& sprite, sf::RenderWindow& window);
};
