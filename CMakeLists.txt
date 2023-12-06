cmake_minimum_required(VERSION 3.26)
project(BomberMan_V5)

set(CMAKE_CXX_STANDARD 20)

add_executable(BomberMan_V5 Src/main.cpp
        Src/Wall.h
        Src/Wall.cpp
        Src/Game.cpp
        Src/Game.h
        Src/Manual.h
        Src/Bomberman.cpp
        Src/Bomberman.h
        Src/Bomb.cpp
        Src/Bomb.h
        Src/Key.cpp
        Src/Key.h
        Src/Enemy.cpp
        Src/Enemy.h
        Src/Door.cpp
        Src/Door.h
        Src/Statusbar.cpp
        Src/Statusbar.h
)



target_link_libraries(BomberMan_V5
        sfml-graphics
        sfml-window
        sfml-system
)