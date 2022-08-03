#include <SnakePlayer.hpp>
#include <iostream>


SnakePlayer::SnakePlayer(Window* window){
  rectangleList = new std::vector<Rectangle*>();
  currentDirection = right;
  this->window = window;

  //Create two rectangles for start
  Rectangle* rect = new Rectangle(window->getWidth()/2, window->getHeight()/2, RECTSIZE_SNAKE_PLAYER, RECTSIZE_SNAKE_PLAYER, window->nextFreeID());
  rect->setColor(0, 200, 0, 255);
  rect->fill(true);
  window->addObject(rect);
  rectangleList->push_back(rect);
  rect = new Rectangle(window->getWidth()/2, window->getHeight()/2, RECTSIZE_SNAKE_PLAYER, RECTSIZE_SNAKE_PLAYER, window->nextFreeID());
  rect->setColor(0, 200, 0, 255);
  rect->fill(true);
  window->addObject(rect);
  rectangleList->push_back(rect);

  gotInput = false;
  lastInputDir = up;
}

Position SnakePlayer::getHeadPos(){
  return rectangleList->at(0)->getPosition();
}

void SnakePlayer::move(){
  gotInput = false;
  for(int i = rectangleList->size()-1; i>0; i--){
    rectangleList->at(i)->setPosition(rectangleList->at(i-1)->getPosition().x, rectangleList->at(i-1)->getPosition().y);
  }
  Position currentPos = getHeadPos();
  switch(currentDirection){
    case up: rectangleList->at(0)->setPosition(currentPos.x, currentPos.y-RECTSIZE_SNAKE_PLAYER); break;
    case down: rectangleList->at(0)->setPosition(currentPos.x, currentPos.y+RECTSIZE_SNAKE_PLAYER); break;
    case left: rectangleList->at(0)->setPosition(currentPos.x-RECTSIZE_SNAKE_PLAYER, currentPos.y); break;
    case right: rectangleList->at(0)->setPosition(currentPos.x+RECTSIZE_SNAKE_PLAYER, currentPos.y); break;
    }
   /* 
  for(int i = 0; i<rectangleList->size(); i++)
    std::cout << "X = " << rectangleList->at(i)->getPosition().x << " Y = " << rectangleList->at(i)->getPosition().y << std::endl;
  std::cout << std::endl;
  */
}

void SnakePlayer::setDirection(Direction newDirection){
  switch(newDirection){
    case up:
    case down:
      if(currentDirection == right || currentDirection == left)
        currentDirection = newDirection;
      break;
    case left:
    case right:
      if(currentDirection == up || currentDirection == down)
        currentDirection = newDirection;
      break;
  }
}

Direction SnakePlayer::getDirection(){
  return currentDirection;
}

void SnakePlayer::getInput(){
  if(!gotInput){
    if(window->getKeyStatus(SDL_SCANCODE_W)){
      lastInputDir = up;
      gotInput = true;
    }
    else if(window->getKeyStatus(SDL_SCANCODE_S)){
      lastInputDir = down;
      gotInput = true;
    }
    else if(window->getKeyStatus(SDL_SCANCODE_A)){
      lastInputDir = left;
      gotInput = true;
    }
    else if(window->getKeyStatus(SDL_SCANCODE_D)){
      lastInputDir = right;
      gotInput = true;
    }
  }
  setDirection(lastInputDir);
}

void SnakePlayer::addRect(){
  Position p = rectangleList->at(rectangleList->size()-1)->getPosition();
  Rectangle* tmp = new Rectangle(-1, -1, RECTSIZE_SNAKE_PLAYER, RECTSIZE_SNAKE_PLAYER, window->nextFreeID());
  tmp->setColor(0, 150, 0, 255);
  tmp->fill(true);
  rectangleList->push_back(tmp);
  window->addObject(tmp);
}

std::vector<Rectangle*>* SnakePlayer::getRectList(){
  return rectangleList;
}
