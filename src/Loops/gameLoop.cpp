#include "mainLoopClass.h"

enemy enm(1);
background bg(1);
player p(1);
void mainLoop::gameLoop(sf::RenderWindow& window){
music01.play();
p.playerSprite.setPosition(p.playerSprite.getGlobalBounds().width, window.getSize().y);
enm.enemySprite.setPosition(window.getSize().x, window.getSize().y);
enm.enemyHealthBar(enm.enemyHealthRepresentation, window);
enm.enemyHealthRepresentation.setPosition(window.getSize().x / 2, window.getSize().y - enm.enemyHealthRepresentation.getSize().y);
enm.maxHealth.setPosition(enm.enemyHealthRepresentation.getPosition());

p.playerHealthRepresentation.setPosition(window.getSize().x - p.playerHealthRepresentation.getSize().x, 0 + p.playerHealthRepresentation.getSize().y);
p.maxHealth.setPosition(p.playerHealthRepresentation.getPosition());

                continueSprite.setScale(2.f, 2.f);
                continueSprite.setOrigin(continueSprite.getLocalBounds().width / 2, continueSprite.getLocalBounds().height / 2);
                continueSprite.setPosition(window.getSize().x / 2, window.getSize().y - continueSprite.getLocalBounds().height);
                titleSprite.setScale(4.f, 4.f);
                titleSprite.setOrigin(titleSprite.getLocalBounds().width / 2, titleSprite.getLocalBounds().height / 2);
                titleSprite.setPosition(window.getSize().x / 2, 2 * titleSprite.getLocalBounds().height);
                titleSprite.setColor(sf::Color::Red);
    while(window.isOpen()){
    if(!gameStarted){
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) gameStarted = true;
            window.clear();
            window.draw(bg.bgSprite);
            if(this->continueTextFrames <= 30){
                window.draw(continueSprite);
                this->continueTextFrames++;
            }
            else if(this->continueTextFrames <= 60){
                this->continueTextFrames++;
            }
            else if(this->continueTextFrames > 60){
                this->continueTextFrames = 0;
            }
            window.draw(titleSprite);
            window.display();

    }
    else if(gameStarted){
                window.clear();

        if(!p.playerUpdate(p.playerSprite, window, enm.enemySprite, enm.enemyProjectileSprite, enm.pineCone)){
            this->playerLost = true;
        }

        if(!enm.enemyUpdate(enm.enemySprite, window, p.playerSprite, window, enm.enemyProjectileSprite, p.arrowSprite, p.playerDamage, p.isArrowAvalible, p.facesLeft)){
            this->playerWon = true;
        }

        eventLoop(window, inputEvent);


        window.draw(bg.bgSprite);
        if(!playerWon && !playerLost){
        if(!p.isArrowAvalible) window.draw(p.arrowSprite);
        window.draw(p.playerSprite);
            window.draw(enm.enemySprite);
            if(!enm.isProjectileAvalible) window.draw(enm.enemyProjectileSprite);
            if(!enm.isConeAvalible) window.draw(enm.pineCone);
            window.draw(enm.maxHealth);
            window.draw(enm.enemyHealthRepresentation);
            window.draw(p.maxHealth);
            window.draw(p.playerHealthRepresentation);
        }
        if(playerWon && !playerLost){
                winSprite.setScale(8.f, 8.f);
                winSprite.setOrigin(winSprite.getLocalBounds().width / 2, winSprite.getLocalBounds().height / 2);
                winSprite.setPosition(window.getSize().x / 2, window.getSize().y / 2);
                quitSprite.setScale(2.f, 2.f);
                quitSprite.setOrigin(quitSprite.getLocalBounds().width / 2, quitSprite.getLocalBounds().height / 2);
                quitSprite.setPosition(window.getSize().x / 2, window.getSize().y  - quitSprite.getLocalBounds().height);
                            window.draw(quitSprite);

                           window.draw(winSprite);
        }
        if(!playerWon && playerLost){
                loseSprite.setScale(8.f, 8.f);
                loseSprite.setOrigin(loseSprite.getLocalBounds().width / 2, loseSprite.getLocalBounds().height / 2);
                loseSprite.setPosition(window.getSize().x / 2, window.getSize().y / 2);
                quitSprite.setScale(2.f, 2.f);
                quitSprite.setOrigin(quitSprite.getLocalBounds().width / 2, quitSprite.getLocalBounds().height / 2);
                quitSprite.setPosition(window.getSize().x / 2, window.getSize().y  - quitSprite.getLocalBounds().height);
                            window.draw(quitSprite);

                           window.draw(loseSprite);
        }

        window.display();

        while(playerWon){
                music01.stop();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }
        while(playerLost){
                music01.stop();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }
    }

    }
}
