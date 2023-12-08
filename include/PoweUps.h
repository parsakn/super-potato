#ifndef BOMBERMAN_V5_POWEUPS_H
#define BOMBERMAN_V5_POWEUPS_H
#include <SFML/Graphics.hpp>
#include "iostream"
#include "Manual.h"
#include "string"
#include "vector"


class PoweUps {
public:
    PoweUps(char type);


    void render(sf::RenderTarget& target);



    sf::FloatRect getBounds();
    char getType();



    void setPosition(const float x, const float y);
    void setScale(const float xScale,const float yScale);

private:
    void initTexture();
    void initSprite();

    char type;

    sf::Sprite sprite;
    sf::Texture textureLifeAid;
    sf::Texture textureSpeedUp;





};


#endif //BOMBERMAN_V5_POWEUPS_H
