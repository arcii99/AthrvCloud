//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: puzzling
#include <stdio.h>

int main() {
   int n;
   printf("How many elements in the array? ");
   scanf("%d", &n);

   int arr[n];
   printf("Enter the array elements: ");

   for(int i=0; i<n; i++) {
      scanf("%d", &arr[i]);
   }

   printf("The array: ");
   for(int i=0; i<n; i++) {
      printf("%d ", arr[i]);
   }

   int k;
   printf("\nEnter the value of k: ");
   scanf("%d", &k);

   int sum = 0, minSum = 0, minIndex = -1;
   for(int i=0; i<k; i++) {
      sum += arr[i];
   }
   minSum = sum;

   for(int i=k; i<n; i++) {
      sum += arr[i] - arr[i-k];
      if(sum < minSum) {
         minSum = sum;
         minIndex = i-k+1;
      }
   }

   printf("The subarray with minimum sum is: ");
   for(int i=minIndex; i<minIndex+k; i++) {
      printf("%d ", arr[i]);
   }
   printf("\n");
   
   return 0;
}