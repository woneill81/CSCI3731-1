all: ppmcopy

ppmcopy.o: ppmcopy.cc
	g++ -c -Werror ppmcopy.cc

ppmcopy: ppmcopy.o
	g++ -o ppmcopy ppmcopy.o