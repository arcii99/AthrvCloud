//FormAI DATASET v1.0 Category: Searching algorithm ; Style: innovative
#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int x) {
    int i;
    for(i = 0; i < n; i++) {
        if(arr[i] == x) {
            return i; // Return the index of the element if found
        }
    }
    return -1; // Return -1 if the element is not found
}

// Function to perform binary search
int binarySearch(int arr[], int left, int right, int x) {
    if(right >= left) {
        int mid = left + (right - left) / 2;
        // If element found at mid index
        if(arr[mid] == x) {
            return mid; 
        }
        // If element is smaller than mid, search left subarray
        if(arr[mid] > x) {
            return binarySearch(arr, left, mid - 1, x);
        }
        // Else search right subarray
        return binarySearch(arr, mid + 1, right, x);
    }
    // If element is not present in the array
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    
    // Perform linear search
    int linearResult = linearSearch(arr, n, x);
    
    if(linearResult == -1) {
        printf("Element not found");
    } else {
        printf("Element found at index: %d\n", linearResult);
    }
    
    // Sort array in ascending order to perform binary search
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    // Perform binary search
    int binaryResult = binarySearch(arr, 0, n - 1, x);
    
    if(binaryResult == -1) {
        printf("Element not found");
    } else {
        printf("Element found at index: %d", binaryResult);
    }
    
    return 0;
}