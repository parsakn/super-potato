
#include "Wall.h"

void Wall::setPosition(float x, float y) {
    this->sprite.setPosition(x,y);
}

Wall::Wall(char Type) {
    type = Type;
    initTexture();
    initSprite();
}

Wall::~Wall() {

}

void Wall::initTexture() {
    if (!this->typeTextureP.loadFromFile(WALL_TYPE2_TEXT))
    {
        std::cout << "ERROR::GAME::COULD NOT LOAD WALL_TYPE_2 TEXTURE" << "\n";
    }
    if (!this->typeTextureB.loadFromFile(WALL_TYPE1_TEXT))
    {
        std::cout << "ERROR::GAME::COULD NOT LOAD WALL_TYPE_1 TEXTURE" << "\n";
    }

}

void Wall::initSprite() {
    if (type == 'P'){
        sprite.setTexture(typeTextureP);
    }
    if (type == 'B'){
        sprite.setTexture(typeTextureB);
    }
}

void Wall::render(sf::RenderTarget &target) {
    target.draw(this->sprite);
}

void Wall::setScale(const float xScale, const float yScale) {
    this->sprite.setScale(xScale,yScale);
}

const sf::FloatRect Wall::getBounds() const {
    return this->sprite.getGlobalBounds();
}

