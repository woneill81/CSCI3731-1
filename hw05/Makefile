all: main

reader.o: reader.cc reader.h
	g++ -c -Werror reader.cc
	
writer.o: writer.cc writer.h
	g++ -c -Werror writer.cc
	
ppmcopy.o: ppmcopy.cc reader.h writer.h
	g++ -c -Werror ppmcopy.cc

main: ppmcopy.o writer.o reader.o 
	g++ -o main ppmcopy.o reader.o writer.o -ljpeg