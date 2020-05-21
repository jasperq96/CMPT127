#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "imgops.h"

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

void draw_rectangle( uint8_t array[], unsigned int cols, unsigned int rows, int x, int y, int rect_width, int rect_height, uint8_t color){
	int compare_x = x + rect_width;
	int compare_y = y + rect_height;
	int startx, endx, starty, endy;

	startx = MIN(x,compare_x);
	starty = MIN(y,compare_y);
	endx = MAX(x,compare_x);
	endy = MAX(y,compare_y);

	if ((startx == compare_x) && (starty == compare_y)){
		startx ++;
		starty ++;
		endx ++;
		endy ++;
	}
	else if ((startx == compare_x) && (starty == y)){
		startx ++;
		endx ++;
	}
	else if ((startx == x) && (starty == compare_y)){
		starty ++;
		endy ++;
	}

	if (rect_height != 0 && rect_width != 0){
		for (int a = startx; a < endx; a++){
			for (int b = starty; b < endy; b++){
				if((a >= 0) && (a < cols)){ 							//needs to be a < cols or b < rows for asserts in set_pixel
					if((b >= 0) && (b < rows)){
						if((a == startx) || (a == endx-1)){
							set_pixel(array , cols, rows, a, b, color);
						}
						else if((b == starty) || (b == endy-1)){
							set_pixel(array, cols, rows, a, b, color);
						}
					}
				}
			}
		}
	}

}