all: main

hw1.o: hw1.cc subtraction.h
	g++ -c -Wall -Werror hw1.cc
	
subtraction.o: subtraction.cc subtraction.h
	g++ -c -Wall -Werror subtraction.cc
	
main: hw1.o subtraction.o subtraction.h
	g++ -o main hw1.o subtraction.o