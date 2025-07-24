//FormAI DATASET v1.0 Category: Searching algorithm ; Style: authentic
#include <stdio.h>

int custom_binary_search(int arr[], int n, int target) 
{
    int left = 0;
    int right = n - 1;
    while (left <= right) 
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) 
        {
            return mid;
        } 
        else if (arr[mid] < target) 
        {
            left = mid + 1;
        } 
        else 
        {
            right = mid - 1;
        }
    }
    return -1;
}

int custom_linear_search(int arr[], int n, int target) 
{
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] == target) 
        {
            return i;
        }
    }
    return -1;
}

int main() 
{
    int arr[] = {1, 5, 9, 13, 16, 20, 22};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 16;
    
    int result = custom_binary_search(arr, n, target);
    if (result == -1) 
    {
        printf("Element not found using binary search.\n");
    } 
    else 
    {
        printf("Element found using binary search at index: %d\n", result);
    }
    
    result = custom_linear_search(arr, n, target);
    if (result == -1) 
    {
        printf("Element not found using linear search.\n");
    } 
    else 
    {
        printf("Element found using linear search at index: %d\n", result);
    }
    
    return 0;
}