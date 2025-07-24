//FormAI DATASET v1.0 Category: Searching algorithm ; Style: genious
#include <stdio.h>

int main() {
    int arr[10] = {1, 3, 5, 7, 9, 10, 14, 18, 21, 25}; // Array of integers
    int size = sizeof(arr) / sizeof(arr[0]); // Determine size of array
    int search = 10; // Element to search for
    int low = 0; // Beginning of the search range
    int high = size - 1; // End of the search range
    int found = 0; // A flag to indicate if element was found
    
    while (low <= high) {
        int mid = (low + high) / 2; // Get middle index
        if (arr[mid] == search) {
            printf("Element found at index %d", mid);
            found = 1;
            break;
        } else if (arr[mid] < search) {
            low = mid + 1; // Search in right half of the array
        } else {
            high = mid - 1; // Search in left half of the array
        }
    }
    
    if (!found) {
        printf("Element not found in the array.");
    }
    
    return 0;
}