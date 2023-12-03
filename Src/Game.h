#ifndef BOMBERMAN_V5_GAME_H
#define BOMBERMAN_V5_GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Manual.h"
#include "vector"
#include "Bomberman.h"
#include "Wall.h"



class Game {
private:
    //Window
    sf::RenderWindow* window;

    //Background
    sf::Texture grassTexture;
    sf::Sprite grassSprite;

    //Map
    std::vector<std::vector<char>> map;


    //Walls
    std::vector<Wall*> walls;

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
    void initWalls();
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
    void updateBoundsCollision();
    void render();
    void renderGrass();
    void readmap();


};


#endif //BOMBERMAN_V5_GAME_H
