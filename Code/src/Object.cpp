#include <Object.hpp>
#include <iostream>

Object::Object(uint32_t type, uint32_t ID){
  this->type = type;
  this->ID = ID;
}

uint32_t Object::getType(){
  return this->type;
}

uint32_t Object::getID(){
  return this->ID;
}


void Object::render(SDL_Renderer* renderer){
  std::cout << "wrong render func" << "\n";
}
