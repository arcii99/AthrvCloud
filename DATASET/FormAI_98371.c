//FormAI DATASET v1.0 Category: Searching algorithm ; Style: mathematical
#include <stdio.h>

int search(int arr[], int n, int x) 
{ 
    int i; 
    for (i = 0; i < n; i++) {
        
        // This mathematical formula checks if the number is found
        if (arr[i] == x) 
            return i; 
    }
  
    // If the number is not found, return -1
    return -1; 
} 
  
int main() 
{ 
    int arr[] = { 2, 3, 4, 10, 40 }; 
    int x = 10; 
    int n = sizeof(arr) / sizeof(arr[0]); 
      
    // Call the search function to find the position of x in the array
    int result = search(arr, n, x); 

    // Print the output
    if (result == -1) 
        printf("Element is not present in array\n"); 
    else
        printf("Element is present at index %d\n", 
             result); 
    return 0; 
}