//FormAI DATASET v1.0 Category: Memory management ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main() {

    int *ptr1, *ptr2, *ptr3, *ptr4;

    // Allocate memory for ptr1
    ptr1 = (int*) malloc(sizeof(int));
    *ptr1 = 5;

    // Allocate memory for ptr2
    ptr2 = (int*) calloc(3, sizeof(int));
    ptr2[0] = 1;
    ptr2[1] = 2;
    ptr2[2] = 3;

    // Allocate memory for ptr3
    ptr3 = (int*) malloc(sizeof(int));
    *ptr3 = 10;

    // Allocate memory for ptr4
    ptr4 = (int*) realloc(ptr2, 5 * sizeof(int));
    ptr4[3] = 4;
    ptr4[4] = 5;

    printf("ptr1: %d\n", *ptr1);
    printf("ptr2[0]: %d, ptr2[1]: %d, ptr2[2]: %d\n", ptr2[0], ptr2[1], ptr2[2]);
    printf("ptr3: %d\n", *ptr3);
    printf("ptr4[0]: %d, ptr4[1]: %d, ptr4[2]: %d\nptr4[3]: %d, ptr4[4]: %d\n", ptr4[0], ptr4[1], ptr4[2], ptr4[3], ptr4[4]);

    // Free pointers
    free(ptr1);
    free(ptr3);
    free(ptr4);

    return 0;
}