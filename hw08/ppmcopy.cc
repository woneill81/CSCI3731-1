#include <cstdio>
#include "Image.h"
//This is the main of Homework 5 modified from Homework 4
int main(int argc, char** argv){
	Image img;
	char ppm[10]="test.ppm";
	char ppm2[10]="final.ppm";
	/*char header[3];
	int width=0;
	int height=0;
	int numPixels=0;	
	
	Read file and put binary into array data
	unsigned char* data=read(ppm, header, &width, &height, &numPixels);
	//Write file with data array as argument
	write(ppm2, data, width, height, numPixels);
	//cleaning up data
	delete [] data;
	data=NULL;*/
	
	int** array = img.read(ppm); 
	img.write(ppm2, array);
	
}