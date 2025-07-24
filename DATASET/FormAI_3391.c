//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Dennis Ritchie
#include <stdio.h>

// function to perform binary search on a sorted array
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;  // key not found
}

// main function to test the binary search algorithm
int main() {
    int n, key;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements in the array in sorted order: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    printf("Enter the key to search: ");
    scanf("%d", &key);
    
    int index = binarySearch(arr, 0, n-1, key);
    
    if (index == -1)
        printf("Key not found in array\n");
    else
        printf("Key found at index %d\n", index);
    
    return 0;
}