#ifndef BOMBERMAN_V5_BOMB_H
#define BOMBERMAN_V5_BOMB_H

#include <SFML/Graphics.hpp>
#include "iostream"
#include "Manual.h"
#include "string"
#include "vector"

class Bomb {
public:
    Bomb();

    void update();
    void render(sf::RenderTarget& target);

    sf::Clock timer;
    float elapsedSeconds;

    //Accessors
     sf::FloatRect getBounds() ;

    //Modifies
    void setPosition(const float x, const float y);
    void setScale(const float xScale,const float yScale);

private:
    void initTexture();
    void initSprite();


    sf::Sprite bombSprite;
    sf::Texture bombTexture;




};


#endif //BOMBERMAN_V5_BOMB_H
