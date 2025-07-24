//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(float arr[], int n) {
   // Create n buckets and initialize it
   int i, j;
   int count[n];
   for (i = 0; i < n; ++i)
      count[i] = 0;   

   // Count the number of elements in each bucket
   for (i = 0; i < n; ++i)
      ++count[(int)arr[i]];

   // Sort the elements by each bucket
   for (i = 0, j = 0; i < n; ++i)
      for (; count[i] > 0; --count[i])
         arr[j++] = i;

}

/* Main function */
int main() {
   float arr[] = {0.42, 0.32, 0.77, 0.01, 0.84, 0.56, 0.23, 0.59};
   int n = sizeof(arr)/sizeof(arr[0]);
   int i;
   printf("Array before sorting:\n");
   printf("[");
   for(i=0;i<n-1;i++){
    printf("%.2f,",arr[i]);
   }
   printf("%.2f",arr[n-1]);
   printf("]\n");
   // Sorting array using bucket sort
   bucket_sort(arr, n);

   // Display the final sorted array
   printf("\nArray after sorting:\n");
   printf("[");
   for(i=0;i<n-1;i++){
    printf("%.2f,",arr[i]);
   }
   printf("%.2f",arr[n-1]);
   printf("]");

   return 0;
}