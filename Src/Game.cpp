#include "Game.h"
#include "vector"


void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight)
                , "BomberMan-Game"
                , sf::Style::Close | sf::Style::Titlebar);

    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);
}

void Game::initGrassTexture() {

    if (!this->grassTexture.loadFromFile(GRASS_TEXT))
    {
        std::cout << "ERROR::GAME::COULD NOT LOAD GRASS TEXTURE" << "\n";
    }

}

void Game::initGrassSprite() {

    this->grassSprite.setTexture(this->grassTexture);

    float blockSize_f;
    blockSize_f = static_cast<float>(this->blockSize);
    float grassSizeX = grassTexture.getSize().x;
    float grassSizeY = grassTexture.getSize().y;
    this->grassSprite.setScale((blockSize_f / grassSizeX) , (blockSize_f / grassSizeY));

}

void Game::initPlayer() {
    this->bomberMan = new Bomberman();

    float blockSize_f;
    blockSize_f = static_cast<float>(this->blockSize);
    float grassSizeX = grassTexture.getSize().x;
    float grassSizeY = grassTexture.getSize().y;

    bomberMan->setScale((blockSize_f / grassSizeX) , (blockSize_f / grassSizeY));
}

void Game::initVariables() {
    this->bombMaxCount = MAX_BOMBS;
}

void Game::run() {

    while (this->window->isOpen())
    {
        this->updatePollEvents();
        this->update();
        this->render();
    }
}

void Game::update() {
    this->updateInput();
    this->updateBoundsCollision();
    this->fixWallCollosion();
    for (int j = 0; j < bombs.size(); ++j) {
        bombs[j]->update();
    }
    tickTokExplode();

}

void Game::renderGrass() {

    for (int x = 0; x < numBlocksX; x++)
    {
        for (int y = 0; y < numBlockY; y++)
        {
            grassSprite.setPosition(static_cast<float>(x * blockSize), static_cast<float>(y * blockSize));
            this->window->draw(this->grassSprite);
        }
    }

}

void Game::render() {

    this->window->clear();

    this->renderGrass();

    for (int i = 0; i < walls.size(); ++i) {
        walls[i]->render(*this->window);
    }

    for (int j = 0; j < bombs.size(); ++j) {
        bombs[j]->render(*this->window);
    }

    this->bomberMan->render(*this->window);

    this->window->display();

}

void Game::readmap() {

        std::ifstream file(MAP_TXTFILE_ADDRESS);

        if (!file.is_open()) {
            std::cerr << "Error opening map file: " << MAP_TXTFILE_ADDRESS << std::endl;


        } else {

            std::string line;

            while (std::getline(file, line)) {

                std::vector<char> row(line.begin(), line.end());

                map.push_back(row);
            }

            file.close();
        }
}

Game::Game() {

    this->initWindow();
    this->readmap();
    this->initMapSpecifications();
    this->initVariables();
    this->initGrassTexture();
    this->initGrassSprite();
    this->initPlayer();
    this->initWalls();

}

Game::~Game() {
    delete this->window;
    delete this->bomberMan;
}

void Game::updatePollEvents() {
    sf::Event e;
    while (this->window->pollEvent(e))
    {
        if (e.Event::type == sf::Event::Closed)
            this->window->close();
        if (e.Event::key.code == sf::Keyboard::Escape)
            this->window->close();
    }
}

void Game::initMapSpecifications() {
    this->numBlocksX = static_cast<int> (map.size());
    this->numBlockY = static_cast<int> (map.size());
    blockSize = windowWidth / numBlocksX;
}

void Game::updateInput() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        this->bomberMan->changeDirection("Left");
        this->bomberMan->move(-1.f, 0.f);
        this->fixWallCollosion();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        this->bomberMan->changeDirection("Right");
        this->bomberMan->move(1.f, 0.f);
        this->fixWallCollosion();

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up )) {
        this->bomberMan->changeDirection("Up");
        this->bomberMan->move(0.f, -1.f);
        this->fixWallCollosion();

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        this->bomberMan->changeDirection("Down");
        this->bomberMan->move(0.f, 1.f);
        this->fixWallCollosion();

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)){
        this->bombing();
    }

}

void Game::initWalls() {

    float blockSize_f;
    blockSize_f = static_cast<float>(this->blockSize);
    float grassSizeX = grassTexture.getSize().x;
    float grassSizeY = grassTexture.getSize().y;




    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[i].size(); ++j) {
            if (map[i][j] == 'P'){
                this->walls.push_back(new Wall('P'));
                walls[walls.size() - 1]->setPosition(j * blockSize,i * blockSize);
                walls[walls.size() - 1]->setScale((blockSize_f / grassSizeX) , (blockSize_f / grassSizeY));
            }
            if (map[i][j] == 'B'){
                this->walls.push_back(new Wall('B'));
                walls[walls.size() - 1]->setPosition(j * blockSize,i * blockSize);
                walls[walls.size() - 1]->setScale((blockSize_f / grassSizeX) , (blockSize_f / grassSizeY));
            }
        }
    }
}

void Game::updateBoundsCollision() {

    if (this->bomberMan->getBounds().left < 0.f)
    {
        this->bomberMan->setPosition(0.f, this->bomberMan->getBounds().top);
    }

    else if (this->bomberMan->getBounds().left + this->bomberMan->getBounds().width >= this->window->getSize().x)
    {
        this->bomberMan->setPosition(this->window->getSize().x - this->bomberMan->getBounds().width, this->bomberMan->getBounds().top);
    }


    if (this->bomberMan->getBounds().top < 0.f)
    {
        this->bomberMan->setPosition(this->bomberMan->getBounds().left, 0.f);
    }

    else if (this->bomberMan->getBounds().top + this->bomberMan->getBounds().height >= this->window->getSize().y)
    {
        this->bomberMan->setPosition(this->bomberMan->getBounds().left, this->window->getSize().y - this->bomberMan->getBounds().height);
    }
}

void Game::fixWallCollosion() {


    for (int i = 0; i < walls.size(); ++i) {
        sf::FloatRect wall = this->walls[i]->getBounds();
        sf::FloatRect player = this->bomberMan->getBounds();
        std::string direction = this->bomberMan->getDirection();
        if(abs(wall.top - player.top) >= wall.width || abs(wall.left - player.left) >= wall.width)
            continue;
        if (direction == "Up" || direction == "Down") {
                    float new_y = player.top + (wall.width - abs(player.top - wall.top)) *
                                               ((player.top - wall.top) / abs(player.top - wall.top));
                    this->bomberMan->setPosition((player.left), (new_y));

        }
        else if (direction == "Right" || direction == "Left") {
                    float new_x = player.left + (wall.width - abs(player.left - wall.left)) *
                                                ((player.left - wall.left) / abs(player.left - wall.left));
                    this->bomberMan->setPosition((new_x), (player.top));
        }
    }
}

void Game::bombing() {
    sf::Vector2f bombPos = calcBombPos();
    bool canBomb = false;
    if (bombs.size() < 3){canBomb = true ; }
    for (auto & bomb : bombs) {
        if (bombPos.x == bomb->getBounds().left && bombPos.y == bomb->getBounds().top){
            canBomb = false;
        }
    }
    if(canBomb){
        bombs.push_back(new Bomb());


        float blockSize_f;
        blockSize_f = static_cast<float>(this->blockSize);
        float grassSizeX = grassTexture.getSize().x;
        float grassSizeY = grassTexture.getSize().y;

        this->bombs[bombs.size() - 1 ]->setScale((blockSize_f / grassSizeX) , (blockSize_f / grassSizeY));
        this->bombs[bombs.size() - 1]->setPosition(bombPos.x,bombPos.y);
    }


}

sf::Vector2f Game::calcBombPos() {
    float new_X =  bomberMan->getBounds().left + ((blockSize)/2);
    float new_Y = bomberMan->getBounds().top + ((blockSize)/2);
    float bombpositionx = new_X - ( static_cast<int>(new_X) % static_cast<int>(blockSize) );
    float bombpositiony = new_Y - ( static_cast<int>(new_Y) % static_cast<int>(blockSize) );

    return {bombpositionx,bombpositiony};
}

void Game::tickTokExplode() {

    for (int i = 0; i < bombs.size(); ++i) {
        bombs[i]->update();
        if (bombs[i]->elapsedSeconds >= 2) {
            delete bombs[i];
            bombs.erase(bombs.begin() + i);
        }
    }
}














