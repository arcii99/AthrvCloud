//FormAI DATASET v1.0 Category: Searching algorithm ; Style: lively
#include <stdio.h>

int search(int arr[], int n, int key) {
    // loop through each element of the array
    for(int i=0; i<n; i++) {
        
        // if the element is equal to the key, return the index
        if(arr[i] == key) {
            return i;
        }
    }
    // if key not found, return -1
    return -1;
}

int main() {
    int arr[] = {2, 3, 7, 8, 10, 15, 20};
    int key = 8;
    int n = sizeof(arr)/sizeof(arr[0]);
    
    // call the search function and print the result
    int index = search(arr, n, key);
    
    if(index == -1) {
        printf("%d Not Found in the array", key);
    }
    else {
        printf("%d Found at index %d", key, index);
    }
    return 0;
}