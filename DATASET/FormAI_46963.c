//FormAI DATASET v1.0 Category: Searching algorithm ; Style: ultraprecise
#include <stdio.h>

/* Searching Algorithm - Binary Search */

int binary_search(int arr[], int l, int r, int x) {
   while (l <= r) {
      int mid = l + (r-l)/2;
      
      if (arr[mid] == x)
         return mid;
      
      if (arr[mid] < x)
         l = mid + 1;
      
      else
         r = mid - 1;
   }
   
   return -1;
}

int main() {
   int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
   int n = sizeof(arr)/sizeof(arr[0]);
   int x = 23;
   int result = binary_search(arr, 0, n-1, x);
   
   (result == -1) ? printf("Element not present in array\n") 
                  : printf("Element found at index: %d\n", result);
   
   return 0;
}