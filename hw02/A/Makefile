all: counter

counter.o: counter.cc
	g++ -c -Werror counter.cc
	
main: counter.o
	g++ -o main counter.o