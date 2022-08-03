#ifndef SnakeApple_hpp
#define SnakeApple_hpp

#include <Position.hpp>
#include <Rectangle.hpp>
#include <SnakePlayer.hpp>
#include <Window.hpp>

class SnakeApple{
public:
  Position* currentPosition;
  Rectangle* appleRectangle;

  SnakeApple(Position pos, Window* window);
  void setRandomPosition(Window* window);

};

#endif
