//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the number of operations to perform
#define NUM_OPERATIONS 1000000

// Define the maximum number to generate
#define MAX_NUM 1000

// Define the function to be optimized
int max_diff(int *arr, int size) {
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return max - min;
}

// Define the main function
int main() {
    // Generate a random array
    int arr[NUM_OPERATIONS];
    srand(time(NULL));
    for (int i = 0; i < NUM_OPERATIONS; i++) {
        arr[i] = rand() % MAX_NUM + 1;
    }

    // Calculate the difference between the max and min values
    int diff = max_diff(arr, NUM_OPERATIONS);

    // Print the result
    printf("The maximum difference in the array is: %d\n", diff);

    // Return 0 to signify success
    return 0;
}