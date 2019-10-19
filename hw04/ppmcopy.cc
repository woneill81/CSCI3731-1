#include <cstdio>
#include "reader.h"
#include "writer.h"
//This is the main of Homework 5 modified from Homework 4
int main(int argc, char** argv){
	char ppm[10]="test.ppm";
	char ppm2[10]="final.ppm";
	char header[3];
	int width=0;
	int height=0;
	int numPixels=0;	
	//Read file and put binary into array data
	unsigned char* data=read(ppm, header, &width, &height, &numPixels);
	//Write file with data array as argument
	write(ppm2, (int)data, width, height, numPixels);
	//cleaning up data
	delete [] data;
	data=NULL;
}