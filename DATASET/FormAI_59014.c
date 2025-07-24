//FormAI DATASET v1.0 Category: Memory management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

int main() {
    // allocating memory for integer variable
    int *ptr = (int*) malloc(sizeof(int));
    
    if(ptr == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }
    
    *ptr = 10;
    
    printf("Value of ptr: %d\n", *ptr);
    
    // reallocation of memory for integer variable
    int *new_ptr = (int*) realloc(ptr, sizeof(int)*2);
    
    if (new_ptr == NULL) {
        printf("Reallocation of memory failed.");
        return 1;
    }
    
    ptr = new_ptr;
    
    *(ptr+1) = 20;
    
    printf("Value of ptr: %d\n", *ptr);
    printf("Value of ptr+1: %d\n", *(ptr+1));
    
    // deallocating memory
    free(ptr);
    
    return 0;
}