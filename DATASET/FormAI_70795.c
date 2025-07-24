//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Sherlock Holmes
#include <stdio.h>

// Function to search for a key element in a sorted array using binary search
int sherlock_search(int arr[], int key, int low, int high) {
    // Check if the array has been searched through completely
    if(low > high) {
        printf("Element not found! The culprit has evaded us.\n");
        return -1;
    }
    
    // Calculate the mid-point of the array
    int mid = (low + high) / 2;
    
    // If the mid-point of the array contains the key element, return its index
    if(arr[mid] == key) {
        printf("Element found! We have caught the culprit.\n");
        return mid;
    }
    
    // Search the left half of the array if the key is smaller than the mid-point
    if(key < arr[mid]) {
        printf("The culprit is on the left!\n");
        return sherlock_search(arr, key, low, mid - 1);
    }
    
    // Search the right half of the array if the key is greater than the mid-point
    else {
        printf("The culprit is on the right!\n");
        return sherlock_search(arr, key, mid + 1, high);
    }
}

// Driver code
int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 12;
    int result = sherlock_search(arr, key, 0, n - 1);
    if(result != -1)
        printf("The key element is at index %d\n", result);
    return 0;
}