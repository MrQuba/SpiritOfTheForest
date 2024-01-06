#include <SFML/Graphics.hpp>
#include "../Entities/Player/playerClass.h"
#include "Draw/Background/backgroundClass.h"
#include <iostream>
#include "../Entities/Enemy/enemyClass.h"
#include <SFML/Audio.hpp>
class mainLoop{
public:
    mainLoop (bool mL){
        music01.openFromFile("ost/music01.ogg");
        music01.setLoop(true);

        playerWon = false;
        playerLost = false;

        winTexture.loadFromFile("txt/Text/YouWin.png");
        winSprite.setTexture(winTexture);
        loseTexture.loadFromFile("txt/Text/YouLose.png");
        loseSprite.setTexture(loseTexture);
        quitTexture.loadFromFile("txt/Text/quit.png");
        quitSprite.setTexture(quitTexture);
        continueTexture.loadFromFile("txt/Text/continue.png");
        continueSprite.setTexture(continueTexture);
        titleTexture.loadFromFile("txt/Text/title.png");
        titleSprite.setTexture(titleTexture);

        gameStarted = false;
    }
    void gameLoop(sf::RenderWindow& window);
private:
    void eventLoop(sf::RenderWindow& window, sf::Event event);
    sf::Event inputEvent;
    sf::Music music01;

    bool playerWon;
    bool playerLost;

    bool gameStarted;

    sf::Texture winTexture;
    sf::Sprite winSprite;
    sf::Texture loseTexture;
    sf::Sprite loseSprite;
    sf::Texture quitTexture;
    sf::Sprite quitSprite;
    sf::Texture continueTexture;
    sf::Sprite continueSprite;
    sf::Texture titleTexture;
    sf::Sprite titleSprite;

    int continueTextFrames;
};
