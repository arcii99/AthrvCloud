//FormAI DATASET v1.0 Category: Searching algorithm ; Style: calm
#include <stdio.h>

int search(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++) { // loop through each element in arr
        if (arr[i] == x) { // if element is equal to x
            return i; // return the index of the element
        }   
    }
    // if x is not found in arr, return -1
    return -1;
}

int main() {
    int arr[] = { 4, 6, 2, 1, 8, 3, 7, 5 };
    int n = sizeof(arr) / sizeof(arr[0]); // calculate size of arr
    int x = 8;

    int result = search(arr, n, x); // call the search function
    if (result == -1) { // if x is not found in arr
        printf("%d is not present in the array.\n", x);
    } else { // if x is found in arr
        printf("%d is present at index %d.\n", x, result);
    }

    return 0;
}