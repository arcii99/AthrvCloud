//FormAI DATASET v1.0 Category: Memory management ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>

int main(){

    int *ptr1 = NULL, *ptr2 = NULL, *ptr3 = NULL;

    // Allocating 30 integers
    ptr1 = (int*) malloc(10 * sizeof(int));
    ptr2 = (int*) malloc(10 * sizeof(int));
    ptr3 = (int*) malloc(10 * sizeof(int));

    // Check if the memory is allocated or not
    if(ptr1 == NULL || ptr2 == NULL || ptr3 == NULL){
        printf("Memory allocation failed\n");
        exit(0);
    }
    else{
        printf("Memory allocation successful\n");
    }

    // Freeing memory pointed by ptr1
    free(ptr1);
    ptr1 = NULL;

    //Reallocating more memory for ptr2
    ptr2 = (int*) realloc(ptr2, 15 * sizeof(int));

    if(ptr2 == NULL){
        printf("Memory reallocation failed\n");
        exit(0);
    }
    else{
        printf("Memory reallocation successful\n");
    }

    //Freeing memory pointed by ptr2 and ptr3
    free(ptr2);
    free(ptr3);

    return 0;
}