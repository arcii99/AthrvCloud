//FormAI DATASET v1.0 Category: Searching algorithm ; Style: protected
#include <stdio.h>

// Defining a protected style function for binary search

int protected_binary_search(int arr[], int n, int key) {
   int left = 0;
   int right = n - 1;
   
   // Run the loop until the key is found or left becomes greater than right.
   while (left <= right) {
      int mid = (left + right) / 2;

      // If the key is found at mid, return mid
      if (arr[mid] == key) {
         return mid;
      }

      /* If key is greater than mid, ignore left half and continue search in the right half */
      else if (arr[mid] < key) {
         left = mid + 1;
      }

      // If key is smaller than mid, ignore right half and continue search in the left half
      else {
         right = mid - 1;
      }
   }

   // If the key is not found in the array, return -1
   return -1;
}

// Driver function
int main() {
   // Initialize the array and key
   int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
   int n = sizeof(arr) / sizeof(arr[0]);
   int key = 23;

   // Perform binary search on the array
   int res = protected_binary_search(arr, n, key);
   
   // Check the result and print output accordingly
   if (res == -1) {
      printf("The key %d is not found in the array.\n", key);
   } else {
      printf("The key %d is found at index %d\n", key, res);
   }
   
   return 0;
}