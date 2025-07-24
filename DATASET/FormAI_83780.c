//FormAI DATASET v1.0 Category: Searching algorithm ; Style: ephemeral
#include <stdio.h>

//function to search for a value in an array
int search(int arr[], int n, int x) {
   int i;
   for (i = 0; i < n; i++)
      if (arr[i] == x)
         return i;
   return -1;
}

int main() {
   int arr[100], n, x, result;
   int i;
   printf("Enter size of array: ");
   scanf("%d", &n);
   printf("Enter array elements: ");
   for(i=0; i<n; i++) {
      scanf("%d", &arr[i]);
   }
   printf("Enter element to be searched: ");
   scanf("%d", &x);
   result = search(arr, n, x);
   if(result == -1) {
      printf("Element not found");
   } else {
      printf("Element found at index %d", result);
   }
   return 0;
}