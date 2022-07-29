CC = g++
CFLAGS = `sdl2-config --cflags --libs`
SRC = ../src/main.cpp ../src/Window.cpp ../src/Object.cpp ../src/Rectangle.cpp
INC = -I ./../include/

WIN_TEST_SRC = ../test_src/window_test.cpp ../src/Window.cpp ../src/Object.cpp
RECT_TEST_SRC = ../test_src/rectangle_test.cpp ../src/Window.cpp ../src/Object.cpp ../src/Rectangle.cpp

main:
	$(CC) -o snake $(INC) $(SRC) $(CFLAGS)

window_test:
	$(CC) -o window_test $(INC) $(WIN_TEST_SRC) $(CFLAGS)

rectangle_test:
	$(CC) -o rectangle_test $(INC) $(RECT_TEST_SRC) $(CFLAGS)

clean:
	rm rectangle_test window_test snake
