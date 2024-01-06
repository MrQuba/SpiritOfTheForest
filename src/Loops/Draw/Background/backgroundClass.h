#include <SFML/Graphics.hpp>

class background{
public:
    background(bool b){
    bgTexture.loadFromFile("txt/Background/background.png");
    bgSprite.setTexture(bgTexture);
    bgSprite.setScale(16.f, 16.f);
    }
    sf::Sprite bgSprite;
private:
    sf::Texture bgTexture;
};
