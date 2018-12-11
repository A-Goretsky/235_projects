
CXXFLAGS=-std=c++14

main: main.o SortingTests.o
	g++ -o main main.o SortingTests.o

main.o: main.cpp SortingTests.hpp
	g++ $(CXXFLAGS) -c main.cpp -g

SortingTests.o: SortingTests.cpp SortingTests.hpp
	g++ $(CXXFLAGS) -c SortingTests.cpp -g
	
clean: 
	rm -f main.o SortingTests.o main
