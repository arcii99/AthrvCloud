//FormAI DATASET v1.0 Category: Searching algorithm ; Style: thoughtful
#include <stdio.h>

int linearSearch(int arr[], int size, int key) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == key) {
            return i; // return the index of the found element
        }
    }
    return -1; // if the element is not found, return -1
}

int main() {
    int arr[] = {12, 7, 3, 15, 31, 10};
    int size = sizeof(arr)/sizeof(int);
    int key = 31;
    
    int result = linearSearch(arr, size, key);
    if(result == -1) {
        printf("Element not found");
    } else {
        printf("Element found at index %d", result);
    }
    
    return 0;
}