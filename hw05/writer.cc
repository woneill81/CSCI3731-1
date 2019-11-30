#include <cstdio>
#include <stdio.h>
#include <jpeglib.h>
#include <setjmp.h>
#include "writer.h"

void write(FILE* file2, unsigned char* array, int width, int height, int numPixels){
	
	unsigned char * image_buffer = array;
	int image_height;
	int image_width;
	
	struct jpeg_compress_struct cinfo;
	struct jpeg_error_mgr jerr;
	
	unsigned char* row_pointer[1];
	int row_stride;
	
	cinfo.err = jpeg_std_error(&jerr);
	
	jpeg_create_compress(&cinfo);
	
	if(file2 == NULL){
		fprintf(stderr, "invalid file:%s\n", file2);
		exit(1);
	}	
	jpeg_stdio_dest(&cinfo, file2);
	
	cinfo.image_width = width;
	cinfo.image_height = height;
	cinfo.input_components = 3;
	cinfo.in_color_space = JCS_RGB;
	
	jpeg_set_defaults(&cinfo);
	
	jpeg_set_quality(&cinfo, 100, TRUE);

	jpeg_start_compress(&cinfo, TRUE);
	
	row_stride = x*3;
	
	while(cinfo.next_scanline < cinfo.image_height){
		row_pointer[0] = &image_buffer[cinfo.next_scanline * row_stride]);
		(void)jpeg_write_scanlines(&cinfo, row_pointer, 1);
		
	}	
	
	jpeg_finish_compress(&cinfo);
	
	jpeg_destroy_compress(&cinfo);
	
}