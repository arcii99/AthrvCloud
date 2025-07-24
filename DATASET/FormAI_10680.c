//FormAI DATASET v1.0 Category: Sorting ; Style: satisfied
#include <stdio.h>

int main() {
   int arr[10], temp;
   int i, j, index, size = 10;
   
   // Prompt user to enter array elements
   printf("Enter %d integers: ", size);
   for(i=0; i<size; i++)
      scanf("%d", &arr[i]);
   
   // Sort the array in ascending order using Selection Sort
   for(i=0; i<size-1; i++) {
      index = i;
      for(j=i+1; j<size; j++) {
         if(arr[j] < arr[index])
            index = j;
      }
      temp = arr[i];
      arr[i] = arr[index];
      arr[index] = temp;
   }
   
   // Display the sorted array
   printf("\nSorted Array: ");
   for(i=0; i<size; i++)
      printf("%d ", arr[i]);
   
   return 0;
}