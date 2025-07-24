//FormAI DATASET v1.0 Category: Searching algorithm ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

/* A function to perform binary search on an integer array */
int binarySearch(int arr[], int left, int right, int x)
{
    while (left <= right) {

        int mid = left + (right - left) / 2;

        // If x is present at mid
        if (arr[mid] == x)
            return mid;

        // If x is greater, ignore left half
        if (arr[mid] < x)
            left = mid + 1;

        // If x is smaller, ignore right half
        else
            right = mid - 1;
    }

    // If we reach here, then element was not present
    return -1;
}

/* A function to perform a unique searching algorithm on an integer array */
int uniqueAlgorithm(int arr[], int size, int x)
{

    // Sort the array using any sorting algorithm (Here we are using Bubble Sort)
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

    int left = 0, right = size - 1;

    // Perform binary search on the sorted array
    while (left <= right) {
        int mid = (left + right) / 2;

        /* Check if the middle element is the target element */
        if (arr[mid] == x) {
            /* Check if the middle element is not repeated in the array */
            if (mid != left && mid != right && arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1])
                return mid;
            else {
                /* If the middle element is repeated, perform binary search on its left and right subarrays */
                int left_result = binarySearch(arr, left, mid-1, x);
                int right_result = binarySearch(arr, mid+1, right, x);

                /* Check if both subarrays return -1, if so, return the index of the target element */
                if (left_result == -1 && right_result == -1)
                    return mid;
                
                /* If not, return the closest non-repeated element */
                else if (left_result == -1)
                    return right_result;
                else if (right_result == -1)
                    return left_result;
                else {
                    if (mid-left_result < right_result-mid)
                        return left_result;
                    else
                        return right_result;
                }
            }
        }

        /* If target element is smaller than mid, search left subarray */
        if (arr[mid] > x)
            right = mid - 1;

        /* If target element is greater than mid, search right subarray */
        else
            left = mid + 1;
    }

    // If we reach here, then element was not present
    return -1;
}

/* Driver code */
int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 40;

    int result = uniqueAlgorithm(arr, size, target);

    if (result == -1)
        printf("Element not present in array");
    else
        printf("Element found at index %d", result);
    return 0;
}