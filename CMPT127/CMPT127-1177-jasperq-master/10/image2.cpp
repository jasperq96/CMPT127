#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "image2.hpp"


  /* Constructs an image of 0x0 pixels. */
  Image::Image()
  :cols (0),
   rows (0),
   pixels (NULL)
  {}
  
  /* Frees all memory allocated for img */
  Image::~Image(){
  	if(pixels != NULL){
  		delete[] pixels;
  	}
  }

  /* Changes the size of an image, allocating memory as necessary, and
     setting all pixels to fillcolor. Returns 0 on success, or a non-zero error code.*/ 
  int Image::resize( unsigned int width,  unsigned int height, uint8_t fillcolor ){
  	cols = width;
  	rows = height;
  	pixels = (uint8_t*) malloc(sizeof(uint8_t)*cols*rows);
  	if(pixels){
  		for(int x = 0; x < rows*cols; ++x){
  			pixels[x] = fillcolor;
  		}
  		return 0;
  	}
  	return 1;  	
  }
  
  /* Sets the color of the pixel at (x,y) to color. Returns 0 on success, else a non-zero 
     error code. If (x,y) is not a valid pixel, the call fails and the image does not change.*/
  int Image::set_pixel( unsigned int x, unsigned int y, uint8_t color ){
  	if(pixels){
  		if(x < cols && x >= 0){
	  		if(y < rows && y >= 0){
	  			pixels[(y*cols)+x] = color;
	  			return 0;
	  		}
  			return 1;
  		}
  		return 1;
  	}
  	return 1;
  }
  
  /* Gets the color of the pixel at (x,y) and stores at the address pointed to 
     by colorp. Returns 0 on success, else a non-zero error code. */
  int Image::get_pixel( unsigned int x, unsigned int y, uint8_t* colorp ){
  	if(pixels && colorp){
  		if ((x >= 0 && x < cols) && (y >= 0 && y < rows)){
  			*colorp = pixels[(y*cols)+x];
  			return 0;
  		}
  		return 1;
  	}
  	return 1;
  }

  /* Saves the image in the file filename. In a format that can be
     loaded by load().  Returns 0 on success, else a non-zero error
     code. */
  int Image::save( const char* filename ){
  	if(filename == NULL){
  		return 1;
  	}
	FILE * myfile = fopen(filename, "w");
	if(myfile != NULL){
		fwrite(&cols, sizeof(int), 1, myfile);
		fwrite(&rows, sizeof(int), 1, myfile);
		if((pixels == NULL) || (cols < 0) || (rows < 0)){
			fclose(myfile);
			return 0;
		}
		else{
			fwrite(pixels, sizeof(uint8_t), cols*rows, myfile);
			fclose(myfile);
			return 0;
		}
	}
}

  /* Load the image from the file filename, replacing the current
     image size and data. The file is in a format that was saved by
     save().  Returns 0 success, else a non-zero error code . */
int Image::load( const char* filename ){
  	if(filename == NULL){
  		return 1;
  	}
	FILE * myfile = fopen(filename, "r");
	if(myfile == NULL){
		return 1;
	}
	int index = 0;
	uint8_t x;
	if(fread(&cols, sizeof(int), 1, myfile) != 1){
		return 1;
	}
	if(fread(&rows, sizeof(int), 1, myfile) != 1){
		return 1;
	}
	if( (cols < 0) || (rows < 0)){
		return 1;
	}
	pixels = (uint8_t*) malloc(sizeof(uint8_t) * cols * rows);
	if(pixels == NULL){
		return 1;
	}
			
	while(fread(&x, sizeof(uint8_t), 1, myfile) == 1){
		pixels[index++] = x;	
	}
	fclose(myfile);
	return 0;
}