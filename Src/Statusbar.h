#ifndef BOMBERMAN_V5_STATUSBAR_H
#define BOMBERMAN_V5_STATUSBAR_H

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include "iostream"
#include "Manual.h"
#include "string"
#include "vector"



class Statusbar {
public:
    Statusbar();


    void render(sf::RenderTarget& target);


    void updateCountdownText(float remainingTime);
    void updateLivesBar();



    void setPosition();
    void setScale();
    void setLives(int livescount);
    void setkeys(int keyscount);
private:
    void initTexture();
    void initSprite();
    void initLifeLine();
    void initText();
    void initKeyTexture();
    void initKeySprite();


    sf::Sprite Sprite;
    sf::Texture Texture;
    sf::Font font;
    sf::RectangleShape lifeLine;

    sf::Sprite keySprite;
    sf::Texture keyTexture;

    sf::Text countdownText;
    int lives;
    int keys;




};


#endif //BOMBERMAN_V5_STATUSBAR_H
