#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main( int argc, char* argv[] ){
  // test the create function
  list_t* list = list_create();

  // check to see if the create function did everything it was supposed to
  if( list == NULL ){
    return 1;
  }

  if( list->head != NULL ){
    return 1;
  }

  if( list->tail != NULL ){
    return 1;
  }

  // now test all the other functions (except list_print) to see if they do what they are supposed to

  // you code goes here

  /////////////////////////////Testing list_index() in t1.c////////////////////////////////////////
  /*
  missing the top check to see if the list is empty
  */

  list_t* list2 = list_create();
  element_t* test = list_index(list2, 1);
  if(test != NULL){
    return 1;
  }
  free(list2);

  /////////////////////////////Testing element_create() in t2.c////////////////////////////////////
  /*
  Element_create() doesn't initialize a new element next to NULL
  */
  element_t* test2 = element_create(1);
  element_t* test3 = element_create(2);
  test2->next = test3;
  free(test2);
  test2 = element_create(3);
  if(test2->next != NULL){
    return 1;
  }
  /////////////////////////////Testing list_index() in t3.c////////////////////////////////////////
  /*
  The variable that is returned in the function starts at the node next to the head, meaning that 
  if i wanted the first node of the LL, it would actually be the second node
  */
  list_t* list3 = list_create();
  list_append(list3, 1);
  list_append(list3, 2);
  element_t* test4 = list_index(list3, 0);
  if(test4->val != 1){
    return 1;
  }
  free(list3);

  /////////////////////////////Testing list_prepend() in t4.c//////////////////////////////////////
  /*
  Completely misses the reassignment of tail if the list is NULL
  */
  list_t* list4 = list_create();
  list_prepend(list4,1);
  if(list4->tail == NULL){
    return 1;
  }
  free(list4);

  /////////////////////////////Testing list_index() in t5.c////////////////////////////////////////
  /*
  Missing the el->next == NULL statement that would return NULL right away if the next index is 
  non-existent
  */

  list_t* list5 = list_create();
  list_prepend(list5,1);
  element_t* test5 = list_index(list5, 10);
  if(test5 != NULL){
    return 1;
  }
  free(list5);

  /////////////////////////////////////////////////////////////////////////////////////////////////
  return 0; // tests pass
}