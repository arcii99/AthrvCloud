//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Ada Lovelace
// This is a C program that searches for a given element in an array

#include <stdio.h>

// function to perform linear search
int linearSearch(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1; // element not found
}

// main function
int main() {
    int arr[10] = { 2, 7, 4, 1, 8, 3, 9, 6, 5, 0 };
    int n = 10;
    int x = 3; // element to be searched
    int pos = linearSearch(arr, n, x);
    if (pos == -1) {
        printf("Element not found in the array.");
    } else {
        printf("Element found at position %d.", pos+1);
    }
    return 0;
}