all: main

swap.o: swap.cc swap.h
	g++ -c -Werror swap.cc

main.o: main.cc swap.h
	g++ -c -Werror main.cc

main: main.o swap.o
	g++ -o main main.o swap.o