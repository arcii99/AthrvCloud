//FormAI DATASET v1.0 Category: Searching algorithm ; Style: grateful
#include <stdio.h>

int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;       // Return index of the element if found
        }
    }
    return -1;              // If element is not found, return -1
}

int main() {
    int arr[5] = {5, 7, 3, 2, 1};
    int size = sizeof(arr) / sizeof(int);
    
    int target = 3;
    int index = linear_search(arr, size, target);
    
    // Display the result
    printf("Target element %d is found at index %d\n", target, index);
    
    return 0;       // End of program
}