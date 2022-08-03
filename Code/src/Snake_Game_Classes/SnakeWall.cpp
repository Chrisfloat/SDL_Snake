#include <SnakeWall.hpp>
#include <SnakePlayer.hpp>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>

SnakeWall::SnakeWall(Position FirstPosition, Position SecondPosition){
    this->FirstPosition = (Position*)malloc(sizeof(Position));
    this->SecondPosition = (Position*)malloc(sizeof(Position));

    this->FirstPosition->x = FirstPosition.x;
    this->FirstPosition->y = FirstPosition.y;

    this->SecondPosition->x = SecondPosition.x;
    this->SecondPosition->y = SecondPosition.y;
}


bool SnakeWall::positionInWall(Position posToCheck){
    uint32_t epsilon = RECTSIZE_SNAKE_PLAYER; //epsilon from which the value can differ
    int32_t xDelta = posToCheck.x - FirstPosition->x;
    int32_t yDelta = posToCheck.y - FirstPosition->y;
    if(std::abs(xDelta) < epsilon && posToCheck.y > FirstPosition->y && posToCheck.y < SecondPosition->y){
        return true;
    }
    else if(std::abs(yDelta) < epsilon && posToCheck.x > FirstPosition->x && posToCheck.x < SecondPosition->x){
        return true;
    }
    return false;
}

bool SnakeWall::positionLeftFromWall(Position posToCheck){
    if(posToCheck.y < FirstPosition->y && posToCheck.y < SecondPosition->y)
        return true;
    return false;
}

bool SnakeWall::positionRightFromWall(Position posToCheck){
    if(posToCheck.y > FirstPosition->y && posToCheck.y > SecondPosition->y)
        return true;
    return false;
}

bool SnakeWall::positionAboveWall(Position posToCheck){
    if(posToCheck.x > FirstPosition->x && posToCheck.x > SecondPosition->x)
        return true;
    return false;
}

bool SnakeWall::positionUnderWall(Position posToCheck){
    if(posToCheck.x > FirstPosition->x && posToCheck.x > SecondPosition->x)
        return true;
    return false;
}
