#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <stdint.h>
#include <vector>
#include <string>

#include <Object.hpp>


class Window{
private:
  /*
  private Class variables
  */
  SDL_Window* sdlWindow;
  SDL_Renderer* sdlRenderer;
  std::vector<Object*>* objectList; //maby replace with hash map
  std::vector<SDL_Event>* events; //maby replace with hash map
  uint32_t FPS;


public:
  /*
  public class variables
  */
  bool isClosed;

  Window(std::string Title, uint32_t windowPosX, uint32_t windowPosY, uint32_t windowWidth, uint32_t windowHeight, uint32_t SDL_FLAGS);
  ~Window();

  void pollEvents();
  void render();
  void close();

  SDL_Window* getSDLWindow();
  SDL_Renderer* getSDLRenderer();

  void maximize();
  void minimize();

  uint32_t getFPS();
  void setFPS(uint32_t FPS);

  uint32_t getWidth();
  uint32_t getHeight();

  std::vector<Object*>* getObjectList();
  void addObject(Object* object);
  void deleteObject(uint32_t ID);
  uint32_t nextFreeID();

  bool getKeyStatus(SDL_Scancode scancode);
  bool getWindowEvent(SDL_WindowEventID event);
  //bool getEventStatus(SDL_Event event);

  void setMinimumSize(uint32_t w, uint32_t h);
};

#endif
