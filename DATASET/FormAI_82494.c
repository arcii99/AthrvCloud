//FormAI DATASET v1.0 Category: Searching algorithm ; Style: all-encompassing
#include <stdio.h>

int search(int arr[], int n, int x) {
   for(int i=0; i<n; i++) {
      if(arr[i] == x) {
         return i;
      }
   }
   return -1;
}

int main() {
   int arr[] = {10, 20, 30, 40, 50, 60};
   int n = sizeof(arr) / sizeof(arr[0]);
   int x = 50;
   int result = search(arr, n, x);
   
   if(result == -1) {
      printf("Element is not present in array\n");
   } else {
      printf("Element is present at index %d\n", result);
   }
   return 0;
}