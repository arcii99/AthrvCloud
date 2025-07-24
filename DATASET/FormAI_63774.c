//FormAI DATASET v1.0 Category: Searching algorithm ; Style: future-proof
#include <stdio.h>

int binarySearch(int arr[], int left, int right, int x) {
   while (left <= right) {
      int mid = left + (right - left) / 2;
  
      if (arr[mid] == x) 
         return mid;
  
      if (arr[mid] < x) 
         left = mid + 1;
  
      else
         right = mid - 1;
   }
  
   return -1;
}

int main() {
   int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110};
   int n = sizeof(arr) / sizeof(arr[0]);
   int x = 60;
   int result = binarySearch(arr, 0, n - 1, x);
  
   if(result == -1) 
      printf("Element not found in array");
  
   else
      printf("Element found at index: %d", result);
  
   return 0;
}