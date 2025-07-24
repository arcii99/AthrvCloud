//FormAI DATASET v1.0 Category: Searching algorithm ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

int binary_Search(int arr[], int left, int right, int value) {
   while(left <= right) {
      int mid = left + (right - left) / 2;
      if(arr[mid] == value)
         return mid;
      if(arr[mid] < value)
         left = mid + 1;
      else
         right = mid - 1;
   }
   return -1;  // returns if search value is not found in array
}

int main() {
   int arr[10] = {2, 8, 9, 15, 24, 26, 32, 38, 43, 57};
   int n = sizeof(arr) / sizeof(arr[0]);
   int value = 38;
   int result = binary_Search(arr, 0, n - 1, value);
   if(result == -1)
      printf("Value not found in array!");
   else
      printf("Value found at index %d", result);
   return 0;
}