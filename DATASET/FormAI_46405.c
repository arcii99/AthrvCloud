//FormAI DATASET v1.0 Category: Searching algorithm ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Function to perform linear search
int linear_search(int arr[], int n, int x) {
    // Loop for each element in the array
    for (int i = 0; i < n; i++) {
        // Check if the current element is the required element
        if (arr[i] == x) {
            // Return the index of the element
            return i;
        }
    }
    // Element not found, return -1
    return -1;
}

int main() {
    // Initialize array and its size
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print the array
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Get the element to be searched
    int x;
    printf("Enter the element to be searched: ");
    scanf("%d", &x);

    // Perform linear search
    int index = linear_search(arr, n, x);

    // Print the search result
    if (index == -1) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element found at index %d in the array.\n", index);
    }

    return 0;
}