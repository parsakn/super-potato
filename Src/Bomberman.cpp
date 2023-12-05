#include "Bomberman.h"

void Bomberman::initVariables() {
    this->isLosingLife = false;
    this->losingLiveCoolDown = 0;
    this->isHide=false;
    this->lives = MAX_LIVES;
    this->movementSpeed = 2.0f;
}

void Bomberman::initTexture() {

    if (!this->upTexture.loadFromFile(BMAN_UP_TEXT))
    {
        std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load uptexture file." << "\n";
    }
    if (!this->downTexture.loadFromFile(BMAN_DOWN_TEXT))
    {
        std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load downtexture file." << "\n";
    }
    if (!this->rightTexture.loadFromFile(BMAN_RIGHT_TEXT))
    {
        std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load righttexture file." << "\n";
    }
    if (!this->leftTexture.loadFromFile(BMAN_LEFT_TXT))
    {
        std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load lefttexture file." << "\n";
    }

}

void Bomberman::initSprite() {

    this->sprite.setTexture(this->downTexture);

}

Bomberman::Bomberman() {

    this->initVariables();
    this->initTexture();
    this->initSprite();
}

Bomberman::~Bomberman() {

}

void Bomberman::render(sf::RenderTarget &target) {
    target.draw(this->sprite);
}

void Bomberman::move(const float dirX, const float dirY) {
    this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

void Bomberman::setPosition(const float x, const float y) {
    this->sprite.setPosition(x, y);
}

void Bomberman::setScale(const float xScale, const float yScale) {
    this->sprite.setScale(xScale,yScale);
}

void Bomberman::changeDirection(const std::string& direction) {

    if (direction == "Right"){
        this->sprite.setTexture(this->rightTexture);
        movementDirection = direction;
    }
    if (direction == "Left"){
        this->sprite.setTexture(this->leftTexture);
        movementDirection = direction;
    }
    if (direction == "Up"){
        this->sprite.setTexture(this->upTexture);
        movementDirection = direction;
    }
    if (direction == "Down"){
        this->sprite.setTexture(this->downTexture);
        movementDirection = direction;
    }
}

const sf::FloatRect Bomberman::getBounds() const {
    return this->sprite.getGlobalBounds();
}

std::string Bomberman::getDirection() {
    return this->movementDirection;
}

void Bomberman::loseLife() {
    if(this->canLoseLife()) {
        this->lives = this->lives - 1;
        isLosingLife = true;
    }
}

int Bomberman::getLivesRemain() {
    return this->lives;
}



bool Bomberman::canLoseLife() {
    if(this->isLosingLife)
        return false;
    else
        return true;
}

void Bomberman::update() {
   if(this->isLosingLife)
       this->respawning();

}

void Bomberman::respawning() {
    this->losingLiveCoolDown = (this->losingLiveCoolDown + 1);
    if(this->losingLiveCoolDown >= MAX_LOSING_LIFE_COOLDOWN) {
        this->losingLiveCoolDown=0;
        this->isLosingLife = false;
        this->isHide=false;
    }
    else {
        if ((this->losingLiveCoolDown / (MAX_LOSING_LIFE_COOLDOWN/BLINK_RATE))%2 == 0 )
            this->isHide = true;
        if ((this->losingLiveCoolDown / (MAX_LOSING_LIFE_COOLDOWN/BLINK_RATE))%2 == 1 )
            this->isHide = false;
    }
}

bool Bomberman::getIsHide() {
    return this->isHide;
}



