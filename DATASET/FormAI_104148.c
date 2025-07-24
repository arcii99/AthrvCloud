//FormAI DATASET v1.0 Category: Error handling ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    srand(time(NULL));  // Seed pseudo-random number generator

    // Declare an array of 10 integers
    int arr[10];

    // Generate random integers and store them in the array
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;  // Random integer between 0 and 99
    }

    // Print out the contents of the array
    printf("Array contents: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Attempt to access an invalid index of the array
    int index = 11;
    if (index < 0 || index >= 10) {
        printf("Error: Invalid index %d\n", index);
        exit(1);  // Terminate the program with an error code
    }
    printf("Value at index %d: %d\n", index, arr[index]);

    return 0;
}