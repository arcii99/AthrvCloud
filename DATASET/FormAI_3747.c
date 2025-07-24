//FormAI DATASET v1.0 Category: Searching algorithm ; Style: recursive
#include <stdio.h> 

int recursive_search(int arr[], int left, int right, int x) 
{ 
    if (right >= left) 
    { 
        int mid = left + (right - left) / 2; 
  
        if (arr[mid] == x) 
            return mid; 
  
        if (arr[mid] > x) 
            return recursive_search(arr, left, mid - 1, x); 
  
        return recursive_search(arr, mid + 1, right, x); 
    } 
  
    return -1; 
} 
  
int main(void) 
{ 
    int arr[] = {12, 23, 34, 45, 56, 67, 78, 89, 90}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int x = 56; 
    int result = recursive_search(arr, 0, n - 1, x); 
    if (result == -1) 
        printf("Element is not present in array"); 
    else
        printf("Element is present at index %d", result); 
    return 0; 
}