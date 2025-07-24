//FormAI DATASET v1.0 Category: Searching algorithm ; Style: immersive
#include <stdio.h>

// Define the function for C Searching algorithm
int c_search(int arr[], int size, int target) {
    int beg = 0, end = size - 1;

    while (beg <= end) {
        int mid = (beg + end) / 2;
        
        if (arr[mid] == target) { // Check if the middle element is equal to the target
            return mid;
        } else if (arr[mid] < target) { // If the middle element is smaller than the target, search in the right half of the array
            beg = mid + 1;
        } else { // If the middle element is greater than the target, search in the left half of the array
            end = mid - 1;
        }
    }

    return -1; // If the target is not found, return -1
}

int main() {

    // Initialize variables
    int arr[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(arr) / sizeof(int);
    int target = 11;

    printf("Starting C Searching Algorithm...\n");

    // Call the search function and save the result to a variable
    int result = c_search(arr, size, target);

    // Check if the target was found and print the result
    if (result != -1) {
        printf("Target element %d found at index %d!\n", target, result);
    } else {
        printf("Target element %d not found in the array.\n", target);
    }

    printf("C Searching Algorithm Ending.\n");

    return 0;
}