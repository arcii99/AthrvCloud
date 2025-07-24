//FormAI DATASET v1.0 Category: Searching algorithm ; Style: creative
#include <stdio.h>

// Define the function for the binary search algorithm
int binarySearch(int arr[], int len, int num) {
    int min = 0, max = len - 1;
    while (min <= max) {
        int mid = (min + max) / 2;
        if (arr[mid] == num) {
            return mid;
        } else if (arr[mid] < num) {
            min = mid + 1;
        } else {
            max = mid - 1;
        }
    }
    return -1;
}

int main() {

    // Define an array of numbers to search in (must be sorted)
    int arr[] = {3, 5, 9, 12, 18, 22, 25, 30, 32, 36};
    int len = sizeof(arr) / sizeof(arr[0]);

    // Define a number to search for
    int num = 18;

    // Run the binary search algorithm using the defined array and number
    int result = binarySearch(arr, len, num);

    // Print the result of the search
    if (result == -1) {
        printf("The number %d was not found in the array.\n", num);
    } else {
        printf("The number %d was found at index %d.\n", num, result);
    }

    return 0;
}