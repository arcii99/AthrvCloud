//FormAI DATASET v1.0 Category: Searching algorithm ; Style: automated
#include <stdio.h>

int linearSearch(int arr[], int n, int x) {
   for (int i = 0; i < n; i++) {
      if (arr[i] == x)
         return i;
   }
   return -1;  
}

int main() {
   int arr[] = { 2, 3, 4, 10, 40 };
   int n = sizeof(arr) / sizeof(arr[0]);
   int x = 10;
   int resultIndex = linearSearch(arr, n, x);
   if (resultIndex == -1)
      printf("Element is not present in array");
   else
      printf("Element is present at index %d", resultIndex);
   return 0;
}