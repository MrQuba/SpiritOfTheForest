#include <SFML/Graphics.hpp>
#include "../entitiesClass.h"
#include "../Movement/movementClass.h"
#include "../Collisions/collisions.h"
#include <cmath>
#include <iostream>
#include "../Enemy/enemyClass.h"
class player{

public:
    player(bool p){
        playerTexture01.loadFromFile("txt/Player/playerSprite.png", sf::IntRect(0, 0, 16, 16));
        playerTexture.loadFromFile("txt/Player/playerSprite.png", sf::IntRect(16, 0, 16, 16));
        playerTexture02.loadFromFile("txt/Player/playerSprite.png", sf::IntRect(32, 0, 16, 16));
        playerSprite.setTexture(playerTexture);
        playerSprite.scale(6.25f, 6.25f);

        jumpHeight = 125;
        playerSpeed = 75;

        doubleJump = false;
        jumpCount = 0;

        arrowTexture.loadFromFile("txt/Player/arrow.png");
        arrowSprite.setTexture(arrowTexture);
        arrowSprite.scale(2.5f, 2.5f);
        arrowSprite.rotate(90.f);

        facesLeft = false;
        arrowFacesLeft = false;

        playerHealth = 50;

        playerIsInvincible = false;

        playerWasHit = false;

        isArrowAvalible = true;

        playerDamage = 13;
        rotatedLeft = true;

        isMoving = false;
        movementAnimationFrame = 0;

playerHealthRepresentation.setFillColor(sf::Color::Red);
playerHealthRepresentation.setSize(sf::Vector2f(playerHealth * 10, 16.f));
playerHealthRepresentation.setOrigin(playerHealthRepresentation.getSize().x / 2, playerHealthRepresentation.getSize().y / 2);

maxHealth.setFillColor(sf::Color::Black);
maxHealth.setSize(sf::Vector2f(playerHealth * 10, 16.f));
maxHealth.setOrigin(maxHealth.getSize().x / 2, maxHealth.getSize().y / 2);

    }
    sf::Vector2f playerVelocity;
    bool isJumping;
    sf::Sprite playerSprite;

    bool playerUpdate(sf::Sprite& sprite, sf::RenderWindow& window, sf::Sprite& eSprite, sf::Sprite& ePSprite, sf::Sprite& pC);

    void spacePressDetection(bool& isJ, sf::Vector2f& v2f, float jH, float g, bool& dJ, int& jC);

    void rightPressDetection(sf::Vector2f& v2f, float pS, float g, sf::Sprite& sprite, bool& isL);
    void leftPressDetection(sf::Vector2f& v2f, float pS, float g, sf::Sprite& sprite, bool& isL);

    void xAxisReleaseDetection(sf::Vector2f& v2f);

    void leftMouseButtonClickDetection(bool& isA, bool& aFL);
    void arrowUpdate(sf::Sprite& aSprite, bool& isA, float g, sf::RenderWindow& window, sf::Sprite& pSprite, bool aFL);

    bool doubleJump;
    int jumpCount;

    sf::Sprite arrowSprite;
    bool isArrowAvalible;

    int playerHealth;

    bool playerIsInvincible;

    sf::Time playerInvincibilityTime;

    bool playerWasHit;

    int playerDamage;

    bool rotatedLeft;
    sf::RectangleShape playerHealthRepresentation;
    sf::RectangleShape maxHealth;
    bool facesLeft;
private:
    sf::Texture playerTexture;
    sf::Texture playerTexture01;
    sf::Texture playerTexture02;
    bool arrowFacesLeft;
    sf::Texture arrowTexture;

    bool isMoving;
    int movementAnimationFrame;
protected:

    float playerSpeed;
    float jumpSpeed;
    float jumpHeight;


};
