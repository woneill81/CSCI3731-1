#include <cstdio>
#include "reader.h"
//Read function for Homework 5 modified from Homework 4
int** read(const char* file, char* header, int *width, int *height, int *numPixels){
	
	FILE* fp = fopen(file , "rb");
	
	fscanf(fp , "%s\n%d %d\n%d\n", header, width, height, numPixels);
	printf("First line in the header: %s\n", header);
	printf("Width of the image: %d\n", *width); 
	printf("Height of the image: %d\n", *height);
	printf("Number of pixels: %d\n", *numPixels);
	
	int size=(*height)*3*(*width); //width*height 

	unsigned char* rgb=(unsigned char*)(&size);
	int** array = new int*[*height]; //Allocate new array of pointers
	*array=new int[width*height]; //Allocate flat array
	//Set all the other elements in array of pointers
	for(int i=1; i<height; i++){
		array[i] = array[i-1]+width;
	}
	//Set the beginning of each row to 255
	for(int j=0; j<height; ++j){
		array[j]=255;
		//Copy the flat array into the 2D array of ints
		for(int i=0; i<width; ++i){
			(int)array[j][i]+=rgb[i];
		}
	}
	int check=fread(rgb, sizeof(char), size, fp);
	printf("Size of the image: %d\nNumber of pixels read: %d\n", size, check);
	printf("Check output: %x\n", array[2]);
	
	
	fclose(fp);
	return array;
}