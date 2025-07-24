//FormAI DATASET v1.0 Category: Searching algorithm ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int c_search(int arr[], int n, int x) {
   int lo = 0;
   int hi = n - 1;
   int mid;
   while (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
      mid = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));
      if (arr[mid] == x)
         return mid;
      if (arr[mid] < x)
         lo = mid + 1;
      else
         hi = mid - 1;
   }
   return -1;
}

int main() {
   int i, n, x, *arr;
   printf("Enter the size of the array: ");
   scanf("%d", &n);

   arr = (int *)malloc(n * sizeof(int));

   printf("Enter %d integers in ascending order: \n", n);
   for (i = 0; i < n; i++)
      scanf("%d", &arr[i]);

   printf("Enter the value to be searched: ");
   scanf("%d", &x);

   int result = c_search(arr, n, x);

   if (result == -1)
      printf("Element not found\n");
   else
      printf("Element found at index %d\n", result);

   free(arr);

   return 0;
}