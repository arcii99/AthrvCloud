//FormAI DATASET v1.0 Category: Searching algorithm ; Style: configurable
#include <stdio.h>

// Function to search an element in an array
int binarySearch(int arr[], int low, int high, int searchElement) {

    if(low <= high) {
        int mid = low + (high-low)/2;

        if(arr[mid] == searchElement)
            return mid;

        if(arr[mid] > searchElement)
            return binarySearch(arr, low, mid-1, searchElement);

        return binarySearch(arr, mid+1, high, searchElement);
    }

    return -1;
}

int main() {

    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int arrSize = sizeof(arr)/sizeof(arr[0]);

    int searchElement;
    printf("Enter the element to search: ");
    scanf("%d", &searchElement);

    int result = binarySearch(arr, 0, arrSize-1, searchElement);
    if(result == -1) {
        printf("Element not found!\n");
    }
    else {
        printf("Element found at index %d\n", result);
    }

    return 0;
}