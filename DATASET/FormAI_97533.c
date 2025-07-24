//FormAI DATASET v1.0 Category: Searching algorithm ; Style: high level of detail
#include <stdio.h> 

int interpolationSearch(int arr[], int low, int high, int x) 
{ 
    int pos; 
    if (low <= high && x >= arr[low] && x <= arr[high]) { 
        pos = low + ((x - arr[low]) * (high - low) / (arr[high] - arr[low])); 

        if (arr[pos] == x) 
            return pos; 
        
        if (arr[pos] < x) 
            return interpolationSearch(arr, pos + 1, high, x); 

        if (arr[pos] > x) 
            return interpolationSearch(arr, low, pos - 1, x); 
    } 
    
    return -1; 
} 

int main() 
{ 
    int arr[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int x = 12; 
    int index = interpolationSearch(arr, 0, n - 1, x); 
    
    if (index != -1) 
        printf("Element found at index %d", index); 
    else
        printf("Element not found"); 
    
    return 0; 
}