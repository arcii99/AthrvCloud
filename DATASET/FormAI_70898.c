//FormAI DATASET v1.0 Category: Searching algorithm ; Style: calm
#include <stdio.h>

// Function to search an element in an array using Linear Search algorithm
int linearSearch(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 70;
    int result = linearSearch(arr, n, x);
    if (result == -1) {
        printf("%d not found in the array.", x);
    }
    else {
        printf("%d found at index %d in the array.", x, result);
    }
    return 0;
}