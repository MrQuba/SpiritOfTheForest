#include <SFML/Graphics.hpp>
#include <iostream>
class window{
public:

window (bool w){
windowTitle = "Game";
gameWindow.create(sf::VideoMode(192, 108), windowTitle, sf::Style::Fullscreen);
gameWindow.setFramerateLimit(60);
}

sf::RenderWindow gameWindow;
std::string windowTitle;

};
