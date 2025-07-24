//FormAI DATASET v1.0 Category: Sorting ; Style: genious
#include <stdio.h>

int main() {

  // Initialize the array to sort
  int arr[] = {9, 2, 5, 1, 7, 3, 8, 6, 4};

  // Determine the length of the array
  int arr_length = sizeof(arr)/sizeof(arr[0]);

  // Print the unsorted array
  printf("Unsorted Array:\n");
  for (int i = 0; i < arr_length; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // Begin the sorting algorithm - Bubble Sort
  int temp;
  for (int i = 0; i < arr_length - 1; i++) {
    for (int j = 0; j < arr_length - i - 1; j++) {
      if (arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

  // Print the sorted array
  printf("Sorted Array:\n");
  for (int i = 0; i < arr_length; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  
  // End of program
  return 0;
}