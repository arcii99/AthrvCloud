//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Ada Lovelace
#include <stdio.h>

// A function that performs linear search
int linearSearch(int arr[], int n, int x) {
   for(int i=0; i<n; i++) {
      if(arr[i] == x)
         return i;
   }
   return -1; // If element is not found
}

int main() {
   int arr[] = {12, 23, 45, 67, 89, 22, 10}; // Example array
   int n = sizeof(arr)/sizeof(arr[0]); // Length of the array
   int x = 22; // Element to be searched
   
   // Call the linear search function and store the result in result variable
   int result = linearSearch(arr, n, x);
   
   // Print the result
   if(result == -1)
      printf("Element is not present in the array.");
   else
      printf("Element is present at index %d", result);
      
   return 0;
}