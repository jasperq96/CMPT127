#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>



typedef struct point
{
  double x, y, z;
} point_t;



///////////////////////////////////////////////////////////////////////////
typedef struct 
{
  // number of points in the array
  size_t len;
  
  // pointer to an array of point_t structs
  // There is space for 'allocated' structs, but 
  // 'len' structs have been used so far.
  point_t * points;
  
  // to be discussed in class
  size_t reserved; 
  
} point_array_t;
////////////////////////////////////////////////////////////////////////////




/* ALL THESE FUNCTIONS REQUIRE A VALID POINT_ARRAY_T POINTER AS THEIR
   FIRST PARAMETER. THEY SHOULD FAIL ON ASSERTION IF THIS POINTER IS
   NULL */

/* TASK 1 */

// Safely initalize an empty array structure.
void point_array_init( point_array_t* pa ){
	assert(pa);
	pa->reserved = 2;
	pa->points = (point_t*)realloc(NULL, pa->reserved * sizeof(point_t));	//set pa->points to NULL, but change the memory space that point_t (which is really how much space NULL takes up) takes to pa->reserved * sizeof(point_t)
	pa->len = 0;
	
}

/* TASK 2 */

// Resets the array to be empty, freeing any memory allocated if
// necessary.
void point_array_reset( point_array_t* pa ){
	assert (pa);
	free(pa->points);
	pa->points = NULL;
	pa->len = 0;
	pa->reserved = 0;
}

/* TASK 3 */

// Append a point to the end of an array. If successful, return 0,
// else return 1;
int point_array_append( point_array_t* pa, point_t* p ){
	assert(pa);
	pa->points = realloc(pa->points, (pa->len+1)*sizeof(point_t));
	if(pa->points != NULL){
		pa->points[pa->len] = *p;
		pa->len++;
		return 0;
	}
	return 1;
}

/* TASK 4 */

// Remove the point at index i from the array, reducing the size of
// the array by one. The order of points in the array may change.
int point_array_remove( point_array_t* pa, unsigned int i ){
	assert(pa);
	if((pa->len != 0) && (i < pa->len)){
		pa->points[i] = pa->points[pa->len - 1];
		pa->len--;
		return 0;
	}
	return 1;
}