#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <stdint.h>

class Object{
protected:
  uint32_t type;
  uint32_t ID;

public:
  Object(uint32_t type, uint32_t ID);
  uint32_t getType();
  uint32_t getID();
  void render(SDL_Renderer* renderer);
};

#endif
