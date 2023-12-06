#include "Statusbar.h"

void Statusbar::updateCountdownText(float remainingTime) {
    int minutes = static_cast<int>(remainingTime) / 60;
    int seconds = static_cast<int>(remainingTime) % 60;

    countdownText.setString("Time: " + std::to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + std::to_string(seconds));
}


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
    target.draw(this->countdownText);
    target.draw(lifeLine);
    if (keys == 1){
     keySprite.setPosition(INITIAL_KEYICON_X, INITIAL_KEYICON_Y);
     target.draw(keySprite);
    } else if(keys == 2){
        keySprite.setPosition(INITIAL_KEYICON_X, INITIAL_KEYICON_Y);
        target.draw(keySprite);
        keySprite.setPosition(INITIAL_KEYICON_X+ keySprite.getGlobalBounds().width , INITIAL_KEYICON_Y);
        target.draw(keySprite);
    } else if(keys == 3){
        keySprite.setPosition(INITIAL_KEYICON_X, INITIAL_KEYICON_Y);
        target.draw(keySprite);
        keySprite.setPosition(INITIAL_KEYICON_X+ keySprite.getGlobalBounds().width , INITIAL_KEYICON_Y);
        target.draw(keySprite);
        keySprite.setPosition(INITIAL_KEYICON_X+ 2*keySprite.getGlobalBounds().width , INITIAL_KEYICON_Y);
        target.draw(keySprite);
    }
}

Statusbar::Statusbar() {
    initTexture();
    initSprite();
    initText();
    initKeyTexture();
    initKeySprite();
    initLifeLine();
    setPosition();
    setScale();

}

void Statusbar::initText() {
    if (!font.loadFromFile(FONT_TTF)) {
        std::cerr << "Font loading failed!" << std::endl;
    }

    countdownText.setFont(font);
    countdownText.setCharacterSize(20);
    countdownText.setFillColor(sf::Color::White);
    countdownText.setPosition(10 , windowHeight + 3);
}

void Statusbar::setLives(int livescount) {
    this->lives = livescount;
}

void Statusbar::initLifeLine() {
    lifeLine.setSize(sf::Vector2f(LIFELINE_XSIZE, LIFELINE_YSIZE));
    lifeLine.setFillColor(sf::Color::Red);
    lifeLine.setOutlineThickness(1.f);
    lifeLine.setOutlineColor(sf::Color::White);
    lifeLine.setPosition(LIFELINEINITIALXPOS, LIFELINEINITIALYPOS);
}

void Statusbar::updateLivesBar() {

    float newWidth = LIFELINE_XSIZE * static_cast<float>(lives) / MAX_LIVES;

    lifeLine.setSize(sf::Vector2f(newWidth, LIFELINE_YSIZE));
}

void Statusbar::initKeyTexture() {
    if (!this->keyTexture.loadFromFile(KEY_1_TXT))
    {
        std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load keyTexture1 file." << "\n";
    }

}

void Statusbar::initKeySprite() {
    this->keySprite.setTexture(this->keyTexture);
    this->keySprite.setScale(0.5,0.5);
}

void Statusbar::setkeys(int keyscount) {
    this->keys = keyscount;
}

