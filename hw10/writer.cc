#include <cstdio>
#include "writer.h"

void write(FILE* file2, int** array, int width, int height, int numPixels){
	
	
	int size=height*3*width; //width*height
	
	unsigned char *rgb = new unsigned char[size];
	unsigned char *bytes =  (unsigned char * ) array[0];
	
	for(int i = 0; i < size; ){
		for(int j = 0; i<3; ++j){
		rgb[i+j] = bytes[i+j+1]; 
		}
	}	
	
	fprintf(file2, "%s\n%d %d\n%d\n", "P6", width, height, numPixels);
	
	int flamingo = fwrite(rgb, sizeof(char), size, file2);
	
	printf("Data to be written%d\n  Written data: %d\n", flamingo);
	
	delete [] rgb;
	rgb = NULL;
}