//FormAI DATASET v1.0 Category: Searching algorithm ; Style: systematic
#include <stdio.h>

int binarySearch(int arr[], int left, int right, int x) {
   while (left <= right) {
      int middle = left + (right - left) / 2;

      if (arr[middle] == x)
         return middle;

      if (arr[middle] < x)
         left = middle + 1;

      else
         right = middle - 1;
   }
   return -1;
}

int main() {
   int arr[] = {4, 6, 8, 10, 12, 14, 16, 18, 20};
   int size = sizeof(arr)/sizeof(arr[0]);
   int x = 14;
   int result = binarySearch(arr, 0, size-1, x);
   if(result == -1)
      printf("Element not found\n");
   else
      printf("Element found at index: %d\n", result);
   return 0;
}