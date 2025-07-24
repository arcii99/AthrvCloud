//FormAI DATASET v1.0 Category: Sorting ; Style: creative
// Welcome to the sorting program that sorts numbers randomly!
// Here, we are not sorry for the mess we create while sorting.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int arr[10];
  int i, j, temp;
  srand(time(NULL)); // Seed for random number generator
  
  // Initializing array with random numbers
  printf("Unsorted array: ");
  for(i=0;i<10;i++){
    arr[i] = rand() % 100; // Random number between 0 and 99
    printf("%d ", arr[i]);
  }
  
  // Sorting array using Bubble Sort algorithm
  for(i=0;i<9;i++){
    for(j=0;j<10-i-1;j++){
      if(arr[j]>arr[j+1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  
  // Displaying sorted array
  printf("\n\nSorted array: ");
  for(i=0;i<10;i++){
    printf("%d ", arr[i]);
  }
  
  return 0;
}