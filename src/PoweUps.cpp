#include "PoweUps.h"


void PoweUps::setPosition(const float x, const float y) {
    this->sprite.setPosition(x, y);
}

void PoweUps::initTexture() {
    if (!this->textureLifeAid.loadFromFile(LIFE_AID_TXT))
    {
        std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load LIFE_AID_TXT file." << "\n";
    }
    if (!this->textureSpeedUp.loadFromFile(SPEEDUP_TXT))
    {
        std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load SPEEDUP_TXT file." << "\n";
    }
}

void PoweUps::initSprite() {
    if (this->type == 'L') {
        this->sprite.setTexture(textureLifeAid);
    } else{
        this->sprite.setTexture(textureSpeedUp);
    }
}

void PoweUps::render(sf::RenderTarget &target) {
    target.draw(this->sprite);
}

sf::FloatRect PoweUps::getBounds() {
    return this->sprite.getGlobalBounds();
}

PoweUps::PoweUps(char typepowerup) {
    this->type = typepowerup;
    initTexture();
    initSprite();

}

void PoweUps::setScale(const float xScale, const float yScale) {
    this->sprite.setScale(xScale,yScale);
}



char PoweUps::getType() {
    return this->type;
}

