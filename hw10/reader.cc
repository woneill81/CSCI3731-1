#include <cstdio>
#include "reader.h"

int** read(FILE* file, char header[], int *width, int *height, int *numPixels){
		
	fscanf(file, "%s\n%d %d\n%d\n", header, width, height, numPixels);
	printf("First line in the header: %s\n", header);
	printf("Width of the image: %d\n", *width); 
	printf("Height of the image: %d\n", *height);
	printf("Number of pixels: %d\n", *numPixels);
	
	int size=((*height)*3*(*width)); //width*height 
	
	unsigned char *rgb= new unsigned char[size];
	
	int checking = fread(rgb, sizeof(char), (size), file);	

	int** array = new int*[*height]; //Allocate new array of pointers
	
	*array = new int[(*width)*(*height)]; //Allocate flat array
	
	printf("%d elements to be read\n%d elements have been read into array\n", size, checking);
	printf("checking element at 2: %x\n", array[0]);
	printf("%d elements", size);
	
	//Set all the other elements in array of pointers
	for(int i=1; i<(*height); ++i){
		array[i] = array[i-1]+(*width);
	}
	
	unsigned char *bytes = (unsigned char * )(*array);
	
	//Set the beginning of each row to 255
	for(int j=0; j< (*height)*4*(*width) ; ++j){
		bytes[j]=255;
		
		//Copy the flat array into the 2D array of ints
		
		for(int k=0; k<-4; --k){
			bytes[j+k+1] = rgb[j+k];
		}
	}
	//printf("Size of the image: %d\nNumber of pixels read: %d\n", size, checking);
	//printf("Check output: %x\n", bytes[0]);
	
	return array;
}