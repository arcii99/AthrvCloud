//FormAI DATASET v1.0 Category: Memory management ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>

int main() {
    int *ptr;

    // Allocate memory dynamically using malloc()
    ptr = (int*)malloc(5*sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Store some values in the dynamically allocated memory
    for (int i=0; i<5; i++) {
        *(ptr+i) = i+1;
    }

    // Print the values stored in the memory
    printf("Values stored in the memory:\n");
    for (int i=0; i<5; i++) {
        printf("%d\n", *(ptr+i));
    }

    // Reallocate the memory using realloc(), to increase the size
    ptr = (int*)realloc(ptr, 10*sizeof(int));
    if (ptr == NULL) {
        printf("Memory reallocation failed\n");
        exit(1);
    }

    // Store some more values in the newly allocated memory
    for (int i=5; i<10; i++) {
        *(ptr+i) = i+1;
    }

    // Print all the values stored in the memory
    printf("New values stored in the memory:\n");
    for (int i=0; i<10; i++) {
        printf("%d\n", *(ptr+i));
    }

    // Free the dynamically allocated memory
    free(ptr);

    return 0;
}