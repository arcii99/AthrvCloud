//FormAI DATASET v1.0 Category: Searching algorithm ; Style: imaginative
#include <stdio.h>

// Declare a function to perform binary search
int binarySearch(int array[], int left, int right, int element) {

    // Perform binary search until left <= right  
    while (left <= right) {

        // Set the middle index of the array
        int middle = left + (right - left) / 2;

        // Check if the element is present at the middle index
        if (array[middle] == element) {
            return middle;
        }

        // If element is greater, ignore left half  
        if (array[middle] < element) {
            left = middle + 1;
        }

        // If element is smaller, ignore right half  
        else {
            right = middle - 1;
        }
    }

    // Element is not present in the array
    return -1;
}

// Declare the main function
int main() {

    // Initialize the array and variables
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(array) / sizeof(array[0]);
    int element = 5;

    // Perform binary search
    int result = binarySearch(array, 0, n - 1, element);

    // Display the result
    if (result == -1) {
        printf("Element is not present in the array.\n");
    }
    else {
        printf("Element is present at index %d.\n", result);
    }

    // Exit the program
    return 0;
}