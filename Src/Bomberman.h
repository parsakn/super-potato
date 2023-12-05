#ifndef BOMBERMAN_V5_BOMBERMAN_H
#define BOMBERMAN_V5_BOMBERMAN_H

#include <SFML/Graphics.hpp>
#include "iostream"
#include "Manual.h"
#include "string"
#include "vector"



class Bomberman {
private:
    sf::Sprite sprite;
    sf::Texture upTexture;
    sf::Texture downTexture;
    sf::Texture rightTexture;
    sf::Texture leftTexture;

    float movementSpeed;
    std::string movementDirection;

    int lives;
    bool isLosingLife;
    bool isHide;
    int losingLiveCoolDown;


    //Private functions
    void initVariables();
    void initTexture();
    void initSprite();


public:

    Bomberman();
    virtual ~Bomberman();


    //Accessors
    const sf::FloatRect getBounds() const;
    std::string getDirection();
    int getLivesRemain();
    bool getIsHide();

    //Modifies
    void setPosition(const float x, const float y);
    void setScale(const float xScale,const float yScale);
    void changeDirection(const std::string& direction);

    //Functions
    void move(const float dirX, const float dirY);
    void update();
    void render(sf::RenderTarget& target);
    void loseLife();
    bool canLoseLife();
    void respawning();



};


#endif //BOMBERMAN_V5_BOMBERMAN_H
