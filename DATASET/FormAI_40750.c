//FormAI DATASET v1.0 Category: Searching algorithm ; Style: excited
#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x) {
   if (r >= l) {
      int mid = l + (r - l) / 2;

      // If the element is present at the middle
      if (arr[mid] == x)
         return mid;

      // If element is smaller than mid
      if (arr[mid] > x)
         return binarySearch(arr, l, mid - 1, x);

      // Else the element is in right sub-array
      return binarySearch(arr, mid + 1, r, x);
   }

   // If element is not present in the array 
   return -1;
}

int main(void) {
   int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   int n = sizeof(arr) / sizeof(arr[0]);
   int x = 5;

   // Searching the element
   int result = binarySearch(arr, 0, n - 1, x);

   // If the element is found, print the index
   // Else print that the element is not present in the array
   (result == -1) ? printf("Element is not present in array")
                  : printf("Element is present at index: %d", result);
   return 0;
}