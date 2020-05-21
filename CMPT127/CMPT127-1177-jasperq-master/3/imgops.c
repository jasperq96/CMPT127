/*
 * imageops.c - Simple operations on images
 *
 * C laboratory exercises.
 * Richard Vaughan, 2014.
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* PAIR SECTION BEGINS - WORK WITH YOUR PARTNER ON THESE TASKS */

/*-------------------------------------------------
  PART 0: DEMONSTRATION
*/


// get the value in the array at coordinate (x,y)
uint8_t get_pixel(const uint8_t array[], unsigned int cols, unsigned int rows, unsigned int x, unsigned int y){
    assert( x < cols );
    assert( y < rows );
    return array[ y * cols + x ];
}

// set the pixel at coordinate {x,y} to the specified color
void set_pixel(uint8_t array[], unsigned int cols, unsigned int rows, unsigned int x, unsigned int y, uint8_t color){
    assert( x < cols );
    assert( y < rows );
    array[ y * cols + x ] = color;
} 

// Set every pixel to 0 (black) 
void zero(uint8_t array[], unsigned int cols, unsigned int rows){
  // your code here.
	memset(array, 0, cols * rows * sizeof(array[0]));
}

// Returns a pointer to a freshly allocated array that contains the
// same values as the original array, or a null pointer if the
// allocation fails. The caller is responsible for freeing the array
// later.
uint8_t* copy(const uint8_t array[], unsigned int cols, unsigned int rows){
  // your code here
	//iniialize my new array
	uint8_t * new_array;
	new_array = malloc(cols * rows * sizeof(uint8_t)); // allocates memory for my 1-D array
	int success = 1;
	for (int x = 0; x < (cols*rows*sizeof(uint8_t)); x++){
		new_array[x] = array[x];
	}
	//checks if the arrays are the same
	for (int x = 0; x < (cols*rows*sizeof(uint8_t)); x++){
		if (new_array[x] != array[x])
			success = 0;	
	}

	if (success == 0){
		return NULL;
	}
	else{
		return new_array;
	}
}



/*-------------------------------------------------
  PART 1: OPERATIONS ON THE WHOLE IMAGE 
*/

/* TASK 1 - three easy functions to get started */

// Return the darkest color that appears in the array; i.e. the smallest value
uint8_t min( const uint8_t array[], unsigned int cols, unsigned int rows ){
  // your code here
	int smallest = array[0];
	for(int x = 1; x < (cols*rows*sizeof(array[0]))-1; x++){
		if (smallest > array[x]){
			smallest = array[x];
		}
	}
  return smallest;
}

// Return the lightest color that appears in the array; i.e. the largest value
uint8_t max( const uint8_t array[], unsigned int cols, unsigned int rows )
{
	int largest = array[0];
	for(int x = 1; x < (cols*rows*sizeof(array[0]))-1; x++){
		if (largest < array[x]){
			largest = array[x];
		}
	}
  return largest;
}

// TASK 2

//  Replace every instance of pre_color with post_color.
void replace_color(  uint8_t array[], unsigned int cols, unsigned int rows, uint8_t pre_color, uint8_t post_color ){
  // your code here
	for (int x = 0; x < (cols*rows*sizeof(array[0]))-1;x++){
		if(array[x] == pre_color){
			array[x] = post_color;
		}
	}
}

/* TASK 3  - two functions */


// flip the image, left-to-right, like in a mirror.
void flip_horizontal( uint8_t array[], unsigned int cols, unsigned int rows ){
  // your code here
	unsigned int x = 1;
	unsigned int temp;

	while (x <= rows){
		unsigned int point_one = (cols*x)-cols;
		unsigned int point_two = (cols*x)-1;	
		while (point_one < point_two){
			temp = array[point_one];
			array[point_one] = array[point_two];
			array[point_two] = temp;
			point_one++;
			point_two--;	
		}
		x++;
	}
}

// flip the image top-to-bottom.
void flip_vertical( uint8_t array[], unsigned int cols, unsigned int rows ){
    // your code here
	unsigned int top = 1;
	unsigned int bottom = rows;
	unsigned int current_cols = 0;
	unsigned int temp;

	while (current_cols < cols){
		unsigned int point_one = (cols*top) - cols + current_cols;
		unsigned int point_two = (cols*bottom) - cols + current_cols;
		while (point_one < point_two){
			temp = array[point_one];
			array[point_one] = array[point_two];
			array[point_two] = temp;
			point_one += cols;
			point_two -= cols;	
		}
		current_cols++;
	}
}

/* TASK 4 */

// Find the first coordinate of the first pixel with a value that
// equals color. Search from left-to-right, top-to-bottom. If it is
// found, store the coordinates in *x and *y and return 1. If it is
// not found, return 0.
int locate_color(  const uint8_t array[], unsigned int cols, unsigned int rows, uint8_t color, unsigned int *x, unsigned int *y ){
    // your code here
	for (int n = 0; n < (cols * rows * sizeof(array[0])); n++){
		if (array[n] == color){
			*x = n % (cols*sizeof(array[0]));
			*y = floor(n / (cols*sizeof(array[0])));
			return 1;
		}
	}
    return 0;
}


/* TASK 5 */

// Invert the image, so that black becomes white and vice versa, and
// light shades of grey become the corresponding dark shade. 
void invert( uint8_t array[], unsigned int cols, unsigned int rows ){
    // your code here
    for (unsigned int x = 0; x < (cols*rows*sizeof(array[0])); x++){
   		if ((array[x]-255) < 0){
   			array[x] = 0-(array[x]-255);
   		}
   		else{
   			array[x] -= 255;
   		}
   	}
}

/* TASK 6 */

// Multiply every pixel by scale_factor, in order to brighten or
// darken the image. Any resulting value over 255 is
// thresholded to 255.
void scale_brightness( uint8_t array[], unsigned int cols, unsigned int rows, double scale_factor ){
  // your code here
	for (unsigned int x = 0; x < (cols*rows*sizeof(array[0])); x++){
		if((array[x]*scale_factor) > 255){
			array[x] = 255;
		}
		else{
			array[x] = round(array[x]*scale_factor);
		}
	}
}


/* TASK 7 */

// Normalize the dynamic range of the image, i.e. Shift and scale the
// pixel colors so that that darkest pixel is 0 and the lightest pixel
// is 255. Hint: you already wrote min() and max(). 
void normalize( uint8_t array[], unsigned int cols, unsigned int rows ){
    // your code here
    float smallest = array[0];
    float largest = array[0];
	float normalized;
    for (int x = 0 ; x < (cols*rows*sizeof(array[0])) ; x++){
    	if (smallest > array[x]){
    		smallest = array[x];
    	}
    	if (largest < array[x]){
    		largest = array[x];
    	}
    }

    largest -= smallest;

    for (int y = 0 ; y < (cols*rows*sizeof(array[0])) ; y++){
    	normalized = ((array[y]-smallest)*255)/largest;
    	array[y] = round(normalized);
    }
}

/* TASK 8 */

// Return a new image of size rows/2 by cols/2 If the original image              
// has an odd number of columns, ignore its rightmost column. If the              
// original image has an odd number of rows, ignore its bottom row.               
// The value of a pixel at (p,q) in the new image is the average of               
// the four pixels at (2p,2q), (2p+1,2q), (2p+1,2q+1), (2p,2q+1) in               
// the original image.                                                            
uint8_t* half( const uint8_t array[], unsigned int cols, unsigned int rows ){
    // your code here
    unsigned int newCols = cols / 2;
    unsigned int newRows = rows / 2;
	uint8_t *half_array = malloc(newRows* newCols * sizeof(uint8_t));

	if (cols % 2 != 0) {
		cols -= 1;
	}
	if (rows % 2 != 0) {
		rows -= 1;
	}
	
	if (half_array != 0) {
		for (int x = 0; x < cols; x += 2) {
			for (int n = 0; n < rows; n += 2) {
				float color = round((get_pixel(array, cols, rows, x, n) + get_pixel(array, cols, rows, x, n + 1) + get_pixel(array, cols, rows, x + 1, n) + get_pixel(array, cols, rows, x + 1, n + 1))/ 4.00);
				set_pixel(half_array, newCols, newRows, x / 2, n / 2, color);
			}
		}
		return half_array;
	}

	else {
		return NULL;
	}
}




/*-------------------------------------------------
  PART 2: OPERATIONS ON IMAGE SUB-REGIONS

  These functions operate only on a rectangular region of the array
  defined by a (left,top) corner (i.e. closer to the image origin) and
  (right,bottom) corner (i.e. further from the image origin).

  The region includes all the columns from [left, right-1] inclusive,
  and all the rows from [top, bottom-1] inclusive.
  
  In every case, you may assume that left <= right and top <= bottom:
  do not need to test for this.

  The area of the region is (right-left) * (bottom-top) pixels, which
  implies that if left == right or top == bottom, the region has no
  area and is defined as "empty". Each function notes how to handle
  empty regions.
 
  In every function, use assert() to test bounds on the region
  corners.
*/

/* TASK 9 */

// Set every pixel in the region to color. If the region is empty, the
// image must be unchanged.
void region_set( uint8_t array[], unsigned int cols, unsigned int rows, unsigned int left, unsigned int top, unsigned int right, unsigned int bottom, uint8_t color ){
    // your code here
    if((top != bottom) && (left != right)){
	    for (int x = left; x < right; x++){
	    	for (int y = top; y < bottom; y++){
	    		set_pixel(array, cols, rows, x, y, color);
	    	}
	    }
	}
}

/* TASK 10 */

// Return the sum of all the pixels in the region. Notice the large
// return type to handle potentially large numbers. Empty regions
// return the sum 0.
unsigned long int region_integrate( const uint8_t array[], unsigned int cols, unsigned int rows, unsigned int left, unsigned int top, unsigned int right, unsigned int bottom ){
    // your code here
    if ((top == bottom) || left == right){
    	return 0;
    }
    else{
    	unsigned long int sum = 0;
    	for (int x = left; x < right; x++){
    		for (int y = top; y < bottom; y++){
    			sum += get_pixel(array, cols, rows, x, y);
    		}
    	}
    	return sum;
    }
}

/* TASK 11 */

// Get a new image which is a copy of the region. Empty regions return
// a null pointer. If memory allocation fails, return a null
// pointer. The caller is responsible for freeing the returned array
// later.
uint8_t* region_copy( const uint8_t array[], unsigned int cols, unsigned int rows, unsigned int left, unsigned int top, unsigned int right, unsigned int bottom){
    // your code here
    unsigned int region_cols = right - left;
    unsigned int region_rows = bottom - top;
    unsigned int color;
    unsigned int n = 0, m = 0;
    uint8_t * regionCopy = malloc (region_cols * region_rows * sizeof(uint8_t));

    if ((regionCopy != 0) && ((top != bottom) && (left != right))){
	    for (int x = left; x < right; x++){
	    	for (int y = top; y < bottom; y++){								// because we are going pixel by pixel starting from the first column and moving down
	    		color = get_pixel(array, cols, rows, x, y);					// only changing columns when all rows are finished, we increment our set_pixel by m++
	    		set_pixel(regionCopy, region_cols, region_rows, n, m, color); // instead of n++ in the inner "for-loop", then reset m since we want to start at the 
	    		m++;														// top row again in the next column
	    	}
	    	m = 0;
	    	n++;
	    }
		return regionCopy;
	}
    return NULL;
}


