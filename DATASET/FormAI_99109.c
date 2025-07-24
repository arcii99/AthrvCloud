//FormAI DATASET v1.0 Category: Searching algorithm ; Style: recursive
#include <stdio.h>

int recursive_binary_search(int arr[], int l, int r, int x);

int main()
{
    int arr[] = {2, 4, 7, 9, 11, 13, 19, 22, 25, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 13;
    int result = recursive_binary_search(arr, 0, n - 1, x);
    if (result == -1)
    {
        printf("Element is not present in the array.\n");
    }
    else
    {
        printf("Element is present at index %d.\n", result);
    }
    return 0;
}

int recursive_binary_search(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        if (arr[mid] > x)
        {
            return recursive_binary_search(arr, l, mid - 1, x);
        }
        else
        {
            return recursive_binary_search(arr, mid + 1, r, x);
        }
    }
    return -1;
}