//FormAI DATASET v1.0 Category: Memory management ; Style: safe
#include <stdio.h>
#include <stdlib.h>

void allocate(int** ptr){
    *ptr = (int*)malloc(sizeof(int));
    if(*ptr == NULL){
        printf("Memory allocation failed!");
        exit(EXIT_FAILURE);
    }
}

void release(int** ptr){
    free(*ptr);
    *ptr = NULL;
}

int main(){
    int* ptr = NULL;
    allocate(&ptr);
    *ptr = 10;
    printf("The value stored at the allocated memory location is %d.\n", *ptr);
    release(&ptr);
    if(ptr == NULL){
        printf("The memory has been released successfully.\n");
    } else{
        printf("Memory release failed.");
    }
    return 0;
}