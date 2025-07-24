//FormAI DATASET v1.0 Category: Memory management ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize variables
    int* arr;
    int size, i;
    time_t t;

    // Prompt user for array size
    printf("Enter size of array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for array
    arr = (int*)malloc(size * sizeof(int));

    // Generate random numbers and populate array
    srand((unsigned) time(&t));
    for (i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    // Print out the array to the console
    printf("Array contents:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free allocated memory 
    free(arr);

    return 0;
}