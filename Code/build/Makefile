CC = g++
CFLAGS = `sdl2-config --cflags --libs`

SRC_RENDER = ../src/Render_Classes/Window.cpp ../src/Render_Classes/Object.cpp ../src/Render_Classes/Rectangle.cpp
SRC_SNAKE = ../src/Snake_Game_Classes/*
SRC = ../src/main.cpp $(SRC_RENDER) $(SRC_SNAKE)

INC_RENDER = -I ./../include/Render_Classes/
INC_SNAKE = -I./../include/Snake_Game_Classes/
INC = $(INC_RENDER) $(INC_SNAKE)

WIN_TEST_SRC = ../test_src/window_test.cpp ../src/Window.cpp ../src/Object.cpp
RECT_TEST_SRC = ../test_src/rectangle_test.cpp ../src/Window.cpp ../src/Object.cpp ../src/Rectangle.cpp

main:
	$(CC) -o snake -g $(INC) $(SRC) $(CFLAGS)

window_test:
	$(CC) -o window_test $(INC) $(WIN_TEST_SRC) $(CFLAGS)

rectangle_test:
	$(CC) -o rectangle_test $(INC) $(SRC) $(CFLAGS)

clean:
	rm rectangle_test window_test snake
