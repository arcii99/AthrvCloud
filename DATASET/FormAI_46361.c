//FormAI DATASET v1.0 Category: Searching algorithm ; Style: sophisticated
#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int low, int high, int key) {
    while(low <= high) {
        int mid = low + (high - low)/2;

        if(arr[mid] == key)
            return mid;
        else if(key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

// Function to perform interpolation search
int interpolationSearch(int arr[], int low, int high, int key) {
    while(low <= high && key >= arr[low] && key <= arr[high]) {
        int position = low + (((double)(high - low)/(arr[high] - arr[low])) * (key - arr[low]));

        if(arr[position] == key)
            return position;

        if(arr[position] < key)
            low = position + 1;
        else
            high = position -1;
    }

    return -1;
}

// Test code
int main() {
    int arr[] = {2, 4, 5, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr)/sizeof(arr[0]);

    int key = 10;
    int index = binarySearch(arr, 0, n-1, key);
    if(index == -1)
        printf("%d not found in the array\n", key);
    else
        printf("%d found at index %d using binary search function\n", key, index);

    key = 12;
    index = interpolationSearch(arr, 0, n-1, key);
    if(index == -1)
        printf("%d not found in the array\n", key);
    else
        printf("%d found at index %d using interpolation search function\n", key, index);

    return 0;
}