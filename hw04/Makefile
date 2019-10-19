all: ppmcopy

ppmcopy.o: ppmcopy.cc reader.h
	g++ -c -Werror ppmcopy.cc

reader.o: reader.cc writer.h
	g++ -c -Werror reader.cc
	
writer.o: writer.cc reader.h writer.h
	g++ -c -Werror writer.cc
	
ppmcopy: ppmcopy.o writer.o reader.o
	g++ -o ppmcopy ppmcopy.o writer.o reader.o