#ifndef BOMBERMAN_V5_STATUSBAR_H
#define BOMBERMAN_V5_STATUSBAR_H

#include <SFML/Graphics.hpp>
#include "iostream"
#include "Manual.h"
#include "string"
#include "vector"



class Statusbar {
public:
    Statusbar();


    void render(sf::RenderTarget& target);




    //Modifies
    void setPosition();
    void setScale();

private:
    void initTexture();
    void initSprite();


    sf::Sprite Sprite;
    sf::Texture Texture;




};


#endif //BOMBERMAN_V5_STATUSBAR_H
