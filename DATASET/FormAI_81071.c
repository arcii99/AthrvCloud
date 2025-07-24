//FormAI DATASET v1.0 Category: Sorting ; Style: random
// This program sorts an array of integers in ascending order using the bubble sort algorithm.
// It is easy to understand and implement, but inefficient for large data sets.
// But here, we will add a unique twist to it - the array will be sorted using random comparisons!

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ARRAY_SIZE 10

int main() {
  int i,j;
  int array[ARRAY_SIZE]; // Initialize an array of size 10
  srand(time(NULL)); // Seed the random number generator with the current time

  // Populate the array with random integers between 0 and 100
  for(i=0;i<ARRAY_SIZE;i++) {
    array[i] = rand()%100;
  }

  // Display the unsorted array
  printf("Unsorted array: ");
  for(i=0;i<ARRAY_SIZE;i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  // Sort the array using random comparisons
  for(i=0;i<ARRAY_SIZE;i++) {
    for(j=i+1;j<ARRAY_SIZE;j++) {
      if(rand()%2 && array[i]>array[j]) { // Random comparison
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }

  // Display the sorted array
  printf("Sorted array: ");
  for(i=0;i<ARRAY_SIZE;i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  return 0;
}