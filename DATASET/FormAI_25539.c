//FormAI DATASET v1.0 Category: Sorting ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This program will sort an array of randomly generated numbers in a funny way

int main() {
  int i, j, temp;
  int arr[10];
  srand(time(NULL));
  
  // Fill array with random numbers
  printf("Unsorted array: ");
  for (i = 0; i < 10; i++) {
    arr[i] = rand() % 100 + 1;
    printf("%d ", arr[i]);
  }
  
  // Bubble sort algorithm with a twist
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 9; j++) {
      if (arr[j] > arr[j+1]) {
        printf("\n\nWhoops! We need to swap %d and %d\n\n", arr[j], arr[j+1]);
        printf("Press any key to continue . . .\n");
        // Wait for user input before swapping
        getchar();
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  
  // Print sorted array
  printf("\n\nSorted array: ");
  for (i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }
  
  return 0;
}