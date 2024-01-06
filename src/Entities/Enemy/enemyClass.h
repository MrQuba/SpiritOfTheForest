#include <SFML/Graphics.hpp>
#include "../entitiesClass.h"
#include "../Movement/movementClass.h"
#include "../Collisions/collisions.h"
#include <iostream>
#include <cmath>
#pragma once
class enemy{
public:
    enemy (bool en){
enemyTexture.loadFromFile("txt/Enemy/enemySprite.png", sf::IntRect(16,0, 16, 16));
enemySprite.setTexture(enemyTexture);
enemySprite.setScale(15.f, 15.f);

enemyHealth = 1000;

enemyProjectileTexture.loadFromFile("txt/Enemy/projectile.png");
enemyProjectileSprite.setTexture(enemyProjectileTexture);
enemyProjectileSprite.setScale(6.f, 6.f);

isProjectileAvalible = true;

enemyWasHit = false;

enemyAttacked = false;
enemyAttackHasCooldown = false;
enemyProjectileFacesLeft = true;

enemyDashed = false;
enemyDashHasCooldown = false;

enemyHealthRepresentation.setFillColor(sf::Color::Red);
enemyHealthRepresentation.setSize(sf::Vector2f(enemyHealth, 16.f));
enemyHealthRepresentation.setOrigin(enemyHealthRepresentation.getSize().x / 2, enemyHealthRepresentation.getSize().y / 2);

maxHealth.setFillColor(sf::Color::Black);
maxHealth.setSize(sf::Vector2f(enemyHealth, 16.f));
maxHealth.setOrigin(maxHealth.getSize().x / 2, maxHealth.getSize().y / 2);
enemyFacesLeft = false;
enemyRotatedLeft = true;
pineTexture.loadFromFile("txt/Enemy/pineCone.png");
pineCone.setTexture(pineTexture);
pineCone.setScale(4.f, 4.f);

attackCooldown = 1.25;
coneCooldown = 2.5;
speedMultiplier = 1;
attackSpeedMultiplier = 1;
coneSpeedMultiplier = 1;
phase = 1;

phaseRequirement1 = this->enemyHealth / 2;
phaseRequirement2 = this->enemyHealth / 4;
phaseRequirement3 = this->enemyHealth / 8;

isEnemyMoving = false;
enemyMovementAnimationFrame = 0;

gravityMultiplier = 10;

}
    sf::Sprite enemySprite;

    bool enemyUpdate(sf::Sprite& eSprite, sf::RenderWindow& window, sf::Sprite& pSprt, sf::RenderWindow& wind, sf::Sprite& ePsprt, sf::Sprite& aSprt, int pDmg, bool isA, bool pFL);
    sf::Vector2f enemyVelocity;

    int enemyHealth;

    int enemyAttack(sf::Sprite& pSprite, sf::Sprite& eSprite, sf::Vector2f& eVelocity);
    void enemyDash(sf::Sprite& pSprite, sf::Sprite& eSprite);

    sf::Sprite enemyProjectileSprite;
    bool isProjectileAvalible;

    void enemyBrain(sf::Sprite& pSprt, sf::Sprite& eSprt, sf::Clock& attCClock, sf::Clock& coneCClock, bool pFL);

    void enemyHitDetection(sf::Clock& eInvClock, int pDmg, bool enemyWasHit, sf::RectangleShape& eHR, sf::RenderWindow& window, sf::Sprite& sprite);

    void enemyProjectileUpdate(sf::Sprite& ePSprite, bool isPA, bool ePFL, bool eA, sf::Clock& aCl, bool aC, sf::RenderWindow& window, sf::Sprite& pSprt, sf::Sprite& eSprt, sf::Sprite& pC);
    bool enemyProjectileFacesLeft;

    bool enemyAttacked;

    sf::Clock enemyAttackCooldownClock;
    bool enemyAttackHasCooldown;

    void enemyHealthBar(sf::RectangleShape& eHB, sf::RenderWindow& window);
    sf::RectangleShape enemyHealthRepresentation;
    int damageTaken;
    bool enemyWasHit;

    bool enemyRotatedLeft;
    bool enemyFacesLeft;

    sf::RectangleShape maxHealth;

    sf::Sprite pineCone;
    bool isConeAvalible;
    sf::Texture pineTexture;

    sf::Clock attackCooldownClock;
    sf::Clock coneCooldownClock;

    short phase;
    int phaseRequirement1;
    int phaseRequirement2;
    int phaseRequirement3;

    bool isEnemyMoving;
    int enemyMovementAnimationFrame;

    int gravityMultiplier;

private:
    sf::Texture enemyTexture;
    sf::Texture enemyProjectileTexture;

    bool enemyDashed;
    bool enemyDashHasCooldown;
    sf::Clock enemyDashCooldownClock;

    float coneCooldown;
    float attackCooldown;
    int speedMultiplier;

    int attackSpeedMultiplier;
    int coneSpeedMultiplier;
};
