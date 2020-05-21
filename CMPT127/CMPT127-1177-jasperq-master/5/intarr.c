#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
  int* data;
  unsigned int len;
} intarr_t;


typedef enum {
  INTARR_OK,
  INTARR_BADARRAY,
  INTARR_BADINDEX,
  INTARR_BADALLOC,
  INTARR_NOTFOUND
} intarr_result_t;


/* LAB 5 TASK 1 */

intarr_t* intarr_create( unsigned int len ){
	intarr_t * new = malloc(sizeof(intarr_t));
	if (new){
		new -> data = malloc(len*sizeof(int));
		if (new -> data){
			new -> len = len;
		}
		else{
			free(new);
		}
	}
	return new;
}

void intarr_destroy( intarr_t* ia ){
	if(ia != NULL){
		if(ia->data != NULL){
			free(ia->data);
		}
	}
}

/* LAB 5 TASK 2 */

intarr_result_t intarr_set( intarr_t* ia,  unsigned int index, int val ){
	if (ia == NULL){
		return INTARR_BADARRAY;
	}
	if ((index >= 0) && (index < ia->len)){
		ia -> data[index] = val;
		return INTARR_OK;
	}
	else if ((index < 0) || (index >= ia->len)){
		return INTARR_BADINDEX;
	}
}

intarr_result_t intarr_get( const intarr_t* ia, unsigned int index, int* i ){
	if (ia == NULL){
		return INTARR_BADARRAY;
	}
	if ((index >= 0) && (index < ia->len) && (i != NULL)) {
		*i = ia->data[index];
		return INTARR_OK;
	}
	else{
		return INTARR_BADINDEX;
	}
}

/* LAB 5 TASK 3 */

intarr_t* intarr_copy( const intarr_t* ia ){
	intarr_t * duplicate;
	duplicate = malloc(sizeof(intarr_t));

	if (ia != NULL){
		duplicate->data = malloc(ia->len * sizeof(int));
		if(duplicate->data == NULL){
			free(duplicate);
			return NULL;
		}
		else{
			memcpy(duplicate->data, ia->data, ia->len * sizeof(int));
			duplicate->len = ia->len;
			return duplicate;
		}
	}
	return NULL;
}

/* LAB 5 TASK 4 */

intarr_result_t intarr_sort( intarr_t* ia ){
	if (ia != NULL){
		for (int x = 1; x < ia->len; x++){
			int compare = ia->data[x];
			int n = x-1;
			while((n >= 0) && ia->data[n] > compare){
				ia->data[n+1] = ia->data[n];
				n--;
			}
			ia->data[n+1] = compare;
		}
		return INTARR_OK;
	}
	return INTARR_BADARRAY;
}

/* LAB 5 TASK 5 */

intarr_result_t intarr_find( intarr_t* ia, int target, int* i ){
	if (ia != NULL){
		if (i != NULL){
			for (int x = 0; x < ia->len; x++){
				if (ia->data[x] == target){
					*i = x;
					return INTARR_OK;
				}
			}
			return INTARR_NOTFOUND;
		}
	}
	return INTARR_BADARRAY;
}

/* LAB 5 TASK 6 */

intarr_result_t intarr_push( intarr_t* ia, int val ){
	if (ia != NULL){
		ia->data = realloc(ia->data, (ia->len+1) * sizeof(int)); //realloc(void * ptr, size) reallocates memory that was previously allocated using malloc for said pointer with said size
		ia->len++;
		ia->data[ia->len-1] = val;
		if (ia->data != NULL){
			return INTARR_OK;
		}
		else{
			return INTARR_BADALLOC;
		}
	}
	return INTARR_BADARRAY;
}

intarr_result_t intarr_pop( intarr_t* ia, int* i ){
	if (ia != NULL){
		if( ia->data != NULL){
			if (i != NULL){
				*i = ia->data[ia->len-1];
				ia->data = realloc(ia->data, (ia->len-1) * sizeof(int));
				ia->len--;
				return INTARR_OK;
			}

		}
		return INTARR_BADINDEX;
	}
	return INTARR_BADARRAY;
}

/* LAB 5 TASK 7 */

intarr_result_t intarr_resize( intarr_t* ia, unsigned int newlen ){
	if (ia != NULL){
		if (newlen < ia->len){
			ia->data = realloc(ia->data, newlen * sizeof(int));
			ia->len = newlen;
		}
		if (newlen > ia->len){
			ia->data = realloc(ia->data, newlen * sizeof(int));
			int oldlen = ia->len;
			ia->len = newlen;
			memset(ia->data, 0, (newlen - oldlen) * sizeof(int));
		}
		if (ia->data != NULL){
			return INTARR_OK;
		}
		else{
			return INTARR_BADALLOC;
		}
	}
	return INTARR_BADARRAY;
}

/* LAB 5 TASK 8 */

intarr_t* intarr_copy_subarray( intarr_t* ia, unsigned int first, unsigned int last ){
	if ((ia == NULL) || (first < 0) || (last < first) || (last > (ia->len-1))){
		return NULL;
	}
	else{
		intarr_t * copy = malloc(sizeof(intarr_t));
		if (copy != NULL){
			copy->data = malloc( ((last-first)+1) * sizeof(int));
			if(copy->data != NULL){
				int index = 0;
				for (int x = first; x <= last; ++x){
					copy->data[index++] = ia->data[x];
				}
				copy->len = last - first + 1;
				return copy;
			}
			free(copy);
			return NULL;
		}
		return NULL;
	}
}






/* -------------------------------------------------------------- */

/* LAB 6 TASK 1 */

/*
  Save the entire array ia into a file called 'filename' in a binary
  file format that can be loaded by intarr_load_binary(). Returns
  zero on success, or a non-zero error code on failure. Arrays of
  length 0 should produce an output file containing an empty array.
*/
int intarr_save_binary( intarr_t* ia, const char* filename );

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_binary(). Returns a pointer to a
  newly-allocated intarr_t on success, or NULL on failure.
*/
intarr_t* intarr_load_binary( const char* filename );


/* LAB 6 TASK 2 */

/*
  Save the entire array ia into a file called 'filename' in a JSON
  text file array file format that can be loaded by
  intarr_load_json(). Returns zero on success, or a non-zero error
  code on failure. Arrays of length 0 should produce an output file
  containing an empty array.
  
  The JSON output should be human-readable.

  Examples:

  The following line is a valid JSON array:
  [ 100, 200, 300 ]
  
  The following lines are a valid JSON array:
  [ 
   100, 
   200, 
   300 
  ]
*/
int intarr_save_json( intarr_t* ia, const char* filename );

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save(). The file may contain an array
  of length 0. Returns a pointer to a newly-allocated intarr_t on
  success (even if that array has length 0), or NULL on failure.
*/
intarr_t* intarr_load_json( const char* filename );