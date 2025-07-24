//FormAI DATASET v1.0 Category: Searching algorithm ; Style: beginner-friendly
#include <stdio.h>

// This function performs a linear search
int linearSearch(int arr[], int n, int x) {
    for(int i=0; i<n; i++) {
        if(arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {5, 3, 7, 2, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 7;
    int result = linearSearch(arr, n, x);

    if(result == -1) {
        printf("Element not found in the array.");
    } else {
        printf("Element found at index %d in the array.", result);
    }

    return 0;
}