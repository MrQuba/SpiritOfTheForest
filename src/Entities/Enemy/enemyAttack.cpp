#include "enemyClass.h"
using  namespace std;
int enemy::enemyAttack(sf::Sprite& pSprite, sf::Sprite& eSprite, sf::Vector2f& eVelocity){
if(pSprite.getPosition().x - eSprite.getPosition().x < 0) {
        return -1;}
if(pSprite.getPosition().x - eSprite.getPosition().x > 0) {
        return 1;}


}
