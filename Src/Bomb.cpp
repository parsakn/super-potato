#include "Bomb.h"

void Bomb::update() {
    elapsedSeconds = timer.getElapsedTime().asSeconds();
}

sf::FloatRect Bomb::getBounds()  {
    return this->bombSprite.getGlobalBounds();
}

void Bomb::setPosition(const float x, const float y) {
    this->bombSprite.setPosition(x, y);
}

void Bomb::setScale(const float xScale, const float yScale) {
    this->bombSprite.setScale(xScale,yScale);
}

void Bomb::initSprite() {
    this->bombSprite.setTexture(this->bombTexture);
}

void Bomb::initTexture() {
    if (!this->bombTexture.loadFromFile(BOMB_TEXT))
    {
        std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load BOMBTEXTURE file." << "\n";
    }
}

Bomb::Bomb() {
    initTexture();
    initSprite();
    this->elapsedSeconds = 0;
}

void Bomb::render(sf::RenderTarget &target) {
    target.draw(this->bombSprite);
}
