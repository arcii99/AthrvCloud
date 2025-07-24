//FormAI DATASET v1.0 Category: Memory management ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Welcome to the memory management example program!
// Get ready to learn how to use malloc and free like a pro!

int main() {
    // Let's start off by declaring our first pointer
    int* ptr1;

    // And assigning it some memory with malloc
    ptr1 = malloc(10 * sizeof(int));

    // Oops, we forgot to check if the memory allocation was successful!
    // Let's add a check to make sure we get a valid pointer
    if (ptr1 == NULL) {
        printf("Memory allocation failed, please try again!\n");
        return -1;
    }

    // Great! We got a valid pointer. Now let's assign some numbers to it
    for (int i = 0; i < 10; i++) {
        ptr1[i] = i * 2;
    }

    // Let's print out our array
    printf("Array 1 contents:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", ptr1[i]);
    }
    printf("\n");

    // Now, let's create another pointer and allocate some memory for it
    int* ptr2 = malloc(5 * sizeof(int));

    // Again, let's check if the memory allocation was successful
    if (ptr2 == NULL) {
        printf("Memory allocation failed, please try again!\n");
        // We forgot to free the first allocation, better do it now
        free(ptr1);
        return -1;
    }

    // Great! Allocation successful. Let's assign some numbers to this one too
    for (int i = 0; i < 5; i++) {
        ptr2[i] = i * 3;
    }

    // Let's print out our second array
    printf("Array 2 contents:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr2[i]);
    }
    printf("\n");

    // Now let's add some more memory to our first array using realloc
    int* ptr3 = realloc(ptr1, 15 * sizeof(int));

    // We need to check the return value of realloc as well
    if (ptr3 == NULL) {
        printf("Memory allocation failed, please try again!\n");
        free(ptr1);
        free(ptr2);
        return -1;
    }

    // Great! The reallocation was successful.
    // Got some extra memory, let's use it
    for (int i = 10; i < 15; i++) {
        ptr3[i] = i * 4;
    }

    // Let's print out our modified first array
    printf("Array 1 modified contents:\n");
    for (int i = 0; i < 15; i++) {
        printf("%d ", ptr3[i]);
    }
    printf("\n");

    // We're done with our arrays, let's free the memory
    free(ptr3);
    free(ptr2);

    // Yay! We're done. Time to celebrate!
    printf("Good job, you're a memory management pro now!\n");

    return 0;
}