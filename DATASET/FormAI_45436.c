//FormAI DATASET v1.0 Category: Searching algorithm ; Style: portable
#include <stdio.h>

// Function to search for an element in an array using linear search
int linear_search(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == key) return i;

    return -1;  // return -1 if element not found
}

// Function to search for an element in an array using binary search
int binary_search(int arr[], int left, int right, int key)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }

    return -1;  // return -1 if element not found
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;

    // Linear Search
    int linear_index = linear_search(arr, n, key);
    if (linear_index != -1)
        printf("Element %d found using linear search at index %d\n", key, linear_index);
    else
        printf("Element %d not found using linear search\n", key);

    // Binary Search
    int binary_index = binary_search(arr, 0, n - 1, key);
    if (binary_index != -1)
        printf("Element %d found using binary search at index %d\n", key, binary_index);
    else
        printf("Element %d not found using binary search\n", key);

    return 0;
}