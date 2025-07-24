//FormAI DATASET v1.0 Category: Searching algorithm ; Style: invasive
#include <stdio.h>

// Define the size of the array
#define ARRAY_SIZE 10

// The array to be searched
int arr[ARRAY_SIZE] = { 2, 4, 1, 8, 6, 5, 7, 3, 9, 10 };

// Invasive searching algorithm
int invasive_search(int key, int* arr, int n) {
    for (int i = 0; i < n; i++) {
        // Check if the current element is the key
        if (*(arr+i) == key) {
            // Return the index of the key
            return i;
        } else {
            // Invasive part - modify the current element to be the key
            *(arr+i) = key;
        }
    }
    // If the key was not found, return -1
    return -1;
}

int main() {
    // Print the initial values of the array
    printf("Initial array: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Search for the key 5
    int index = invasive_search(5, arr, ARRAY_SIZE);

    // Print the result and the modified array
    if (index != -1) {
        printf("Key found at index %d\n", index);
    } else {
        printf("Key not found\n");
    }

    printf("Modified array: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}