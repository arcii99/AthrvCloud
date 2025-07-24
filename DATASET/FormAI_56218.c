//FormAI DATASET v1.0 Category: Searching algorithm ; Style: introspective
#include <stdio.h>

// Function to perform binary search recursively
int binarySearch(int arr[], int start, int end, int key)
{
    // base condition
    if (start <= end)
    {
        // find the middle index
        int mid = (start + end) / 2;

        // if key is found, return its index
        if (arr[mid] == key)
            return mid;

        // if the key is less than the mid element, search in the left half
        else if (key < arr[mid])
            return binarySearch(arr, start, mid - 1, key);

        // else search in the right half
        else
            return binarySearch(arr, mid + 1, end, key);
    }
    // key not found
    return -1;
}

// Function to perform linear search recursively
int linearSearch(int arr[], int n, int key)
{
    // base condition
    if (n < 0)
        return -1;

    // if key is found, return its index
    else if (arr[n] == key)
        return n;

    // else search in the remaining array
    else
        return linearSearch(arr, n - 1, key);
}

int main()
{
    int arr[] = {12, 45, 67, 89, 101, 123, 200};
    int n = sizeof(arr) / sizeof(arr[0]);

    // example usage of binary search
    int binaryKey = 67;
    int binaryResult = binarySearch(arr, 0, n - 1, binaryKey);
    if (binaryResult != -1)
        printf("Binary Search: %d is found at index %d\n", binaryKey, binaryResult);
    else
        printf("Binary Search: %d is not found in the array\n", binaryKey);

    // example usage of linear search
    int linearKey = 89;
    int linearResult = linearSearch(arr, n - 1, linearKey);
    if (linearResult != -1)
        printf("Linear Search: %d is found at index %d\n", linearKey, linearResult);
    else
        printf("Linear Search: %d is not found in the array\n", linearKey);

    return 0;
}