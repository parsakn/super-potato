
#include "Door.h"

void Door::initSprite() {
    this->Sprite.setTexture(this->Texture);
}

void Door::initTexture() {
    if (!this->Texture.loadFromFile(DOOR_TEXT))
    {
        std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load DOOR_TEXT file." << "\n";
    }
}

void Door::setPosition(const float x, const float y) {
    this->Sprite.setPosition(x, y);
}

void Door::setScale(const float xScale, const float yScale) {
    this->Sprite.setScale(xScale,yScale);
}

sf::Sprite Door::getsprite() {
    return this->Sprite;
}

sf::FloatRect Door::getBounds() {
    return this->Sprite.getGlobalBounds();
}

void Door::render(sf::RenderTarget &target) {
    target.draw(this->Sprite);
}

Door::Door() {
    initTexture();
    initSprite();
}
