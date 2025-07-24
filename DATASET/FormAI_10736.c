//FormAI DATASET v1.0 Category: Searching algorithm ; Style: romantic
#include <stdio.h>

int linearSearch(int arr[], int n, int x) {
   for(int i=0;i<n;i++) {
      if(arr[i]==x)
         return i;
   }
   return -1;
}

int main() {
   int n, x;
   printf("Enter the size of the array: ");
   scanf("%d", &n);
   int arr[n];
   printf("Enter the elements of the array:\n");
   for(int i=0;i<n;i++) {
      scanf("%d", &arr[i]);
   }
   printf("Enter the element to be searched: ");
   scanf("%d", &x);
   int result = linearSearch(arr, n, x);
   if(result == -1) {
      printf("Element not found\n");
   } else {
      printf("Element found at index: %d\n", result);
   }
   return 0;
}