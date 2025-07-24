//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: imaginative
#include <stdio.h>

int main()
{
   int n, m, i, j, k;
   printf("Enter the number of elements in the array: ");
   scanf("%d", &n);
   
   int arr[n];
   printf("Enter the elements of the array: ");
   for(i=0; i<n; i++) scanf("%d", &arr[i]);
   
   printf("Enter the maximum number of elements to be selected: ");
   scanf("%d", &m);
   
   printf("Selected elements are: ");
   // Greedy algorithm begins
   for(i=0; i<m; i++)
   {
      int max = arr[0];
      k = 0;
      for(j=1; j<n; j++)
      {
         if(arr[j] > max)
         {
            max = arr[j];
            k = j;
         }
      }
      printf("%d ", max);
      arr[k] = -1; // mark as selected
   }
   // Greedy algorithm ends 
   return 0;
}