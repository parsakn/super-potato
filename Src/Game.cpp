#include "Game.h"
#include "vector"


void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight + STATUSBARHEIGHT)
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

void Game::initStatusBar() {
    this->statusbar = new Statusbar;
}

void Game::initVariables() {
    this->bombMaxCount = MAX_BOMBS;
    this->keyCollected = 0;
    this->isReachedDoor = false;
    this->wonGame = false;
    this->LoseGame = false;
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

void Game::initEnemies() {

    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[i].size(); ++j) {
            if (map[i][j] == 'V'){
                this->enemies.push_back(new Enemy('H'));
                float text_x = enemies[enemies.size() - 1]->getsprite().getTexture()->getSize().x;
                float text_y = enemies[enemies.size() - 1]->getsprite().getTexture()->getSize().y;
                enemies[enemies.size() - 1]->setPosition(j * blockSize,i * blockSize);
                enemies[enemies.size() - 1]->setScale((blockSize / text_x) , (blockSize / text_y));
            }
            if (map[i][j] == 'H'){
                this->enemies.push_back(new Enemy('V'));
                float text_x = enemies[enemies.size() - 1]->getsprite().getTexture()->getSize().x;
                float text_y = enemies[enemies.size() - 1]->getsprite().getTexture()->getSize().y;
                enemies[enemies.size() - 1]->setPosition(j * blockSize,i * blockSize);
                enemies[enemies.size() - 1]->setScale((blockSize / text_x) , (blockSize / text_y));
            }
        }
    }
}

void Game::initDoor() {
    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[i].size(); ++j) {
            if (map[i][j] == 'D'){
                this->door = new Door();
                float door_x = this->door->getsprite().getTexture()->getSize().x;
                float door_y = this->door->getsprite().getTexture()->getSize().y;
                this->door->setScale( blockSize/door_x  , blockSize/door_y);
                this->door->setPosition(j*blockSize,i*blockSize);
                walls.push_back(new Wall('B'));
                walls[walls.size() - 1 ]->setPosition(j*blockSize,i*blockSize);
                float wall_x =walls[walls.size() - 1]->getsprite().getTexture()->getSize().x;
                float wall_y =walls[walls.size() - 1]->getsprite().getTexture()->getSize().y;
                walls[walls.size() - 1]->setScale(blockSize/wall_x,blockSize/wall_y);

            }
        }
    }
}

void Game::initKeys() {


    std::vector<int> randomIndexesOfBWalls = getKeysIndex();

    keys.push_back(new Key(1));
    keys.push_back(new Key(2));
    keys.push_back(new Key(3));

    for (int i = 0; i < keys.size(); ++i) {
        float text_x = keys[i]->getsprite().getTexture()->getSize().x;
        float text_y = keys[i]->getsprite().getTexture()->getSize().y;
        keys[i]->setScale((blockSize / text_x) , (blockSize / text_y));
        sf::FloatRect wallbounds = walls[randomIndexesOfBWalls[i]]->getBounds();
        float wall_x = wallbounds.left;
        float wall_y = wallbounds.top;
        keys[i]->setPosition(wall_x,wall_y);
    }
}

void Game::initMapSpecifications() {
    this->numBlocksX = static_cast<int> (map.size());
    this->numBlockY = static_cast<int> (map.size());
    blockSize = windowWidth / numBlocksX;
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
    if (!wonGame && !LoseGame) {
        this->updateInput();
        this->updateBoundsCollision();
        this->updateEnemiesBomberManCollosion();
        this->updateEnemiesBoundsCollosion();
        this->fixWallCollosion();
        this->bomberMan->update();
        for (int j = 0; j < bombs.size(); ++j) {
            bombs[j]->update();
        }
        for (int t = 0; t < enemies.size(); ++t) {
            enemies[t]->update();
        }
        this->updateKey();
        this->updateDoor();
        this->tickTokExplode();
        this->updatelapsedseconds();
        this->updatestatusbar();
        this->updateGameStatus();
    }

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

    if (!wonGame && !LoseGame) {
        this->window->clear();

        this->renderGrass();

        if (!isReachedDoor)
            this->door->render(*this->window);

        for (int t = 0; t < keys.size(); ++t) {
            keys[t]->render(*this->window);
        }

        for (int i = 0; i < walls.size(); ++i) {
            walls[i]->render(*this->window);
        }

        for (int j = 0; j < bombs.size(); ++j) {
            bombs[j]->render(*this->window);
        }

        for (int x = 0; x < enemies.size(); ++x) {
            enemies[x]->render(*this->window);
        }

        if (!this->bomberMan->getIsHide())
            this->bomberMan->render(*this->window);

        this->statusbar->render(*this->window);

        this->window->display();
    }
    if (wonGame || LoseGame){
        this->window->clear();
        //this->window->draw(endGameStatus);
        if (wonGame){
            this->window->draw(this->wonGameMessage);
        } else{
            this->window->draw(this->loseGameMessage);
        }
        this->window->display();
    }

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
    this->initEnemies();
    this->initKeys();
    this->initDoor();
    this->initStatusBar();
    this->initEndGameStatus();
    this->initEndGameTexts();


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

void Game::updateBoundsCollision() {

    if (this->bomberMan->getBounds().left < 0.f)
    {
        this->bomberMan->setPosition(0.f, this->bomberMan->getBounds().top);
    }

    else if (this->bomberMan->getBounds().left + this->bomberMan->getBounds().width >= windowWidth)
    {
        this->bomberMan->setPosition(this->window->getSize().x - this->bomberMan->getBounds().width, this->bomberMan->getBounds().top);
    }


    if (this->bomberMan->getBounds().top < 0.f)
    {
        this->bomberMan->setPosition(this->bomberMan->getBounds().left, 0.f);
    }

    else if (this->bomberMan->getBounds().top + this->bomberMan->getBounds().height >= windowHeight)
    {
        this->bomberMan->setPosition(this->bomberMan->getBounds().left, windowHeight - this->bomberMan->getBounds().height);
    }
}

void Game::updateKey() {


    for (int i = 0; i <keys.size(); i++) {
        sf::FloatRect key = this->keys[i]->getBounds();
        sf::FloatRect player = this->bomberMan->getBounds();
        if(abs(key.top - player.top) <= key.width-3  && abs(key.left - player.left) <= key.width-3 ) {
            for (int i = 0; i < keys.size(); ++i) {
                float key_X = this->keys[i]->getBounds().left;
                float key_Y = this->keys[i]->getBounds().top;
                if(key_X == key.left && key_Y == key.top){
                    this->plusKeyCollectedByOne();
                    delete keys[i];
                    keys.erase(keys.begin() + i);
                    std::cout<< this->getKeyCollected()<<"\n";
                }
            }
        }

    }
}

void Game::updateDoor() {
    sf::FloatRect doorxy = this->door->getBounds();
    sf::FloatRect player = this->bomberMan->getBounds();
    if(abs(doorxy.top - player.top) <= doorxy.width-3  && abs(doorxy.left - player.left) <= doorxy.width-3 && keyCollected == 3 && !isReachedDoor){
        delete this->door;
        this->isReachedDoor = true;
        std::cout << "door collected" << std::endl;
    }


}

void Game::fixWallCollosion() {


    for (int i = 0; i < walls.size(); ++i) {
        sf::FloatRect wall = this->walls[i]->getBounds();
        sf::FloatRect player = this->bomberMan->getBounds();
        std::string direction = this->bomberMan->getDirection();
        if(abs(wall.top - player.top) >= wall.width - 2 || abs(wall.left - player.left) >= wall.width - 2)
            continue;
        if (direction == "Up" || direction == "Down") {
                    float new_y = player.top + (-2 + wall.width - abs(player.top - wall.top)) *
                                               ((player.top - wall.top) / abs(player.top - wall.top));
                    this->bomberMan->setPosition((player.left), (new_y));

        }
        else if (direction == "Right" || direction == "Left") {
                    float new_x = player.left + (-2 + wall.width - abs(player.left - wall.left)) *
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

            float x_b = bombs[i]->getBounds().left;
            float y_b = bombs[i]->getBounds().top;
            std::vector<sf::Vector2f> positions  = FindExplodedBlocks({x_b,y_b});
            wallExplosion(positions);
            bombermanExplosion(positions);
            enemyExplosion(positions);
            delete bombs[i];
            bombs.erase(bombs.begin() + i);

        }
    }
}

std::vector<sf::Vector2f> Game::FindExplodedBlocks(sf::Vector2f bomb) {

    std::vector<sf::Vector2f> positions;

    sf::Vector2f pos0 = {bomb.x ,bomb.y};
    sf::Vector2f pos1 = {bomb.x - blockSize,bomb.y};
    sf::Vector2f pos2 = {bomb.x + blockSize,bomb.y};
    sf::Vector2f pos3 = {bomb.x ,bomb.y - blockSize};
    sf::Vector2f pos4 = {bomb.x ,bomb.y + blockSize};

    positions.push_back(pos0);
    positions.push_back(pos1);
    positions.push_back(pos2);
    positions.push_back(pos3);
    positions.push_back(pos4);

    return positions;

}

void Game::wallExplosion(std::vector<sf::Vector2f> positions) {
    for (int i = 0; i < walls.size(); ++i) {
        for (int j = 0; j < positions.size(); ++j) {
            float wall_X = this->walls[i]->getBounds().left;
            float wall_Y = this->walls[i]->getBounds().top;

            if(wall_X == positions[j].x && wall_Y == positions[j].y && walls[i]->getType() == 'B'){
                delete walls[i];
                walls.erase(walls.begin() + i);
            }
        }
    }
}

void Game::bombermanExplosion(std::vector<sf::Vector2f> positions) {
    sf::Vector2f boyBlock = calcBombPos();
    for (int i = 0; i < positions.size(); ++i) {
       if(boyBlock.x == positions[i].x && boyBlock.y == positions[i].y){
           this->bomberMan->loseLife();
           std::cout << this->bomberMan->getLivesRemain() << std::endl;
       }
    }
}

std::vector<int> Game::getKeysIndex() {
    std::vector<int> output;
    std::vector<int> wall_type_B;
    for(int i=0;i<this->walls.size();i++){
        if(this->walls[i]->getType()=='B')
            wall_type_B.push_back(i);
    }
    std::srand(time(0));
    int var1=rand()%wall_type_B.size();
    int var2=rand()%wall_type_B.size();
    int var3=rand()%wall_type_B.size();
    if(var1==var2){
        while (var1==var2){
            var2=rand()%wall_type_B.size();
        }
    }
    if(var3==var1 || var3==var2){
        while(var3==var1 || var3==var2){
            var3=rand()%wall_type_B.size();
        }
    }
    output.push_back(wall_type_B[var1]);
    output.push_back(wall_type_B[var2]);
    output.push_back(wall_type_B[var3]);
    return output;
}

int Game::getKeyCollected() {
    return keyCollected;
}

void Game::plusKeyCollectedByOne() {
    keyCollected++;
}

void Game::updateEnemiesBoundsCollosion() {
    for (int i = 0; i < enemies.size(); ++i) {
        for (int j = 0; j < walls.size(); ++j) {
            if (enemies[i]->getsprite().getGlobalBounds().intersects(walls[j]->getsprite().getGlobalBounds())){
                if (enemies[i]->getDirection() == "Right"){enemies[i]->changeDirection("Left");}
                else if (enemies[i]->getDirection() == "Left"){enemies[i]->changeDirection("Right");}
                else if (enemies[i]->getDirection() == "Up"){enemies[i]->changeDirection("Down");}
                else if (enemies[i]->getDirection() == "Down"){enemies[i]->changeDirection("Up");}
            }
            if (enemies[i]->getBounds().left <= 0){enemies[i]->changeDirection("Right");}
            if (enemies[i]->getBounds().top <= 0){enemies[i]->changeDirection("Down");}
            if (enemies[i]->getBounds().left + enemies[i]->getBounds().width >= windowWidth){enemies[i]->changeDirection("Left");}
            if (enemies[i]->getBounds().left + enemies[i]->getBounds().height >= windowHeight){enemies[i]->changeDirection("Up");}
        }
    }
}

void Game::enemyExplosion(std::vector<sf::Vector2f> positions) {
    for (int i = 0; i < enemies.size(); ++i) {
        float new_X =  enemies[i]->getBounds().left + ((blockSize)/2);
        float new_Y = enemies[i]->getBounds().top + ((blockSize)/2);
        float enemy_x = new_X - ( static_cast<int>(floor(new_X)) % static_cast<int>(blockSize));
        float enemy_y = new_Y - ( static_cast<int>(floor(new_Y)) % static_cast<int>(blockSize));
        for (int j = 0; j < positions.size(); ++j) {
            if(enemy_x == positions[j].x && enemy_y == positions[j].y){
                delete enemies[i];
                enemies.erase(enemies.begin() + i);
            }
        }

    }
}

void Game::updateEnemiesBomberManCollosion() {
    for (int i = 0; i < enemies.size(); ++i) {
        if (enemies[i]->getsprite().getGlobalBounds().intersects(this->bomberMan->getSprite().getGlobalBounds())){
            delete enemies[i];
            enemies.erase(enemies.begin() + i);
            this->bomberMan->loseLife();
            std::cout << this->bomberMan->getLivesRemain() << std::endl;
        }
    }
}

void Game::updatelapsedseconds() {
    this->elapsedSeconds = timer.getElapsedTime().asSeconds();

}

void Game::updatestatusbar() {
    this->statusbar->updateCountdownText(120.f - this->elapsedSeconds);
    this->statusbar->setLives(this->bomberMan->getLivesRemain());
    this->statusbar->setkeys(keyCollected);
    this->statusbar->updateLivesBar();
}

void Game::updateGameStatus() {
    if(isReachedDoor && elapsedSeconds < 120.f){
        this->wonGame = true;
        std::cout << "wooon" << std::endl;
    }
    if (elapsedSeconds > 120.f || this->bomberMan->getLivesRemain() == 0){
        this->LoseGame = true;
        std::cout << "looose" << std::endl;
    }
}

void Game::initEndGameStatus() {
    endGameStatus.setSize(sf::Vector2f(windowWidth , windowHeight + STATUSBARHEIGHT));
    endGameStatus.setFillColor(sf::Color::White);
    endGameStatus.setPosition(0, 0);
}

void Game::initEndGameTexts() {
    if (!font.loadFromFile(FONT_TTF)) {
        std::cerr << "Font loading failed!" << std::endl;
    }

    wonGameMessage.setFont(font);
    wonGameMessage.setCharacterSize(23);
    wonGameMessage.setFillColor(sf::Color::Green);
    wonGameMessage.setPosition(0 ,  (windowHeight + STATUSBARHEIGHT - 100)/2);
    wonGameMessage.setString("YOU AVOIDED HARAAM\n\nAND FOUND \n\nTHE PATH TO HEAVEN!!");

    loseGameMessage.setFont(font);
    loseGameMessage.setCharacterSize(23);
    loseGameMessage.setFillColor(sf::Color::Red);
    loseGameMessage.setPosition(0 ,  (windowHeight + STATUSBARHEIGHT - 100)/2);
    loseGameMessage.setString("GIRLS DISTRACTED YOU \n\nSORRY LOSER!");
}












