//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: dynamic
#include <stdio.h>

int main() {
   int n, i, j, temp;
   printf("Enter number of elements: ");
   scanf("%d", &n);
   int arr[n];

   printf("Enter elements:\n");
   for(i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }

   // sorting the array using selection sort
   for(i = 0; i < n-1; i++) {
      for(j = i+1; j < n; j++) {
         if(arr[i] > arr[j]) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
         }
      }
   }

   // calculating the minimum difference
   int min_diff = arr[1] - arr[0];
   for(i = 2; i < n; i++) {
      if((arr[i] - arr[i-1]) < min_diff) {
         min_diff = arr[i] - arr[i-1];
      }
   }

   printf("Minimum difference is %d", min_diff);
   return 0;
}