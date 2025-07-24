//FormAI DATASET v1.0 Category: Searching algorithm ; Style: inquisitive
#include <stdio.h>

int binarySearch(int arr[], int left, int right, int val) {
   while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == val)
         return mid;
      else if (arr[mid] < val)
         left = mid + 1;
      else
         right = mid - 1;
   }
   return -1;
}

int main() {
   int arr[] = {2, 4, 7, 9, 12, 18, 26, 31, 39, 41};
   int n = sizeof(arr) / sizeof(arr[0]);
   int val = 12;
   int index = binarySearch(arr, 0, n - 1, val);
   
   if (index == -1)
      printf("Element not found\n");
   else
      printf("Element found at index %d", index);
   
   return 0;
}