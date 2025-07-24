//FormAI DATASET v1.0 Category: Searching algorithm ; Style: optimized
#include <stdio.h>

int search(int arr[], int n, int x) {
    // initialize variables for start and end indices of the array
    int start = 0, end = n-1;

    // while loop to keep searching until start and end indices cross each other
    while (start <= end) {
        int mid = start + (end - start)/2; // calculate the middle element of the array

        // if element is found at the middle index, return the index
        if (arr[mid] == x)
            return mid;

        // if element is smaller than middle element, search the left half of the array
        else if (arr[mid] > x)
            end = mid - 1; // adjust the end index to mid - 1

        // if element is larger than middle element, search the right half of the array
        else
            start = mid + 1; // adjust the start index to mid + 1
    }

    // if element is not found in the array, return -1
    return -1;
}

// main function
int main() {
    int arr[] = {2, 5, 7, 14, 19, 21, 25, 29, 35, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 25; // element to search for
    int index = search(arr, n, x);

    if (index == -1)
        printf("Element not found in array.\n");
    else
        printf("Element found at position %d.\n", index+1);

    return 0;
}