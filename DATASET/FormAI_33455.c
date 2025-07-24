//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: thoughtful
#include <stdio.h>

int main()
{
   int n, i, j, temp;
   printf("Enter the number of elements: ");
   scanf("%d", &n);

   int arr[n];
   printf("Enter %d elements:\n", n);

   for(i = 0; i < n; i++)
      scanf("%d", &arr[i]);

   // Applying Selection Sort Algorithm
   for(i = 0; i < n-1; i++)
   {
      int min_idx = i;

      for(j = i+1; j < n; j++)
      {
         if(arr[j] < arr[min_idx])
            min_idx = j;
      }

      temp = arr[min_idx];
      arr[min_idx] = arr[i];
      arr[i] = temp;
   }

   printf("Sorted array using Selection Sort: \n");

   for(i = 0; i < n; i++)
      printf("%d ", arr[i]);

   return 0;
}