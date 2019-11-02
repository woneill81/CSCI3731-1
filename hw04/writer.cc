#include <cstdio>
#include "writer.h"
//Write function for Homework 5 modified from Homework 4
void write(const char* file2, unsigned char* array, int width, int height, int numPixels){

	FILE* fw = fopen(file2 , "wb");
	int size=height*3*width; //width*height
	fprintf(fw, "%s\n%d %d\n%d\n", "P6", width, height, numPixels);
	int flamingo = fwrite(array, sizeof(char), size, fw);
	printf("Data to be written%d\n  Written data: %d\n", flamingo);
	
	fclose(fw);
}