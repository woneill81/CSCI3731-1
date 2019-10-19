#ifndef READER_H
#define READER_H
#include <cstdio>

unsigned char* read(const char* file, char* header, int *width, int *height, int *numPixels);

#endif