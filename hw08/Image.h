#ifndef IMAGE_H
#define IMAGE_H

class Image {

private:
	char header[3];
	int width;
	int height;
	int size=height*3*width;
	unsigned char* numPixels;

public:
	int** read(const char* file);
	void write(const char* file2, int** array);
	//virtual ~Image();

};
#endif