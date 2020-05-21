#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "intarr.h"

/* -------------------------------------------------------------- */

/* LAB 6 TASK 1 */

/*
  Save the entire array ia into a file called 'filename' in a binary
  file format that can be loaded by intarr_load_binary(). Returns
  zero on success, or a non-zero error code on failure. Arrays of
  length 0 should produce an output file containing an empty array.
*/
int intarr_save_binary( intarr_t* ia, const char* filename ){
	if(ia != NULL){
		FILE * myfile = fopen(filename, "w");
		if(myfile != NULL){
			fwrite(&ia->len, sizeof(int), 1, myfile);
			int fileLength = fwrite(ia->data, sizeof(int), ia->len, myfile);
			if (fileLength == ia->len){
				fclose(myfile);
				return 0;
			}
			else{
				return 1;
			}
		}
		return 1;
	}
	return 1;
}


/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_binary(). Returns a pointer to a
  newly-allocated intarr_t on success, or NULL on failure.
*/
intarr_t* intarr_load_binary( const char* filename ){
	if(filename != NULL){
		FILE * myfile = fopen(filename, "r");
		if(myfile != NULL){
			int len;
			int index = 0;
			int x;
			if(fread(&len, sizeof(int), 1, myfile) != 1){
				return NULL;
			}
			else if (len >= 0){
				intarr_t * new = intarr_create(len);
				while(fread(&x, sizeof(int), 1, myfile) == 1){
					new->data[index++] = x;
				}
				fclose(myfile);
				return new;
			}
		}
		return NULL;
	}
	return NULL;
}