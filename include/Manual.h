#ifndef BOMBERMAN_V5_MANUAL_H
#define BOMBERMAN_V5_MANUAL_H

#include <string>
#include <SFML/Graphics.hpp>

const int windowWidth = 500;
const int windowHeight = 500;

const int STATUSBARHEIGHT = 35;

const std::string BMAN_UP_TEXT = "/home/parsa/CLionProjects/BomberMan_V5/Sprites/boy/up.png";
const std::string BMAN_DOWN_TEXT = "/home/parsa/CLionProjects/BomberMan_V5/Sprites/boy/down-stay.png";
const std::string BMAN_RIGHT_TEXT = "/home/parsa/CLionProjects/BomberMan_V5/Sprites/boy/right.png";
const std::string BMAN_LEFT_TXT = "/home/parsa/CLionProjects/BomberMan_V5/Sprites/boy/left.png";
const std::string GRASS_TEXT = "/home/parsa/CLionProjects/BomberMan_V5/Sprites/grass.png";
const std::string BOMB_TEXT = "/home/parsa/CLionProjects/BomberMan_V5/Sprites/bomb.png";
const std::string WALL_TYPE1_TEXT = "/home/parsa/CLionProjects/BomberMan_V5/Sprites/wall-1.png";
const std::string WALL_TYPE2_TEXT = "/home/parsa/CLionProjects/BomberMan_V5/Sprites/wall-2.png";
const std::string MAP_TXTFILE_ADDRESS = "/home/parsa/CLionProjects/BomberMan_V5/map.txt";
const std::string KEY_1_TXT = "/home/parsa/CLionProjects/BomberMan_V5/Sprites/key.png";
const std::string KEY_2_TXT = "/home/parsa/CLionProjects/BomberMan_V5/Sprites/key2.png";
const std::string KEY_3_TXT = "/home/parsa/CLionProjects/BomberMan_V5/Sprites/key3.png";
const std::string ENEMY_UP_TEXT = "/home/parsa/CLionProjects/BomberMan_V5/Sprites/girl/up.png";
const std::string ENEMY_DOWN_TEXT = "/home/parsa/CLionProjects/BomberMan_V5/Sprites/girl/down-stay.png";
const std::string ENEMY_RIGHT_TEXT = "/home/parsa/CLionProjects/BomberMan_V5/Sprites/girl/right.png";
const std::string ENEMY_LEFT_TEXT = "/home/parsa/CLionProjects/BomberMan_V5/Sprites/girl/left.png";
const std::string DOOR_TEXT = "/home/parsa/CLionProjects/BomberMan_V5/Sprites/Door.png";
const std::string STATUSBAR_TXT = "/home/parsa/CLionProjects/BomberMan_V5/Sprites/statusbar.png";
const std::string FONT_TTF = "/home/parsa/CLionProjects/BomberMan_V5/Sprites/spaceboy/SPACEBOY.TTF";
const std::string LIFE_AID_TXT = "/home/parsa/CLionProjects/BomberMan_V5/Sprites/LifeAid.png";
const std::string SPEEDUP_TXT = "/home/parsa/CLionProjects/BomberMan_V5/Sprites/speedup.png";



const int MAX_LIVES = 3;
const int MAX_BOMBS = 3;
const int MAX_LOSING_LIFE_COOLDOWN=80;

const int BLINK_RATE=16;

const int LIFELINE_XSIZE = 180;
const int LIFELINE_YSIZE = 25;
const int LIFELINEINITIALXPOS = (windowWidth / 2) - 50 ;
const int LIFELINEINITIALYPOS = windowHeight + 5;

const int INITIAL_KEYICON_X = windowWidth - 100;
const int INITIAL_KEYICON_Y = windowHeight + 5;

const int KEYS_NUMBER = 3;
const int POWERUP_NUMBERS = 2;

const std::string RIGHT = "Right" ;
const std::string UP = "Up" ;
const std::string LEFT = "Left" ;
const std::string DOWN = "Down" ;

const float GAMETIME = 120.f;
const char PTYPEWALL = 'P';
const char BTYPEWALL = 'B';
const char DOORTYPE = 'D';
const char VTYPEENEMY = 'V';
const char HTYPEENEMY = 'H';
const char LTYPEPOWERUP = 'L';
const char STYPEPOWERUP = 'S';

#endif //BOMBERMAN_V5_MANUAL_H
