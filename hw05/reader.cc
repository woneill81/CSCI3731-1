#include <cstdio>
#include "reader.h"

unsigned char* read(FILE* file, char header[], int *width, int *height, int *numPixels){
		
	fscanf(file, "%s\n%d %d\n%d\n", header, width, height, numPixels);
	printf("First line in the header: %s\n", header);
	printf("Width of the image: %d\n", *width); 
	printf("Height of the image: %d\n", *height);
	printf("Number of pixels: %d\n", *numPixels);
	
	int size=((*height)*3*(*width)); //width*height 
	
	unsigned char *rgb= new unsigned char[size];
	
	int checking = fread(rgb, sizeof(char), size, file);	
	
	printf("%d elements to be read\n%d elements have been read into array\n", size, checking);
	printf("checking element at 2: %x\n", array[0]);	
	
	//printf("Size of the image: %d\nNumber of pixels read: %d\n", size, checking);
	//printf("Check output: %x\n", bytes[0]);
	
	return array;
}