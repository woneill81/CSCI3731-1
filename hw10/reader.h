#ifndef READER_H
#define READER_H
#include <cstdio>

int** read(FILE* file, char header[], int *width, int *height, int *numPixels);

#endif