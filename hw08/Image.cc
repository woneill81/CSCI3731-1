#include <cstdio>
#include "Image.h"
		
int** Image::read(const char* file){
	FILE* fp = fopen(file , "rb");	
	fscanf(fp , "%s\n%d %d\n%d\n", header, width, height, numPixels);

	unsigned char* rgb=(unsigned char*)(&size);
	int** array = new int*[height]; //Allocate new array of pointers
	*array=new int[width*height]; //Allocate flat array
	//Set all the other elements in array of pointers
	for(int i=1; i<height; i++){
		array[i] = array[i-1]+width;
	}
	//Set the beginning of each row to 255
	for(int j=0; j<height; ++j){
		*array[j]=255;
		//Copy the flat array into the 2D array of ints
		for(int i=0; i<width; ++i){
			array[j][i]+=rgb[i];
		}
	}
	int check=fread(rgb, sizeof(char), size, fp);
	printf("Size of the image: %d\nNumber of pixels read: %d\n", size, check);
	printf("Check output: %x\n", array[2]);
	
	return array;
	fclose(fp);		
	
}

void Image::write(const char* file2, int** array){
		
	FILE* fw = fopen(file2 , "wb");
	 //width*height
	fprintf(fw, "%s\n%d %d\n%d\n", "P6", width, height, numPixels);
	int flamingo = fwrite(&array, sizeof(char), size, fw);
	printf("Data to be written%d\n  Written data: %d\n", flamingo);
	
	fclose(fw);
	
}	




