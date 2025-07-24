//FormAI DATASET v1.0 Category: Searching algorithm ; Style: unmistakable
#include<stdio.h>

int binarySearch(int arr[], int l, int r, int x) {
   if (r >= l) {
      int mid = (l + r)/2;
      if (arr[mid] == x)
         return mid;
      if (arr[mid] > x)
         return binarySearch(arr, l, mid-1, x);
      return binarySearch(arr, mid+1, r, x);
   }
   return -1;
}

int interpolationSearch(int arr[], int n, int x) {
   int lo = 0, hi = n - 1;
   while (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
      if (lo == hi) {
         if (arr[lo] == x) return lo;
         return -1;
      }

      int pos = lo + (((double)(hi-lo) /
         (arr[hi]-arr[lo]))*(x - arr[lo]));
      if (arr[pos] == x)
         return pos;
      if (arr[pos] < x)
         lo = pos + 1;
      else
         hi = pos - 1;
   }
   return -1;
}

int main() {
   int arr[] = {12, 25, 37, 42, 56, 75, 87};
   int n = sizeof(arr)/sizeof(arr[0]), x = 37;
   int result = binarySearch(arr, 0, n-1, x);
   if (result == -1) printf("Element not found\n");
   else printf("Element found at index: %d\n", result);

   result = interpolationSearch(arr, n, x);
      if (result == -1) printf("Element not found\n");
   else printf("Element found at index: %d\n", result);
   return 0;
}