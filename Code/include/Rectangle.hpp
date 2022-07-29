#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <Color.hpp>
#include <Object.hpp>
#include <Position.hpp>

#define RECTANGLE_OBJECT_TYPE 1

class Rectangle : public Object{
private:
  bool filled;
  Color* color;
  SDL_Rect* sdlRect;

public:
  Rectangle(uint32_t posX, uint32_t posY, uint32_t width, uint32_t height, uint32_t ID);
  void fill(bool shouldBeFilled);
  void setColor(uint32_t R, uint32_t G, uint32_t B, uint32_t A);
  Color* getColor();
  void render(SDL_Renderer* renderer);
  void setPosition(uint32_t x, uint32_t y);
  Position getPosition();
};

#endif
