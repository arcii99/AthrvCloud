//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: surrealist
#include <stdio.h>

int main() {
   int i, j, n, sum = 0, max;
   int arr[100];

   // ask the user for the size of the array
   printf("Enter the size of the array: ");
   scanf("%d", &n);

   // ask the user to input the elements of the array
   printf("Enter the elements of the array: ");
   for (i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }

   // sort the array in ascending order
   for (i = 0; i < n; i++) {
      for (j = i + 1; j < n; j++) {
         if (arr[i] > arr[j]) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
         }
      }
   }

   // calculate the maximum sum of a continuous subarray
   for (i = 0; i < n; i++) {
      sum += arr[i];
      if (sum < 0) {
         sum = 0;
      }
      if (sum > max) {
         max = sum;
      }
   }

   // print the maximum sum
   printf("The maximum sum of a continuous subarray is: %d", max);

   return 0;
}