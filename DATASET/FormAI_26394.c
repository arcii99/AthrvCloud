//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Donald Knuth
#include<stdlib.h>
#include<stdio.h>

// Define an array to be sorted
int array[] = {15, 3, 9, 8, 5, 2, 7, 1, 6, 4};

// Define a function to perform Bucket Sort
void bucket_sort(int array[], int n) {
   int i, j;
   int count[n];

   // Initialize all elements of count[] to 0
   for (i = 0; i < n; i++)
      count[i] = 0;

   // Count the number of times each element appears in array[]
   for (i = 0; i < n; i++)
      (count[array[i]])++;

   // Sort the elements of array[] using count[]
   for (i = 0, j = 0; i < n; i++) 
      for(; count[i]; count[i]--) 
         array[j++] = i;
}

// Main Function
int main() {
   int i, n = sizeof(array)/sizeof(array[0]);
   bucket_sort(array, n);

   // Print the sorted array
   printf("Sorted array: \n");
   for (i = 0; i < n; i++)
      printf("%d ", array[i]);
   printf("\n");
   return 0;
}