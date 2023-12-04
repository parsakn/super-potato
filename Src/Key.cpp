#include "Key.h"

void Key::initTexture() {
    if (!this->keyTexture1.loadFromFile(KEY_1_TXT))
    {
        std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load keyTexture1 file." << "\n";
    }
    if (!this->keyTexture2.loadFromFile(KEY_2_TXT))
    {
        std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load keyTexture2 file." << "\n";
    }
    if (!this->keyTexture3.loadFromFile(KEY_3_TXT))
    {
        std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load keyTexture3 file." << "\n";
    }
}

void Key::initSprite() {
    if (this->keyNumber == 1){
        this->keySprite.setTexture(this->keyTexture1);
    }
    if (this->keyNumber == 2){
        this->keySprite.setTexture(this->keyTexture2);
    }
    if (this->keyNumber == 3){
        this->keySprite.setTexture(this->keyTexture3);
    }


}

void Key::setScale(const float xScale, const float yScale) {
    this->keySprite.setScale(xScale,yScale);
}

void Key::setPosition(const float x, const float y) {
    this->keySprite.setPosition(x, y);
}

sf::FloatRect Key::getBounds() {
    return this->keySprite.getGlobalBounds();
}

void Key::render(sf::RenderTarget &target) {
    target.draw(this->keySprite);
}

Key::Key(int type) {
    this->keyNumber = type;
    initTexture();
    initSprite();
}

sf::Sprite Key::getsprite() {
    return this->keySprite;
}
