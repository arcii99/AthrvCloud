//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

int main() {
   //Declare variables
   int n, i, j, temp, minIndex;
   int *arr;
  
   //Take array size from the user
   printf("Enter the size of the array: ");
   scanf("%d", &n);

   //Allocate memory dynamically
   arr = (int*)malloc(n*sizeof(int));

   //Take array elements from the user
   printf("Enter the array elements:\n");
   for(i=0; i<n; i++) {
      scanf("%d", &arr[i]);
   }

   //Greedy Algorithm (Selection Sort)
   for(i=0; i<n-1; i++) {
      minIndex = i;

      for(j=i+1; j<n; j++) {
         if(arr[j] < arr[minIndex]) {
            minIndex = j;
         }
      }

      //Swap the elements
      temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;
   }

   //Print the sorted array
   printf("\nSorted Array:\n");
   for(i=0; i<n; i++) {
      printf("%d ", arr[i]);
   }

   //Free the dynamically allocated memory
   free(arr);

   return 0;
}