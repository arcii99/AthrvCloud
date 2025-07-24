//FormAI DATASET v1.0 Category: Searching algorithm ; Style: accurate
#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x) {
   if (r >= l) {
      int mid = l + (r - l) / 2;
 
      if (arr[mid] == x){
         return mid;
      }
 
      if (arr[mid] > x){
         return binarySearch(arr, l, mid - 1, x);
      }
 
      return binarySearch(arr, mid + 1, r, x);
   }

   return -1;
}

void insertionSort(int arr[], int n) {
   int i, key, j;
   for (i = 1; i < n; i++) {
       key = arr[i];
       j = i - 1;
 
       while (j >= 0 && arr[j] > key) {
           arr[j + 1] = arr[j];
           j = j - 1;
       }
       arr[j + 1] = key;
   }
}

int main() {
   int arr[] = {3, 9, 4, 7, 2, 6, 1};
   int n = sizeof(arr) / sizeof(arr[0]);
   int x = 4;

   // Sort the array using Insertion Sort
   insertionSort(arr, n);

   // Search for the element x using Binary Search
   int result = binarySearch(arr, 0, n - 1, x);

   // Print the result
   if (result == -1) {
      printf("Element is not present in the array.\n");
   }
   else {
      printf("Element is present at index %d.\n", result);
   }

   return 0;
}