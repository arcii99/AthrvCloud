//FormAI DATASET v1.0 Category: Memory management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr, *ptr1, *ptr2, *ptr3;

    // dynamic memory allocation
    ptr = (int*)malloc(5*sizeof(int));

    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        exit(0);
    }

    // assign values to allocated memory
    for (int i=0; i<5; i++) {
        *(ptr + i) = i+1;
    }

    printf("Allocated memory: ");
    for (int i=0; i<5; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    // reallocate memory
    ptr1 = (int*)realloc(ptr, 10*sizeof(int));
    if (ptr1 != NULL) {
        ptr = ptr1;
    } else {
        printf("Memory reallocation failed.\n");
        exit(0);
    }

    // assign values to reallocated memory
    for (int i=5; i<10; i++) {
        *(ptr + i) = i+1;
    }

    printf("Reallocated memory: ");
    for (int i=0; i<10; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    // calloc demo
    ptr2 = (int*)calloc(5, sizeof(int));
    if (ptr2 == NULL) {
        printf("Memory allocation failed.\n");
        exit(0);
    }

    printf("Calloc memory: ");
    for (int i=0; i<5; i++) {
        printf("%d ", *(ptr2 + i));
    }
    printf("\n");

    // free memory
    free(ptr);
    free(ptr2);

    // arithmetics with pointers
    ptr3 = (int*)malloc(5*sizeof(int));
    if (ptr3 == NULL) {
        printf("Memory allocation failed.\n");
        exit(0);
    }

    // access elements with pointer arithmetic
    *ptr3 = 10; *(ptr3 + 1) = 20; *(ptr3 + 2) = 30; *(ptr3 + 3) = 40; *(ptr3 + 4) = 50;

    printf("Pointer arithmetic: ");
    for (int i=0; i<5; i++) {
        printf("%d ", *(ptr3 + i));
    }
    printf("\n");

    // accessing the end of the allocated memory block
    ptr3 = ptr3 + 4;

    printf("End of allocated memory block: %p\n", ptr3);

    free(ptr3);

    return 0;
}