all: main 

Angle.o: Angle.cc Angle.h
	g++ -c -Werror Angle.cc
	
main.o: main.cc Angle.h
	g++ -c -Werror main.cc
	
main: main.o Angle.o
	g++ -o main main.o Angle.o