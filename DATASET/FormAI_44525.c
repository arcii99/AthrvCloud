//FormAI DATASET v1.0 Category: Searching algorithm ; Style: scientific
#include <stdio.h>

//function to perform binary search
int binarySearch(int arr[], int low, int high, int target)
{
    while (low <= high) 
    {
        int mid = (low + high) / 2;
 
        if (arr[mid] == target)
            return mid;
 
        if (arr[mid] < target)
            low = mid + 1;
 
        else
            high = mid - 1;
    }
    //return -1 if not found
    return -1;
}
 
//driver function
int main()
{
    int arr[] = {2, 5, 8, 10, 15, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 15;
    int result = binarySearch(arr, 0, n - 1, target);
    
    if(result == -1)
    {
        printf("Element not found.");
    }
    else
    {
        printf("Element found at index %d", result);
    }
    
    return 0;
}