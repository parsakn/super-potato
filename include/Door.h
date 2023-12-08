
#ifndef BOMBERMAN_V5_DOOR_H
#define BOMBERMAN_V5_DOOR_H

#include "Key.h"


class Door{
public:
    Door();


    void render(sf::RenderTarget& target);


    sf::FloatRect getBounds() ;
    sf::Sprite getsprite();


    void setPosition(const float x, const float y);
    void setScale(const float xScale,const float yScale);

private:
    void initTexture();
    void initSprite();


    sf::Sprite Sprite;
    sf::Texture Texture;






};


#endif //BOMBERMAN_V5_DOOR_H
