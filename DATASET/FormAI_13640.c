//FormAI DATASET v1.0 Category: Memory management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

void* memoryAllocation(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("Allocated %zu bytes of memory at address: %p\n", size, ptr);
    return ptr;
}

void memoryDeallocation(void* ptr) {
    if (ptr == NULL) {
        printf("Can not free NULL pointer.\n");
        return;
    }
    printf("Deallocated memory at address: %p\n", ptr);
    free(ptr);
}

int main() {
    int* ptr1 = (int*) memoryAllocation(sizeof(int));
    *ptr1 = 10;
    printf("value of ptr1: %d\n", *ptr1);

    double* ptr2 = (double*) memoryAllocation(sizeof(double));
    *ptr2 = 3.14;
    printf("value of ptr2: %.2lf\n", *ptr2);

    // reallocation of memory
    ptr1 = (int*) realloc(ptr1, 2 * sizeof(int));
    if (ptr1 == NULL) {
        printf("Reallocation of memory failed.\n");
        exit(1);
    }
    printf("Reallocated memory at address: %p\n", ptr1);
    *(ptr1+1) = 20;
    printf("value of ptr1[1]: %d\n", *(ptr1+1));

    memoryDeallocation(ptr1);
    memoryDeallocation(ptr2);

    return 0;
}