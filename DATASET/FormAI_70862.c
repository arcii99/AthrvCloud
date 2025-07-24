//FormAI DATASET v1.0 Category: Searching algorithm ; Style: innovative
#include <stdio.h>

// Function to perform a binary search
int binary_search(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        // If the element is present at the middle
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, search in left subarray
        if (arr[mid] > x)
            high = mid - 1;

        // Else search in right subarray
        else
            low = mid + 1;
    }

    // If the element is not present in the array
    return -1;
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Enter a number to search in the array: ");
    int x;
    scanf("%d", &x);

    int result = binary_search(arr, n, x);

    if (result == -1)
        printf("Element is not present in array");
    else
        printf("Element is present at index %d", result);

    return 0;
}