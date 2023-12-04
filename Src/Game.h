#ifndef BOMBERMAN_V5_GAME_H
#define BOMBERMAN_V5_GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Manual.h"
#include "vector"
#include "Bomberman.h"
#include "Wall.h"
#include "Bomb.h"

///commendxvkm

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

    //Bombs
    std::vector<Bomb*> bombs;

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
    void bombing();
    void tickTokExplode();
    void updatePollEvents();
    void run();
    void update();
    void updateInput();
    void wallExplosion(std::vector<sf::Vector2f> positions);
    void updateBoundsCollision();
    void fixWallCollosion();
    void render();
    void renderGrass();
    void readmap();

    sf::Vector2f calcBombPos();
    std::vector<sf::Vector2f> FindExplodedBlocks(sf::Vector2f bomb);

};


#endif //BOMBERMAN_V5_GAME_H
