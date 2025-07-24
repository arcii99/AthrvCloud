//FormAI DATASET v1.0 Category: Searching algorithm ; Style: innovative
#include<stdio.h> 

int unique_search(int arr[], int n, int num) 
{ 
    // Initialize left and right pointers 
    int left = 0, right = n - 1; 
  
    // Binary search 
    while (left <= right) { 
        int mid = (left + right) / 2; 
  
        // If number is found at mid, return index 
        if (arr[mid] == num) 
            return mid; 
  
        // If left half of array is sorted and num is in left half 
        if (arr[left] <= arr[mid]) { 
            if (num >= arr[left] && num < arr[mid]) 
                right = mid - 1; 
            else
                left = mid + 1; 
        } 
  
        // If right half of array is sorted and num is in right half 
        else { 
            if (num > arr[mid] && num <= arr[right]) 
                left = mid + 1; 
            else
                right = mid - 1; 
        } 
    } 
  
    // If number is not found, return -1 
    return -1; 
} 

int main() 
{ 
    int arr[] = { 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 4, 5, 6, 7 }; 
    int n = sizeof(arr) / sizeof(int); 
    int num = 10; 
    
    // Find if num exists in array, and get index if it does 
    int index = unique_search(arr, n, num); 
    
    // Print index of num if found, else print error message  
    if (index == -1) {
        printf("Error: Number not found in array.\n");
    }
    else {
        printf("Number %d found at index %d in array.\n", num, index);
    }
  
    return 0; 
}