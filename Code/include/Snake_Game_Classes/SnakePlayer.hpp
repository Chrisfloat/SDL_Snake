#ifndef SnakePlayer_hpp
#define SnakePlayer_hpp

#include <Rectangle.hpp>
#include <Direction.hpp>
#include <Window.hpp>
#include <Position.hpp>

#define RECTSIZE_SNAKE_PLAYER 15

class SnakePlayer{
private:
  std::vector<Rectangle*>* rectangleList;
  Direction currentDirection;
  Window* window;

  bool gotInput;
  Direction lastInputDir;

public:
  SnakePlayer(Window* window);
  Position getHeadPos();
  void move();
  void setDirection(Direction newDirection);
  Direction getDirection();
  void getInput();
  void addRect();
  std::vector<Rectangle*>* getRectList(); // XD
};

#endif
