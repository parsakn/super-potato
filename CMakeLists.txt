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
        Src/Bomberman.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(C:/Project3/SFML/include/SFML)

target_link_libraries(BomberMan_V5
        sfml-graphics
        sfml-window
        sfml-system
)