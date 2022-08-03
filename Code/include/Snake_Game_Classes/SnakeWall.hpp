#ifndef SnakeWall_hpp
#define SnakeWall_hpp

#include <Position.hpp>

class SnakeWall{
public:
  Position* FirstPosition;
  Position* SecondPosition;

  SnakeWall(Position FirstPosition, Position SecondPosition);
  bool positionInWall(Position posToCheck);
  bool positionLeftFromWall(Position posToCheck);
  bool positionRightFromWall(Position posToCheck);
  bool positionAboveWall(Position posToCheck);
  bool positionUnderWall(Position posToCheck);
};

#endif
