//FormAI DATASET v1.0 Category: Searching algorithm ; Style: interoperable
#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x) {
   while (l <= r) {
      int mid = l + (r - l) / 2;

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
   int n = sizeof(arr) / sizeof(arr[0]);
   int x = 23;

   int result = binarySearch(arr, 0, n - 1, x);

   (result == -1) ? printf("Element is not present in array")
                  : printf("Element is present at index %d", result);

   return 0;
}