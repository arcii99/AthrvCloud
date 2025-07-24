//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_VALUES 1000000

// Function to swap two integers
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Function to perform binary search
int binarySearch(int arr[], int l, int r, int x) {
    if(r >= l) {
        int mid = l + (r - l) / 2;

        // If element is present at the middle
        if(arr[mid] == x) {
            return mid;
        }

        // If element is smaller than mid, search in left subarray
        if(arr[mid] > x) {
            return binarySearch(arr, l, mid-1, x);
        }

        // If element is larger than mid, search in right subarray
        return binarySearch(arr, mid+1, r, x);
    }

    // If element is not present in the array
    return -1;
}

int main() {
    // Generate random values between 1 and 1000
    int arr[MAX_VALUES];
    srand(time(0));  // Seed for random number generation
    for(int i=0; i<MAX_VALUES; i++) {
        arr[i] = (rand() % 1000) + 1;
    }

    // Sort the array using bubble sort
    bubbleSort(arr, MAX_VALUES);

    // Search for a random value in the array using binary search
    int search_value = (rand() % 1000) + 1;
    int result = binarySearch(arr, 0, MAX_VALUES-1, search_value);

    if(result == -1) {
        printf("Value not found in the array.\n");
    } else {
        printf("Value found at index %d in the array.\n", result);
    }

    return 0;
}