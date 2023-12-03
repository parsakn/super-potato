#ifndef BOMBERMAN_V5_GAME_H
#define BOMBERMAN_V5_GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Manual.h"
#include "vector"
#include "Bomberman.h"



class Game {
private:
    //Window
    sf::RenderWindow* window;

    //Background
    sf::Texture grassTexture;
    sf::Sprite grassSprite;

    //Map
    std::vector<std::vector<char>> map;

    //Map Specifications
    int numBlocksX;
    int numBlockY;
    int blockSize;


    //BomberMan
    Bomberman* bomberMan;

    //Private Functions
    void initWindow();
    void initGrassTexture();
    void initGrassSprite();
    void initVariables();
    void initPlayer();
    void initMapSpecifications();


    //Variables
    int bombMaxCount;





public:

    Game();
    ~Game();

    //Functions
    void updatePollEvents();
    void run();
    void update();
    void updateInput();
    void render();
    void renderGrass();
    void readmap();


};


#endif //BOMBERMAN_V5_GAME_H
