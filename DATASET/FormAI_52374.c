//FormAI DATASET v1.0 Category: Searching algorithm ; Style: thoughtful
#include <stdio.h>

// function to search an element in an array iteratively
int iterativeSearch(int arr[], int size, int key) {
    for(int i=0; i<size; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1; // indicates element not found
}

// function to search an element in an array recursively
int recursiveSearch(int arr[], int low, int high, int key) {
    if(low > high) {
        return -1; // indicates element not found
    }
    int mid = (low + high) / 2;
    if(arr[mid] == key) {
        return mid;
    } else if(arr[mid] > key) {
        return recursiveSearch(arr, low, mid-1, key);
    } else {
        return recursiveSearch(arr, mid+1, high, key);
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int key = 7;
    int index = iterativeSearch(arr, size, key);
    if(index == -1) {
        printf("%d not found in the array.\n", key);
    } else {
        printf("%d found at index %d using iterative search.\n", key, index);
    }
    
    key = 13;
    index = recursiveSearch(arr, 0, size-1, key);
    if(index == -1) {
        printf("%d not found in the array.\n", key);
    } else {
        printf("%d found at index %d using recursive search.\n", key, index);
    }
    
    return 0;
}