//FormAI DATASET v1.0 Category: Memory management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* ptr1 = (int*) malloc(sizeof(int));
    *ptr1 = 10;
    printf("Value stored at ptr1: %d\n", *ptr1);

    int* ptr2 = (int*) malloc(sizeof(int));
    *ptr2 = 20;
    printf("Value stored at ptr2: %d\n", *ptr2);

    printf("Addresses of ptr1 and ptr2: %p, %p\n", ptr1, ptr2);

    int* ptr3 = (int*) calloc(3, sizeof(int));
    printf("Address of ptr3: %p\n", ptr3);
    ptr3[0] = 30;
    ptr3[1] = 40;
    ptr3[2] = 50;

    printf("Values stored in ptr3: %d, %d, %d\n", ptr3[0], ptr3[1], ptr3[2]);

    ptr3 = (int*) realloc(ptr3, 4 * sizeof(int));
    ptr3[3] = 60;
    printf("Values stored in ptr3 after realloc: %d, %d, %d, %d\n", ptr3[0], ptr3[1], ptr3[2], ptr3[3]);

    free(ptr1);
    free(ptr2);
    free(ptr3);
    printf("Memory freed successfully.\n");

    return 0;
}