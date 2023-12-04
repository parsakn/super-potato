#ifndef BOMBERMAN_V5_KEY_H
#define BOMBERMAN_V5_KEY_H

#include <SFML/Graphics.hpp>
#include "iostream"
#include "Manual.h"
#include "string"
#include "vector"

class Key {
public:
    Key(int type);


    void render(sf::RenderTarget& target);

    //Accessors
    sf::FloatRect getBounds() ;

    //Modifies
    void setPosition(const float x, const float y);
    void setScale(const float xScale,const float yScale);

private:
    void initTexture();
    void initSprite();


    sf::Sprite keySprite;
    sf::Texture keyTexture1;
    sf::Texture keyTexture2;
    sf::Texture keyTexture3;
    int keyNumber;




};


#endif //BOMBERMAN_V5_KEY_H
