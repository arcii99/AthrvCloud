//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: future-proof
#include <stdio.h>

// The size of our array
#define ARR_SIZE 1000

int main(void) {

    // Declare the array with a size of ARR_SIZE and initialize to 0
    int arr[ARR_SIZE] = {0};

    // Loop through the array and add each element to the one before it
    for (int i = 1; i < ARR_SIZE; i++) {
        arr[i] += arr[i-1];
    }

    // Print the final element in the array
    printf("Final Element: %d\n", arr[ARR_SIZE-1]);

    return 0;
}