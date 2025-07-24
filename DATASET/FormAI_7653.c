//FormAI DATASET v1.0 Category: Memory management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr1, *ptr2, *ptr3;
    // allocate space for ptr1 with malloc
    ptr1 = (int*) malloc(sizeof(int));
    if (ptr1 == NULL) {
        printf("Error: could not allocate memory with malloc.\n");
        exit(1);
    }
    *ptr1 = 5;
    printf("Value of ptr1 is %d\n", *ptr1);
    
    // allocate space for ptr2 and ptr3 with calloc
    ptr2 = (int*) calloc(3, sizeof(int));
    if (ptr2 == NULL) {
        printf("Error: could not allocate memory with calloc.\n");
        exit(1);
    }
    printf("Values of ptr2 are %d, %d, %d\n", ptr2[0], ptr2[1], ptr2[2]);
    
    ptr3 = (int*) calloc(5, sizeof(int));
    if (ptr3 == NULL) {
        printf("Error: could not allocate memory with calloc.\n");
        exit(1);
    }
    for (int i = 0; i < 5; i++) {
        ptr3[i] = i*10;
    }
    printf("Values of ptr3 are %d, %d, %d, %d, %d\n", ptr3[0], ptr3[1], ptr3[2], ptr3[3], ptr3[4]);
    
    // reallocate space for ptr1 with realloc
    ptr1 = (int*) realloc(ptr1, 2*sizeof(int));
    if (ptr1 == NULL) {
        printf("Error: could not allocate memory with realloc.\n");
        exit(1);
    }
    ptr1[1] = 10;
    printf("Values of ptr1 are %d, %d\n", ptr1[0], ptr1[1]);
    
    // free allocated memory
    free(ptr1);
    free(ptr2);
    free(ptr3);
    
    return 0;
}