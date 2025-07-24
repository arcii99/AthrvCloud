//FormAI DATASET v1.0 Category: Memory management ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Allocate 10 integers using malloc
    int* array_one = (int*) malloc(10 * sizeof(int));

    // Initialize the integers to consecutive numbers
    for(int i=0; i<10; i++) {
        array_one[i] = i+1;
    }

    // Print out the integers in array_one
    printf("Array One: ");
    for(int i=0; i<10; i++) {
        printf("%d ", array_one[i]);
    }
    printf("\n");

    // Reallocate the array to hold 5 integers
    int* array_two = (int*) realloc(array_one, 5 * sizeof(int));

    // Modify the first 5 integers in array_two
    for(int i=0; i<5; i++) {
        array_two[i] += 10;
    }

    // Print out the integers in array_two
    printf("Array Two: ");
    for(int i=0; i<5; i++) {
        printf("%d ", array_two[i]);
    }
    printf("\n");

    // Free the memory used by array_two
    free(array_two);

    return 0;
}