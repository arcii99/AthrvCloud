//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Claude Shannon
#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x) {
   if (r >= l) {
      int mid = l + (r - l) / 2;

      if (arr[mid] == x)
         return mid;

      if (arr[mid] > x)
         return binarySearch(arr, l, mid - 1, x);

      return binarySearch(arr, mid + 1, r, x);
   }

   return -1;
}

int main() {
   int n, arr[100], x, result;

   /* input sorted array */
   printf("Enter the number of elements in the sorted array: ");
   scanf("%d", &n);

   printf("Enter the elements of the sorted array: ");
   for (int i = 0; i < n; i++)
      scanf("%d", &arr[i]);

   /* input element to be searched */
   printf("Enter the element to be searched: ");
   scanf("%d", &x);

   result = binarySearch(arr, 0, n - 1, x);

   if (result == -1)
      printf("Element not found in the array");
   else
      printf("Element found at index %d", result);

   return 0;
}