//FormAI DATASET v1.0 Category: Searching algorithm ; Style: cheerful
#include <stdio.h>

// Function to implement Linear Search Algorithm
int linear_search(int arr[], int n, int key) {
    int i;
    
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Element found
        }
    }
    
    return -1; // Element not found
}

int main() {
    
    int arr[] = {8, 5, 6, 9, 2, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 7;
    
    int index = linear_search(arr, n, key);
    
    if (index == -1) {
        printf("Element not found in the array\n");
    }
    else {
        printf("Element found at index: %d in the array\n", index);
    }
    
    return 0;
}