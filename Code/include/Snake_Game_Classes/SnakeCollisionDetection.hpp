#ifndef SnakeCollisionDetection_hpp
#define SnakeCollisionDetection_hpp

#include <SnakePlayer.hpp>
#include <SnakeApple.hpp>
#include <SnakeWall.hpp>

class SnakeCollisionDetection{
private:
  SnakePlayer* player;
  SnakeApple* apple;
  std::vector<SnakeWall*>* walls;

public:
  SnakeCollisionDetection(SnakePlayer* player, SnakeApple* apple, std::vector<SnakeWall*>* walls);
  bool appleCollision();
  bool wallCollision();
  bool snakeCollision();
};

#endif
