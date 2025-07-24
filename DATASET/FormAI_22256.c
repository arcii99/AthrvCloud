//FormAI DATASET v1.0 Category: Searching algorithm ; Style: energetic
#include <stdio.h>

int search(int arr[], int n, int x);

int main() {
    // Initialize an array of integers
    int arr[] = { 6, 7, 8, 9, 10 };
    
    // Get the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Search for number 9 in the array
    int x = 9;
    int result = search(arr, n, x);
  
    // If number found, print its position/index
    if (result == -1) {
        printf("%d not found in the array\n", x);
    } else {
        printf("%d found at position %d in the array\n", x, result);
    }

    return 0;
}

// Function to perform a linear search in an array
int search(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}