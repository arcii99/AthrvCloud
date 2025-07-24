//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Alan Touring
#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x) {
   if (r >= l) {
      int mid = l + (r - l)/2;
      if (arr[mid] == x)
         return mid;
      if (arr[mid] > x)
         return binarySearch(arr, l, mid-1, x);
      return binarySearch(arr, mid+1, r, x);
   }
   return -1;
}

int main() {
   int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int x = 23;
   int index = binarySearch(arr, 0, n-1, x);
   if(index == -1) {
      printf("Element is not present in array.\n");
   } else {
      printf("Element is present at index %d.\n", index);
   }
   return 0;
}