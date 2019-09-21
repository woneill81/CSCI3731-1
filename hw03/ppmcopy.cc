#include <cstdio>

int main(int argc, char** argv) {
	//Open test.ppm and write to final.ppm
	FILE* fp = fopen("test.ppm", "rb");
	FILE* destination = fopen("final.ppm", "wb");
	
	//variables to store the header
	char p6[3];
	int x = 0;
	int y = 0;
	int maxPixel = 0;
	
	
	//read header and assign
	fscanf(fp, "%s\n%d %d\n%d\n", p6, &x, &y, &maxPixel);
	
	//assign the null terminator
	p6[2] = '\0';
	
	//checking
	printf("p6 is %s\n", p6);
	printf("x is %d\n", x);
	printf("y is %d\n", y);
	printf("maxPixel is %d\n", maxPixel);
	
	
	unsigned char *array = new unsigned char[x*3*y];
	
	int checking = fread(array, sizeof(char), x*3*y, fp);
	
	printf("%d elements should be read\nReport: %d elements are read\n", x*3*y, checking);
	printf("This step is for checking element at 2: %x\n", array[2]);
	
	//write the header into final.ppm
	fprintf(destination, "%s\n%d %d\n%d\n", "P6", x, y, maxPixel);
	
	//checking will now store the number of values is written into final.ppm
	checking = fwrite(array, sizeof(char), x*3*y, destination);
	
	//Report
	printf("%d elements should be written\nReport: %d elements are written\n", x*3*y, checking);
	
	//Cleaning up the memory
	delete [] array;
	array = NULL;
	
	fclose(destination);
	fclose(fp);
}