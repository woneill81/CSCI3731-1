all: main

main.o: main.cc angle.h
	g++ -c -Werror main.cc

fish.o: fish.cc fish.h angle.h
	g++ -c -Werror fish.cc

main: main.o fish.o
	g++ -o main main.o fish.o
