//FormAI DATASET v1.0 Category: Searching algorithm ; Style: lively
#include <stdio.h>

// function to perform linear search in an array
int linear_search(int arr[], int n, int target) {
    for(int i = 0; i < n; i++) {    // loop through the array
        if(arr[i] == target) {      // if target found, return the index
            return i;
        }
    }
    return -1;      // target not found, return -1
}

int main() {
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(arr)/sizeof(arr[0]);    // get the size of array
    int target = 50;

    // perform linear search for target in array
    int index = linear_search(arr, n, target);

    if(index == -1) {
        printf("Target not found in array.\n");
    } else {
        printf("Target found at index %d in array.\n", index);
    }

    return 0;
}