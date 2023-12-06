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
#include "Enemy.h"
#include "cmath"
#include "Door.h"

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

    //Enemies
    std::vector<Enemy*> enemies;

    //Bombs
    std::vector<Bomb*> bombs;

    //Keys
    std::vector<Key*> keys;

    //BomberMan
    Bomberman* bomberMan;

    //Door
    Door* door;

    //Private Functions
    void initWindow();
    void initDoor();
    void initGrassTexture();
    void initGrassSprite();
    void initVariables();
    void initPlayer();
    void initEnemies();
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
    void run();
    void update();
    void updatePollEvents();
    void updateInput();
    void updateBoundsCollision();
    void updateEnemiesBoundsCollosion();
    void updateEnemiesBomberManCollosion();
    void updateKey();
    void wallExplosion(std::vector<sf::Vector2f> positions);
    void bombermanExplosion(std::vector<sf::Vector2f> positions);
    void enemyExplosion(std::vector<sf::Vector2f> positions);
    void fixWallCollosion();
    void render();
    void renderGrass();
    void readmap();
    std::vector<int> getKeysIndex();
    sf::Vector2f calcBombPos();
    std::vector<sf::Vector2f> FindExplodedBlocks(sf::Vector2f bomb);

};


#endif //BOMBERMAN_V5_GAME_H
