#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "intarr.h"


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
int intarr_save_json( intarr_t* ia, const char* filename ){
  if(ia != NULL){
    FILE * myfile = fopen(filename, "w");
    if (myfile){
      fprintf(myfile, "[ ");
      for(int x = 0; x < ia->len; ++x){
        if(x != ia->len-1){
          fprintf(myfile, "%d, ", ia->data[x]);
        }
        else{
          fprintf(myfile, "%d ", ia->data[x]);
        }

      }
    fprintf(myfile,"]");
    fclose(myfile);
    return 0;
    }

  }
  return 1;
}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save(). The file may contain an array
  of length 0. Returns a pointer to a newly-allocated intarr_t on
  success (even if that array has length 0), or NULL on failure.
*/
intarr_t* intarr_load_json( const char* filename ){
  if(filename != NULL){
    FILE * myfile = fopen(filename, "r");
    if (myfile != NULL){
      intarr_t * new = intarr_create(0);
      char nothing;
      fscanf(myfile, "%c", &nothing); //this gets rid of the "[" at the beginning of the file
      int value;
      while(fscanf(myfile, "%d, ", &value)){
        intarr_push(new, value);
      }
      if(fscanf(myfile, "%d ", &value)){
        intarr_push(new, value);
      }
      fclose(myfile);
      return new;
    }
  }
  return NULL;
}