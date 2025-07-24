//FormAI DATASET v1.0 Category: Memory management ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int* ptr;
    int i, sum = 0;

    // Allocating memory dynamically for ptr
    ptr = (int*)malloc(5 * sizeof(int));

    // Checking if memory has been allocated successfully or not
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        exit(0);
    }

    // Initializing values of ptr
    *ptr = 10;
    *(ptr + 1) = 20;
    *(ptr + 2) = 30;
    *(ptr + 3) = 40;
    *(ptr + 4) = 50;

    // Calculating sum of all the numbers
    for (i = 0; i < 5; i++) {
        sum += *(ptr + i);
    }

    printf("Sum of all the numbers: %d\n", sum);

    // Deallocating memory
    free(ptr);

    return 0;
}