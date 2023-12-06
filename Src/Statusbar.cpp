#include "Statusbar.h"

void Statusbar::initSprite() {
    this->Sprite.setTexture(this->Texture);
}

void Statusbar::initTexture() {
    if (!this->Texture.loadFromFile(STATUSBAR_TXT))
    {
        std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load Statusbar file." << "\n";
    }
}

void Statusbar::setScale() {
    float text_x = this->Texture.getSize().x;
    float text_y = this->Texture.getSize().y;

    this->Sprite.setScale(windowWidth / text_x ,STATUSBARHEIGHT / text_y);
}

void Statusbar::setPosition() {
    this->Sprite.setPosition(0, windowHeight);
}

void Statusbar::render(sf::RenderTarget &target) {
    target.draw(this->Sprite);
}

Statusbar::Statusbar() {
    initTexture();
    initSprite();
    setPosition();
    setScale();

}
