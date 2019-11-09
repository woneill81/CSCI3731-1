all: main 

fish.o: fish.cc fish.h angle.h population.h
	g++ -c -Werror fish.cc

population.o: population.cc population.h
	g++ -c -Werror population.cc
	
drunkenfish.o: drunkenfish.cc drunkenfish.h fish.h angle.h population.h
	g++ -c -Werror drunkenfish.cc

flippyfish.o: flippyfish.cc flippyfish.h fish.h angle.h population.h
	g++ -c -Werror flippyfish.cc
	
angle.o: angle.cc angle.h
	g++ -c -Werror angle.cc
	
main.o: main.cc angle.h population.h fish.h drunkenfish.h flippyfish.h
	g++ -c -Werror main.cc
	
main: main.o angle.o flippyfish.o drunkenfish.o population.o fish.o
	g++ -o main main.o angle.o flippyfish.o drunkenfish.o population.o fish.o
	
