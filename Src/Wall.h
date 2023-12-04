#ifndef BOMBERMAN_V5_WALL_H
#define BOMBERMAN_V5_WALL_H

#include <SFML/Graphics.hpp>
#include "iostream"
#include "Manual.h"
#include "string"
#include "vector"

class Wall {
public:
    Wall(char type);
    ~Wall();

    //Functions
    void setPosition(float x, float y);
    void setScale(const float xScale,const float yScale);
    void render(sf::RenderTarget& target);

    //Accessors
    const sf::FloatRect getBounds() const;
    char getType();


private:
    char type;
    sf::Sprite sprite;
    sf::Texture typeTextureB;
    sf::Texture typeTextureP;

    //Private Functions
    void initTexture();
    void initSprite();
};


#endif //BOMBERMAN_V5_WALL_H
