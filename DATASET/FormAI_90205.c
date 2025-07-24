//FormAI DATASET v1.0 Category: Searching algorithm ; Style: introspective
#include <stdio.h>

/* This is a unique searching algorithm that uses recursive binary search */
/* It takes in an array, the element to be searched for and the left and right indices of the array */
int recursiveBinarySearch(int arr[], int left, int right, int x) {
    // If the right index is greater than or equal to the left index
    if (right >= left) {
        // Get the middle index of the array
        int middle = left + (right - left) / 2;

        // If the middle element is equal to the searched element, return its index
        if (arr[middle] == x) {
            return middle;
        }
        // If the middle element is greater than the searched element, recursively search the left half
        if (arr[middle] > x) {
            return recursiveBinarySearch(arr, left, middle - 1, x);
        }
        // If the middle element is less than the searched element, recursively search the right half
        return recursiveBinarySearch(arr, middle + 1, right, x);
    }
    // If the element is not found, return -1
    return -1;
}

int main() {
    // Define an array of integers in ascending order
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    // Define the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Ask the user for the element to be searched
    int x;
    printf("Enter the element to be searched: ");
    scanf("%d", &x);

    // Call the recursive binary search function and get the index of the searched element
    int result = recursiveBinarySearch(arr, 0, n - 1, x);

    // If the element is found, print its index, otherwise print that it is not found
    if (result != -1) {
        printf("Element found at index %d.\n", result);
    } else {
        printf("Element not found.\n");
    }
    return 0;
}