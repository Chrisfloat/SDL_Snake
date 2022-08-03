#ifndef SnakeGame_hpp
#define SnakeGame_hpp

#include <Window.hpp>
#include <SnakePlayer.hpp>
#include <SnakeApple.hpp>
#include <SnakeWall.hpp>
#include <SnakeCollisionDetection.hpp>

class SnakeGame{
private:
  Window* window;
  SnakePlayer* player;
  SnakeApple* apple;
  std::vector<SnakeWall*>* walls;
  SnakeCollisionDetection* collDetect;

  uint32_t points;

  //private attributes for check
  bool gameIsFinished;

  //Private functions for abstraction purpose
  void collisionLogic();


public:
  SnakeGame();
  void game();
  void test();

};

#endif
