//FormAI DATASET v1.0 Category: Searching algorithm ; Style: complete
#include <stdio.h>

int binarySearch(int arr[], int n, int x)
{
    int left = 0, right = n - 1;
    
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return -1;
}

int main()
{
    int arr[] = {2, 4, 7, 11, 16, 23, 29, 32, 39};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 16;
    
    int result = binarySearch(arr, n, x);
    
    if (result == -1)
        printf("%d not found in array\n", x);
    else
        printf("%d found at index %d\n", x, result);
    
    return 0;
}