all: ppmcopy

Image.o: Image.cc Image.h
	g++ -c -Werror Image.cc
	
ppmcopy.o: ppmcopy.cc Image.h
	g++ -c -Werror ppmcopy.cc

ppmcopy: ppmcopy.o Image.o
	g++ -o ppmcopy ppmcopy.o Image.o