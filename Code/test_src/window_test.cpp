#include <Window.hpp>
#include <iostream>

int main(int argc, char *argv[]) {
  std::cout << "Starting Window Test" << std::endl;
  std::cout << "Test 1: Constructor Test" << std::endl;
  Window* window1 = new Window("Test 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 100, 100, 0);
  std::cout << "Did a window open? Y/N" << std::endl;
  std::string result1;
  std::cin >> result1;
  if(result1.compare("Y") == 0){
    std::cout << "Test worked" << std::endl;
  }
  else{
    std::cout << "Test failed" << std::endl;
  }

  std::cout << "\nTest 2: Destructor/close() Test" << std::endl;
  window1->close();
  std::cout << "Did a window close? Y/N" << std::endl;
  std::string result2;
  std::cin >> result2;
  if(result2.compare("Y") == 0){
    std::cout << "Test worked" << std::endl;
  }
  else{
    std::cout << "Test failed" << std::endl;
  }

  std::cout << "\nTest 3: pollEvents() (also tests getKeyStatus(scancode = X)) Test" << std::endl;
  Window* window2 = new Window("Test 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 100, 100, 0);
  while(!window2->getKeyStatus(SDL_SCANCODE_X)){
    window2->pollEvents();
    SDL_Delay(10); //to let the CPU cool down
  }
  std::cout << "It worked :)" << std::endl;

  std::cout << "\nTest 4: render() (not implemented)" << std::endl;

  //Will work later on tests


}
