//FormAI DATASET v1.0 Category: Memory management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int main() {
    // initialize pointers
    int *ptr1, *ptr2, *ptr3;

    // allocate memory for ptr1 using malloc
    ptr1 = (int *) malloc(sizeof(int) * 5);
    if(ptr1 == NULL) {
        printf("Memory allocation failed for ptr1.");
    } else {
        printf("Memory allocation successful for ptr1.\n");
    }

    // allocate memory for ptr2 using calloc
    ptr2 = (int *) calloc(5, sizeof(int));
    if(ptr2 == NULL) {
        printf("Memory allocation failed for ptr2.");
    } else {
        printf("Memory allocation successful for ptr2.\n");
    }

    // reallocate memory for ptr1 using realloc
    ptr3 = (int *) realloc(ptr1, sizeof(int) * 10);
    if(ptr3 == NULL) {
        printf("Memory reallocation failed for ptr1.");
    } else {
        // update the value of pointer
        ptr1 = ptr3;
        printf("Memory reallocation successful for ptr1.\n");
    }

    // free the allocated memory
    free(ptr1);
    free(ptr2);

    return 0;
}