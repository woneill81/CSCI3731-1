all: main
	
main.o: main.cc
	g++ -c -Werror main.cc
	
Angle.o: Angle.cc Angle.h
	g++ -c -Werror Angle.cc
	
Fish.o: Fish.cc Fish.h Angle.h
	g++ -c -Werror Fish.cc

Population.o: Population.cc Population.h
	g++ -c -Werror Population.cc

main: main.o Angle.o Fish.o Population.o
	g++ -o test main.o Angle.o Fish.o Population.o