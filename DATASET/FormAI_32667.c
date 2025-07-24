//FormAI DATASET v1.0 Category: Searching algorithm ; Style: shocked
#include<stdio.h>

int search(int arr[], int n, int x) {
   int i;
   for (i = 0; i < n; i++) {
      if (arr[i] == x)
         return i;
   }
   return -1;
}

int main() {
   int arr[] = {10, 20, 30, 40, 50};
   int n = sizeof(arr) / sizeof(arr[0]);
   int x = 30;
   
   int result = search(arr, n, x);
   if(result == -1)
      printf("Oops! %d is not present in this array.\n", x);
   else
      printf("Wow! %d is present at index %d in this array.\n", x, result);
      
   return 0;
}