#include <Rectangle.hpp>
#include <stdlib.h>

Rectangle::Rectangle(uint32_t posX, uint32_t posY, uint32_t width, uint32_t height, uint32_t ID) : Object(RECTANGLE_OBJECT_TYPE, ID){
  this->filled = false;

  this->color = (Color*) malloc(sizeof(Color));
  color->R = 255; color->G = 255; color->B = 255; color->A = 255;

  this->sdlRect = (SDL_Rect*) malloc(sizeof(SDL_Rect));
  sdlRect->x = posX; sdlRect->y = posY; sdlRect->w = width; sdlRect->h = height;

}

void Rectangle::fill(bool shouldBeFilled){
  this->filled = shouldBeFilled;
}

void Rectangle::setColor(uint32_t R, uint32_t G, uint32_t B, uint32_t A){
  color->R = R; color->G = G; color->B = B; color->A = A;
}

Color* Rectangle::getColor(){
  return color;
}

void Rectangle::render(SDL_Renderer* renderer){
  SDL_SetRenderDrawColor(renderer, color->R, color->G, color->B, color->A);
  if(filled)
    SDL_RenderFillRect(renderer, sdlRect);
  else
    SDL_RenderDrawRect(renderer, sdlRect);
}

void Rectangle::setPosition(uint32_t x, uint32_t y){
  sdlRect->x = x;
  sdlRect->y = y;
}

Position Rectangle::getPosition(){
  Position pos;
  pos.x = sdlRect->x;
  pos.y = sdlRect->y;
  return pos;
}
