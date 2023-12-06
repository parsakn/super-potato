#ifndef BOMBERMAN_V5_ENEMY_H
#define BOMBERMAN_V5_ENEMY_H

#include <SFML/Graphics.hpp>
#include "iostream"
#include "Manual.h"
#include "string"
#include "vector"

class Enemy {
private:
    sf::Sprite sprite;
    sf::Texture upTexture;
    sf::Texture downTexture;
    sf::Texture rightTexture;
    sf::Texture leftTexture;

    float movementSpeed;
    std::string movementDirection;

    char type;


    void initVariables();
    void initTexture();
    void initSprite();

public:

    Enemy(char etype);
    virtual ~Enemy();



    const sf::FloatRect getBounds() const;
    sf::Sprite getsprite();
    std::string getDirection();



    void setPosition(const float x, const float y);
    void setScale(const float xScale,const float yScale);
    void changeDirection(const std::string& direction);


    void move(const float dirX, const float dirY);
    void update();
    void render(sf::RenderTarget& target);

};


#endif //BOMBERMAN_V5_ENEMY_H
