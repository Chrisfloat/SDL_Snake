#include <SnakeApple.hpp>
#include <SnakePlayer.hpp>

SnakeApple::SnakeApple(Position pos, Window* window){
    currentPosition = (Position*)malloc(sizeof(Position));
    currentPosition->x = pos.x;
    currentPosition->y = pos.y;

    appleRectangle = new Rectangle(pos.x, pos.y, RECTSIZE_SNAKE_PLAYER, RECTSIZE_SNAKE_PLAYER, window->nextFreeID());
    appleRectangle->setColor(200, 0, 0, 255);
    appleRectangle->fill(true);
    window->addObject(appleRectangle);
    std::srand(SDL_GetTicks());
}

void SnakeApple::setRandomPosition(Window* window){
    uint64_t rnumX = std::rand()%window->getWidth();
    rnumX -= rnumX%RECTSIZE_SNAKE_PLAYER;

    uint64_t rnumY = std::rand()%window->getHeight();
    rnumY -= rnumY%RECTSIZE_SNAKE_PLAYER;

    currentPosition->x = rnumX;
    currentPosition->y = rnumY;
    appleRectangle->setPosition(rnumX, rnumY);
}
  