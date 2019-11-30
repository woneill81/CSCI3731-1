#include <cstdio>
#include "reader.h"
#include "writer.h"

int main(int argc, char** argv){
	FILE* fp = fopen("test.ppm", "rb");
	FILE* fw = fopen("test2.ppm", "wb");
	
	char header[3];
	header[2]='\0';
	int width=0;
	int height=0;
	int numPixels=0;	
	
	//Read file and put binary into array data
	unsigned char* array = read(fp, header, &width, &height, &numPixels);
	
	//Write file with data array as argument
	write(fw, array, width, height, numPixels);
	
	//cleaning up data
	delete[] array;
	array=NULL;
	
	fclose(fw);
	fclose(fp);
}