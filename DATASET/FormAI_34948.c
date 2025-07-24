//FormAI DATASET v1.0 Category: Searching algorithm ; Style: sophisticated
#include <stdio.h>

// Function to search a given element using linear search algorithm
int linear_search(int arr[], int n, int x) {
   int i;
   for (i = 0; i < n; i++) {
      if (arr[i] == x)
         return i; // Return the index where element is found
   }
   return -1; // Return -1 if element is not found
}

// Function to search a given element using binary search algorithm
int binary_search(int arr[], int left, int right, int x) {
   if (right >= left) {
      int mid = left + (right - left)/2; // Calculate midpoint

      if (arr[mid] == x)
         return mid; // Return index where element is found

      if (arr[mid] > x)
         return binary_search(arr, left, mid-1, x); // Introduces recursion and searches in left side of array

      return binary_search(arr, mid+1, right, x); // Introduces recursion and searches in right side of array
   }
   return -1; // Returns -1 if element is not found
}

int main() {
   int arr[] = {1, 5, 11, 23, 45, 71, 87, 92, 101, 136}; // Sample integer array
   int n = sizeof(arr)/sizeof(arr[0]); // Calculate size of array

   int x = 101; // Element to search
   int linearSearchResult = linear_search(arr, n, x); // Call linear search function to search a given element
   int binarySearchResult = binary_search(arr, 0, n-1, x); // Call binary search function to search a given element

   if (linearSearchResult == -1)
      printf("%d not found in array using linear search\n", x);
   else
      printf("%d found in the array at index %d using linear search\n", x, linearSearchResult);

   if (binarySearchResult == -1)
      printf("%d not found in array using binary search\n", x);
   else
      printf("%d found in the array at index %d using binary search\n", x, binarySearchResult);

   return 0; // Return 0 to terminate the program
}