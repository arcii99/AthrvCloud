//FormAI DATASET v1.0 Category: Searching algorithm ; Style: optimized
#include <stdio.h>

int optimizedSearch(int arr[], int n, int x)
{
    int left = 0, right = n-1;
 
    while (left <= right && x >= arr[left] && x <= arr[right])
    {
        int pos = left + (((double)(right-left) /
              (arr[right]-arr[left]))*(x - arr[left]));
 
        if (arr[pos] == x)
            return pos;
 
        if (arr[pos] < x)
            left = pos + 1;
 
        else
            right = pos - 1;
    }
    return -1;
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int x = 22;
    int result = optimizedSearch(arr, n, x);
    if(result == -1)
    {
        printf("Element is not present in array");
    }
    else
    {
        printf("Element is present at index %d",result);
    }
    return 0;
}