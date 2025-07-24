//FormAI DATASET v1.0 Category: Searching algorithm ; Style: detailed
#include <stdio.h>

/* Function to search an element in array using linear search */
int linearSearch(int arr[], int n, int x) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        if (arr[i] == x) 
            return i; 
    return -1; /* If element is not present in the array */
} 

/* Function to search an element in array using binary search */
int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        /* If the element is present at the middle */
        if (arr[mid] == x) 
            return mid; 
  
        /* If element is smaller than mid, then it can only be present in left subarray */
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        /* Else the element can only be present in right subarray */
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    /* If element is not present in array */
    return -1; 
} 

int main() 
{ 
    int arr[] = { 5, 10, 15, 20, 25, 30, 35, 40, 45, 50 };  /* Array of elements */ 
    int n = sizeof(arr) / sizeof(arr[0]);  /* Size of the array */
    int x = 35, y = 100;  /* Element to be searched */
  
    /* Performing linear search */
    int result = linearSearch(arr, n, x); 
    (result == -1) ? printf("Element is not present in array.\n") : printf("Element is present at index %d.\n", result); 
  
    /* Performing binary search */
    int result2 = binarySearch(arr, 0, n - 1, y); 
    (result2 == -1) ? printf("Element is not present in array.\n") : printf("Element is present at index %d.\n", result2); 
    return 0; 
}