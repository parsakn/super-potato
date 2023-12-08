#include "Enemy.h"

Enemy::Enemy(char etype) {
    this->type = etype;
    initTexture();
    initVariables();
    initSprite();
}

const sf::FloatRect Enemy::getBounds() const {
    return this->sprite.getGlobalBounds();
}

void Enemy::setPosition(const float x, const float y) {
    this->sprite.setPosition(x, y);
}

void Enemy::setScale(const float xScale, const float yScale) {
    this->sprite.setScale(xScale,yScale);
}

void Enemy::changeDirection(const std::string &direction) {
    if (direction == RIGHT){
        this->sprite.setTexture(this->rightTexture);
        movementDirection = direction;
    }
    if (direction == LEFT){
        this->sprite.setTexture(this->leftTexture);
        movementDirection = direction;
    }
    if (direction == UP){
        this->sprite.setTexture(this->upTexture);
        movementDirection = direction;
    }
    if (direction == DOWN){
        this->sprite.setTexture(this->downTexture);
        movementDirection = direction;
    }
}

void Enemy::move(const float dirX, const float dirY) {
    this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

void Enemy::update() {
    if (movementDirection == UP){
        move(0.f,-1.f);
    } else if(movementDirection == DOWN){
        move(0.f,1.f);
    } else if(movementDirection == RIGHT){
        move(1.f,0.f);
    } else if (movementDirection == LEFT){
        move(-1.f,0.f);
    }
}

void Enemy::render(sf::RenderTarget &target) {
    target.draw(this->sprite);
}

std::string Enemy::getDirection() {
    return this->movementDirection;
}

Enemy::~Enemy() {

}

void Enemy::initVariables() {
    this->movementSpeed = 0.5f;
    std::srand(time(0));
    int luckyDirection = rand()%2 ;
    if (this->type == VTYPEENEMY){
        if (luckyDirection == 0){
            this->movementDirection = RIGHT;
        } else{
            this->movementDirection = LEFT;
        }
    }
    if (this->type == HTYPEENEMY){
        if (luckyDirection == 0){
            this->movementDirection = UP;
        } else{
            this->movementDirection = DOWN;
        }
    }
}

void Enemy::initTexture() {
    if (!this->upTexture.loadFromFile(ENEMY_UP_TEXT))
    {
        std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load uptexture file." << "\n";
    }
    if (!this->downTexture.loadFromFile(ENEMY_DOWN_TEXT))
    {
        std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load downtexture file." << "\n";
    }
    if (!this->rightTexture.loadFromFile(ENEMY_RIGHT_TEXT))
    {
        std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load righttexture file." << "\n";
    }
    if (!this->leftTexture.loadFromFile(ENEMY_LEFT_TEXT))
    {
        std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load lefttexture file." << "\n";
    }

}

void Enemy::initSprite() {
    if (movementDirection == UP){
        this->sprite.setTexture(upTexture);
    } else if(movementDirection == DOWN){
        this->sprite.setTexture(downTexture);
    } else if(movementDirection == RIGHT){
        this->sprite.setTexture(rightTexture);
    } else if (movementDirection == LEFT){
        this->sprite.setTexture(leftTexture);
    }
}

sf::Sprite Enemy::getsprite() {
    return this->sprite;
}
