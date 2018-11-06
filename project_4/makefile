CXXFLAGS=-std=c++11

main: main.o MazeSolver.o
	g++ $(CXXFLAGS) -o main main.o MazeSolver.o

main.o: main.cpp MazeSolver.h
	g++ $(CXXFLAGS) -c main.cpp

MazeSolver.o: MazeSolver.cpp MazeSolver.h
	g++ $(CXXFLAGS) -c MazeSolver.cpp

debug: CXXFLAGS:=$(CXXFLAGS) -g -fsanitize=address,undefined

debug: main

clean:
	rm main.o MazeSolver.o
