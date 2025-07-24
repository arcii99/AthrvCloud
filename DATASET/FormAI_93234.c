//FormAI DATASET v1.0 Category: Searching algorithm ; Style: satisfied
#include <stdio.h>

// Function to search an element in a sorted and rotated array
int searchRotated(int arr[], int n, int key)
{
    int left = 0, right = n - 1;

    // Find the pivot element using binary search
    while (left < right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] > arr[right])
            left = mid + 1;
        else
            right = mid;
    }

    // left/right variable now points to the pivot element
    int pivot = left;

    // Prepare to do binary search now
    left = 0, right = n - 1;

    // Binary search the key in the array
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int realmid = (mid + pivot) % n;

        if (arr[realmid] == key)
            return realmid;
        else if (arr[realmid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

// Driver code
int main()
{
    int arr[] = {6, 7, 8, 9, 10, 1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 3;

    int index = searchRotated(arr, n, key);

    if (index != -1)
        printf("Element found at index %d", index);
    else
        printf("Element not found in the array");

    return 0;
}