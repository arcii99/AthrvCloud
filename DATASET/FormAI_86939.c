//FormAI DATASET v1.0 Category: Searching algorithm ; Style: active
#include <stdio.h>

int binary_search(int arr[], int l, int r, int val) {
   if (r >= l) {
      int mid = l + (r - l) / 2;

      if (arr[mid] == val)
         return mid;

      if (arr[mid] > val)
         return binary_search(arr, l, mid - 1, val);

      return binary_search(arr, mid + 1, r, val);
   }
   return -1;
}

int main(void) {
   int arr[] = { 2, 3, 4, 10, 40 };
   int n = sizeof(arr) / sizeof(arr[0]);
   int val = 10;
   int result = binary_search(arr, 0, n - 1, val);
   (result == -1) ? printf("Element is not present in array\n") :
         printf("Element is present at index %d\n", result);
   return 0;
}