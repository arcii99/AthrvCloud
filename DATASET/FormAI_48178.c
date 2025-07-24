//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Alan Touring
#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
   for(int i=0; i<n; i++) {
      if(arr[i] == key) {
         return i;
      }
   }
   return -1;
}

int main() {
   int arr[] = {3, 9, 4, 6, 7, 1};
   int n = sizeof(arr)/sizeof(arr[0]);

   int key = 7;
   int found = linearSearch(arr, n, key);

   if(found == -1) {
      printf("Element not found\n");
   } else {
      printf("Element found at index %d\n", found);
   }

   return 0;
}