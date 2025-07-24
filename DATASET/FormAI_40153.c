//FormAI DATASET v1.0 Category: Computer Biology ; Style: satisfied
#include <stdio.h>

int main() {
   int i, n;
   float sum = 0, avg, min, max;
   printf("Enter the number of elements: ");
   scanf("%d",&n);
   float arr[n];
   printf("\nEnter the elements: ");

   for(i=0;i<n;i++) {
      scanf("%f",&arr[i]);
      sum += arr[i];
   }

   // Calculating average
   avg = sum/n;
   printf("\nAverage: %.2f", avg);

   // Finding the minimum value
   min = arr[0];
   for(i=1;i<n;i++) {
      if(arr[i] < min)
         min = arr[i];
   }
   printf("\nMinimum value: %.2f", min);

   // Finding the maximum value
   max = arr[0];
   for(i=1;i<n;i++) {
      if(arr[i] > max)
         max = arr[i];
   }
   printf("\nMaximum value: %.2f", max);

   return 0;
}