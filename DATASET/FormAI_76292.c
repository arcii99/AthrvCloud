//FormAI DATASET v1.0 Category: Memory management ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

void *my_malloc(int size);
void my_free(void *ptr);

int main() {
    int *ptr_one;
    float *ptr_two;

    // allocate memory for ptr_one
    ptr_one = (int*)my_malloc(sizeof(int));
    if (ptr_one == NULL) {
        printf("Error: could not allocate memory for ptr_one");
        return -1;
    }
    *ptr_one = 10;

    // allocate memory for ptr_two
    ptr_two = (float*)my_malloc(sizeof(float));
    if (ptr_two == NULL) {
        printf("Error: could not allocate memory for ptr_two");
        return -1;
    }
    *ptr_two = 3.14;

    printf("Value of ptr_one: %d\n", *ptr_one);
    printf("Value of ptr_two: %f\n", *ptr_two);

    // free memory allocated for ptr_one and ptr_two
    my_free(ptr_one);
    my_free(ptr_two);

    return 0;
}

// custom memory allocation function
void *my_malloc(int size) {
    void *ptr = malloc(size);
    if (ptr != NULL) {
        printf("Allocated %d bytes at memory address %p\n", size, ptr);
    }
    return ptr;
}

// custom memory deallocation function
void my_free(void *ptr) {
    free(ptr);
    printf("Memory at address %p has been freed\n", ptr);
}