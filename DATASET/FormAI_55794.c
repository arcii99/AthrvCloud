//FormAI DATASET v1.0 Category: Searching algorithm ; Style: brave
#include <stdio.h>

int binary_search(int arr[], int low, int high, int key)
{

    if (high >= low) {
        int mid = low + (high - low) / 2;
 
        if (arr[mid] == key)
            return mid;
 
        if (arr[mid] > key)
            return binary_search(arr, low, mid - 1, key);
 
        return binary_search(arr, mid + 1, high, key);
    }
 
    return -1;
}
 
int main()
{
    int arr[] = { 3, 7, 11, 14, 23, 35, 67, 76 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 35;
    int result = binary_search(arr, 0, n - 1, key);
    (result == -1)
        ? printf("Element is not present in array")
        : printf("Element is present at index %d", result);
    return 0;
}