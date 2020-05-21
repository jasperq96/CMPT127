#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "imgops.h"

int check( uint8_t array[], int cols, int rows, int a, int b){
	int sum = 0;
	for( int x=-1; x<=1; x++ ){
		for( int y=-1; y<=1; y++ ){
			if( (x != 0) || (y != 0)){ 
				int checkx = (a+x+cols) % cols; 
				int checky = (b+y+rows) % rows; 
				if(get_pixel( array, cols, rows, checkx, checky ) > 0){
	  				sum++;
	  			}
	  		}
		}
  	}
  	return sum;
}

void life (uint8_t array[], unsigned int cols, unsigned int rows ){
	uint8_t * temp = copy(array, cols, rows);

	for (int x = 0; x < cols; x++){
		for (int y = 0; y < rows; y++){
			unsigned int count = check(temp, cols, rows, x, y);
			if (count > 3 || count < 2){
				set_pixel(array, cols, rows, x, y, 0);
			}
			else if(count == 3){
				set_pixel(array, cols, rows, x, y, 255);
			}
		}
	}
	free(temp);
}