//FormAI DATASET v1.0 Category: Searching algorithm ; Style: excited
// Hey there! I'm so excited to show you my unique searching algorithm example program in C.
// This program will search for a given integer element in an array using a modified binary search algorithm.

#include <stdio.h>

int binary_search(int arr[], int l, int r, int x) {
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

int modified_binary_search(int arr[], int n, int x) {
   int l = 0, r = n - 1;
   while (l <= r) {
      int mid = l + (r - l) / 2;
      if (arr[mid] == x)
         return mid;
      if (arr[l] <= arr[mid]) {
         if (x >= arr[l] && x <= arr[mid])
            r = mid - 1;
         else
            l = mid + 1;
      } else {
         if (x >= arr[mid] && x <= arr[r])
            l = mid + 1;
         else
            r = mid - 1;
      }
   }
   return -1;
}

int main() {
   int arr[] = {6, 7, 8, 9, 10, 1, 2, 3, 4, 5};
   int n = sizeof(arr) / sizeof(arr[0]);
   int x = 3;
   int result = modified_binary_search(arr, n, x);
   if (result == -1)
      printf("%d not found in array!", x);
   else
      printf("%d found at index %d in array!", x, result);
   return 0;
}

// Wow! That was so much fun. My algorithm will quickly search for an integer element in an array regardless of its order. 
// I hope you enjoyed this unique searching algorithm example program in C as much as I did writing it.