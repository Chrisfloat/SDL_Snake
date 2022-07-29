#include <Window.hpp>
#include <Rectangle.hpp>

int main(int argc, char const *argv[]) {
  Window* window = new Window("Test 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 100, 100, SDL_WINDOW_RESIZABLE);
  window->maximize();
  window->setFPS(10);

  Rectangle* rect = new Rectangle(100, 100, 20, 20, 1);
  //window->addObject((Object*)rect);

  Rectangle* rect2 = new Rectangle(200, 200, 20, 20, 2);
  rect2->fill(true);
  rect2->setColor(255, 0, 0, 255);
  //window->addObject((Object*)rect2);

  std::vector<Rectangle*>* rects = new std::vector<Rectangle*>();
  for(int i = 0; i<1000; i++){
    Rectangle* rect1 = new Rectangle(200, 200, 20, 20, i+3);
    rect1->fill(true);
    rect1->setColor((i<<20)%255, (i<<10)%255, (i<<25)%255, 255);
    window->addObject((Object*)rect1);
    rects->push_back(rect1);
  }

  uint32_t timer = 0;

  while(!window->getKeyStatus(SDL_SCANCODE_ESCAPE) && !window->getWindowEvent(SDL_WINDOWEVENT_CLOSE)){
    window->pollEvents();

    if(timer == 359) timer = 0;
    else timer++;

    rect2->setPosition(std::sin(timer)*400+500, std::cos(timer)*400+500);

    for(int i = 0; i<1000; i++){
      rects->at(i)->setPosition(std::sin(timer+i*2)*400+600, std::cos(timer+i)*400+500);
    }

    window->render();
  }

  delete window;

}
