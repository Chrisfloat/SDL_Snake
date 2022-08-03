#include <Window.hpp>
#include <SnakeGame.hpp>
#include <SnakeCollisionDetection.hpp>

#include <iostream>

SnakeGame::SnakeGame(){
    window = new Window("SDL Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 780, 780, 0);
    window->setMinimumSize(100, 100);
    window->setFPS(20);

    player = new SnakePlayer(window);
    apple = new SnakeApple(player->getHeadPos(), window);
    
    walls = new std::vector<SnakeWall*>();
    Position topLeft = {0, 0};
    Position topRight = {window->getWidth(), 0};
    Position bottomLeft = {0, window->getHeight()};
    Position bottomRight = {window->getWidth(), window->getHeight()};
    walls->push_back(new SnakeWall(topLeft, topRight));
    walls->push_back(new SnakeWall(topLeft, bottomLeft));
    walls->push_back(new SnakeWall(bottomLeft, bottomRight));
    walls->push_back(new SnakeWall(topRight, bottomRight));

    collDetect = new SnakeCollisionDetection(player, apple, walls);

    gameIsFinished = false;
    points = 0;
    //Start GAME
    game();
}

void SnakeGame::game(){
    while(!window->getWindowEvent(SDL_WINDOWEVENT_CLOSE) && !gameIsFinished){
        window->pollEvents();

        //get player input and move
        player->getInput();
        player->move();

        //collision logic
        collisionLogic();

        window->render();
    }
    SDL_Delay(1000*1);
}

//logic that needs to processed when a collision appeared
void SnakeGame::collisionLogic(){
    //snake wall collision
    if(collDetect->wallCollision()){
        gameIsFinished = true;
    }
    if(collDetect->appleCollision()){
        points++;
        player->addRect();
        apple->setRandomPosition(window);
    }
    if(collDetect->snakeCollision()){
        gameIsFinished = true;
    }
}

void SnakeGame::test(){
    player->addRect();
    player->addRect();
    while(!window->getWindowEvent(SDL_WINDOWEVENT_CLOSE) && !gameIsFinished){
        window->pollEvents();

        std::cout << RECTSIZE_SNAKE_PLAYER << std::endl;

        //get player input and move
        player->getInput();
        player->move();

        //collision logic
        collisionLogic();

        window->render();
    }
    SDL_Delay(1000*1);
}