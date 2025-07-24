//FormAI DATASET v1.0 Category: Searching algorithm ; Style: beginner-friendly
#include <stdio.h>

// function to search for an element x in array arr
int linear_search(int arr[], int n, int x) {
    // loop through each element in the array
    for (int i = 0; i < n; i++) {
        // if the current element matches x, return its index
        if (arr[i] == x) {
            return i;
        }
    }
    // if x is not found in the array, return -1
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};  // initialize the array
    int n = sizeof(arr) / sizeof(arr[0]);  // find the length of the array
    int x = 3;  // the element to be searched for
    
    // call the linear search function to find the index of x in the array
    int index = linear_search(arr, n, x);
    
    // print the result
    if (index == -1) {
        printf("%d was not found in the array.\n", x);
    } else {
        printf("%d was found at index %d in the array.\n", x, index);
    }
    
    return 0;
}