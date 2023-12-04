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
#include "Key.h"

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

    //Keys
    std::vector<Key*> keys;

    //BomberMan
    Bomberman* bomberMan;

    //Private Functions
    void initWindow();
    void initGrassTexture();
    void initGrassSprite();
    void initVariables();
    void initPlayer();
    void initWalls();
    void initKeys();
    void initMapSpecifications();


    //Variables
    int bombMaxCount;
    int keyCollected=0;





public:

    Game();
    ~Game();

    //Functions
    int getKeyCollected();
    void plusKeyCollectedByOne();
    void bombing();
    void tickTokExplode();
    void updatePollEvents();
    void run();
    void update();
    void updateInput();
    void wallExplosion(std::vector<sf::Vector2f> positions);
    void bombermanExplosion(std::vector<sf::Vector2f> positions);
    void updateBoundsCollision();
    void fixWallCollosion();
    void render();
    void renderGrass();
    void readmap();
    std::vector<int> getKeysIndex();
    sf::Vector2f calcBombPos();
    void updateKey();
    std::vector<sf::Vector2f> FindExplodedBlocks(sf::Vector2f bomb);

};


#endif //BOMBERMAN_V5_GAME_H
