//FormAI DATASET v1.0 Category: Searching algorithm ; Style: complex
#include<stdio.h>

// Function to perform binary search recursively
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element is present in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // Element is not present in array
    return -1;
}

// Function to perform ternary search
int ternarySearch(int arr[], int l, int r, int x)
{
    while (r >= l)
    {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        // If x is present at the mid1
        if (arr[mid1] == x)
            return mid1;

        // If x is present at the mid2
        if (arr[mid2] == x)
            return mid2;

        // If x is not present in either mid1 or mid2, recur in the appropriate subarray
        if (arr[mid1] > x)
            r = mid1 - 1;
        else if (arr[mid2] < x)
            l = mid2 + 1;
        else
        {
            l = mid1 + 1;
            r = mid2 - 1;
        }
    }

    // Element is not present in array
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 3; // Element to be searched

    int result1 = binarySearch(arr, 0, n-1, x);
    (result1 == -1) ? printf("Element is not present in array\n") : printf("Element is present at index %d\n", result1);

    int result2 = ternarySearch(arr, 0, n-1, x);
    (result2 == -1) ? printf("Element is not present in array\n") : printf("Element is present at index %d\n", result2);

    return 0;
}