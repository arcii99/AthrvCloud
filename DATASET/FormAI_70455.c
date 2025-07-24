//FormAI DATASET v1.0 Category: Searching algorithm ; Style: enthusiastic
#include <stdio.h>

// Function to perform the binary search
int binarySearch(int arr[], int lower, int upper, int target) {
    if (upper >= lower) {
        int middle = lower + (upper - lower) / 2;

        // If element is present at the middle itself
        if (arr[middle] == target)
            return middle;

        // If element is smaller than mid, then it can only be present in left subarray
        if (arr[middle] > target)
            return binarySearch(arr, lower, middle - 1, target);

        // Else the element can only be present in right subarray
        return binarySearch(arr, middle + 1, upper, target);
    }

    // If target is not present in array
    return -1;
}

int main() {
    int size, target;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array in ascending order:\n");

    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nEnter the target element: ");
    scanf("%d", &target);

    int result = binarySearch(arr, 0, size - 1, target);
    if (result == -1)
        printf("\nElement not found.");
    else
        printf("\nElement found at index %d", result);

    return 0;
}