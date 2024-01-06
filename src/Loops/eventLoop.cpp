#include "mainLoopClass.h"
player plr(1);
void mainLoop::eventLoop(sf::RenderWindow& window, sf::Event event){

        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed) window.close();
            if(event.type == sf::Event::KeyPressed){
                        if(event.key.code == sf::Keyboard::Delete) window.close();
            }
            if(event.type == sf::Event::KeyReleased){
                        if(event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) plr.xAxisReleaseDetection(plr.playerVelocity);
                        if(event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) plr.xAxisReleaseDetection(plr.playerVelocity);
            }
        }
}
