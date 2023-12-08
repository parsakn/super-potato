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
#include "Statusbar.h"
#include "PoweUps.h"
#include <random>
#include <algorithm>
#include <iterator>
#include <unordered_set>

class Game {
private:

    sf::RenderWindow* window;


    sf::Texture grassTexture;
    sf::Sprite grassSprite;


    std::vector<std::vector<char>> map;



    std::vector<Wall*> walls;


    int numBlocksX;
    int numBlockY;
    int blockSize;


    Statusbar* statusbar;


    std::vector<Enemy*> enemies;


    std::vector<Bomb*> bombs;


    std::vector<Key*> keys;


    std::vector<PoweUps*> powerUps;


    Bomberman* bomberMan;


    Door* door;


    void initWindow();
    void initDoor();
    void initGrassTexture();
    void initGrassSprite();
    void initVariables();
    void initPlayer();
    void initEnemies();
    void initWalls();
    void initKeys();
    void initPowerUps();
    void initStatusBar();
    void initEndGameStatus();
    void initMapSpecifications();
    void initEndGameTexts();




    int keyCollected;
    std::vector<int> randomWallsB;


    sf::Font font;
    bool wonGame;
    bool LoseGame;
    bool isReachedDoor;


    sf::RectangleShape endGameStatus;
    sf::Text wonGameMessage;
    sf::Text loseGameMessage;





public:

    Game();
    ~Game();


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
    void updatePowerUps();
    void updateDoor();
    void updatelapsedseconds();
    void updateGameStatus();
    void updatestatusbar();
    void wallExplosion(std::vector<sf::Vector2f> positions);
    void bombermanExplosion(std::vector<sf::Vector2f> positions);
    void enemyExplosion(std::vector<sf::Vector2f> positions);
    void fixWallCollosion();
    void render();
    void renderGrass();
    void readmap();
    std::vector<int> getRandomWalls();
    sf::Vector2f calcBombPos();
    std::vector<sf::Vector2f> FindExplodedBlocks(sf::Vector2f bomb);

    sf::Clock timer;
    float elapsedSeconds;

};


#endif //BOMBERMAN_V5_GAME_H
