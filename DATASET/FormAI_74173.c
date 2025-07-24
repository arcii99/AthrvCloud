//FormAI DATASET v1.0 Category: Searching algorithm ; Style: energetic
#include <stdio.h>

// Function to search for an element in an array
int search(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++) {
        // If element is found
        if (arr[i] == x) {
            return i;
        }
    }
    // If element is not found
    return -1;
}

int main() {
    int arr[] = { 10, 20, 30, 40, 50 };
    int x = 30;
    int n = sizeof(arr) / sizeof(arr[0]);
     
    // Searching for the element
    int result = search(arr, n, x);
    if (result == -1) {
        printf("Element not present in the array\n");
    } else {
        printf("Element is present at position %d in the array\n", result);
    }
    return 0;
}