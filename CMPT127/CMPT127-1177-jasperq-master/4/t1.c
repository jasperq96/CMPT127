#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "imgops.h"
#include "t1.h"

void draw_circle( uint8_t img[], unsigned int cols, unsigned int rows, int x, int y, int r, uint8_t color ){
	double a, b, c;

//draw_circle( img, 193,  96,  162,   -5,    8,   19 )

	if(r > 0){
		for (int n = 0; n < cols; n++){
			for (int m = 0; m < rows; m++){
				//Top left of circle
				a = n-x-.5;
				b = m-y-.5;
				c = sqrt(pow(a,2)+pow(b,2));
				if (c < r){
					set_pixel(img, cols, rows, n, m, color);
				}
				//Top right of circle
				a = n-x+.5;
				b = m-y-.5;
				c = sqrt(pow(a,2)+pow(b,2));
				if (c < r){
					set_pixel(img, cols, rows, n, m, color);
				}
				a = n-x+.5;
				b = m-y+.5;
				c = sqrt(pow(a,2)+pow(b,2));
				if (c < r){
					set_pixel(img, cols, rows, n, m, color);
				}
				//Bottom left of circle
				a = n-x-.5;
				b = m-y+.5;
				c = sqrt(pow(a,2)+pow(b,2));
				if (c < r){
					set_pixel(img, cols, rows, n, m, color);
				}
			}
		}
	}
}