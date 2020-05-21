#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void list_merge(list_t * list1, list_t * list2) {
    if (list2->head != NULL) {
    	if (list1->head == NULL) {
            *list1 = *list2;
    	} 
        else {
       		list1->tail->next = list2->head;
        	list1->tail= list2->tail;
    	}
    free(list2);
    }
}




void list_sort(list_t * list) {
    if (list->head != list->tail){

    element_t * pivot = list->head;
    list->head = list->head->next;

    list_t * smaller = list_create();
    list_t * larger = list_create();
    
    element_t * current = list->head;
    element_t * next;

    while (current != NULL) {
        next = current->next;
        current->next = NULL;
        if (current->val <= pivot->val) {
            list_append(smaller, current->val);
        } 
        else {
            list_append(larger, current->val);
        }
        current = next;
    }

    list->head = NULL;
    list->tail = NULL;

    list_sort(smaller);
    list_sort(larger);

    list_merge(list, smaller);
    list_append(list, pivot->val);
    list_merge(list, larger);
    }
    else{
        return;
    }
}