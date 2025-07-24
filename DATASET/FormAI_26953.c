//FormAI DATASET v1.0 Category: Searching algorithm ; Style: peaceful
#include <stdio.h>

int search(int arr[], int n, int x) {
   int i;
   for (i = 0; i < n; i++) {
      if (arr[i] == x)
         return i;
   }
   return -1;
}

int main() {
   int arr[] = {2, 3, 4, 10, 40};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int x = 10;
   int result = search(arr, n, x);
   if(result == -1) {
      printf("%d not found in array.", x);
   } else {
      printf("%d found at index %d.", x, result);
   }
   return 0;
}