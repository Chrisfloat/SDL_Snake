#include <SnakeCollisionDetection.hpp>

SnakeCollisionDetection::SnakeCollisionDetection(SnakePlayer* player, SnakeApple* apple, std::vector<SnakeWall*>* walls){
    this->player = player;
    this->apple = apple;
    this->walls = new std::vector<SnakeWall*>();
    for(int i = 0; i<walls->size(); i++)
        this->walls->push_back(walls->at(i));
}

bool SnakeCollisionDetection::appleCollision(){
    uint32_t epsilon = 10;
    int32_t xDelta = player->getHeadPos().x - apple->currentPosition->x;
    int32_t yDelta = player->getHeadPos().y - apple->currentPosition->y;
    if(std::abs(xDelta) < epsilon && std::abs(yDelta) < epsilon)
        return true;
    return false;
}

bool SnakeCollisionDetection::wallCollision(){
    for(int i = 0; i<walls->size(); i++){
        if(walls->at(i)->positionInWall(player->getHeadPos()))
            return true;
    }
    return false;
}

bool SnakeCollisionDetection::snakeCollision(){
    std::vector<Rectangle*>* list = player->getRectList();
    uint32_t epsilon = 3;
    int32_t xDelta, yDelta;
    for(int i = 1; i<list->size(); i++){
        xDelta = player->getHeadPos().x - list->at(i)->getPosition().x;
        yDelta = player->getHeadPos().y - list->at(i)->getPosition().y;
        if(std::abs(xDelta) < epsilon && std::abs(yDelta) < epsilon)
            return true;
    }
    return false;
}