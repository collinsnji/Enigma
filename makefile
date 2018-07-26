SRC = $(shell pwd)/src/enigma.cxx
CC = g++
DEBUG = -g
CPP_STD = -std=c++14
FLAGS = -Wall -Wextra $(DEBUG) $(CPP_STD)

build:
	mkdir -p $(shell pwd)/build
	$(CC) $(FLAGS) $(SRC) -o build/enigma.o
clean:
	\rm -r build/*.o
test:
	./build/enigma.o