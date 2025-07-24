//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTS 1000000000 
// Define the number of elements the program will be working with 

int main() {

    int *arr = malloc(NUM_ELEMENTS * sizeof(int)); // Allocate memory for array with NUM_ELEMENTS elements 

    // Fill the array with random elements between 1 and 1000
    srand(time(NULL));
    for(int i = 0; i < NUM_ELEMENTS; i++) {
        arr[i] = rand() % 1000 + 1;
    }

    // Find the maximum element in the array using a linear search
    int max_element = arr[0];
    for(int i = 1; i < NUM_ELEMENTS; i++) {
        if(arr[i] > max_element) {
            max_element = arr[i];
        }
    }

    printf("The maximum element in the array is: %d\n", max_element);

    free(arr); // Free the memory allocated for the array
    return 0;
}