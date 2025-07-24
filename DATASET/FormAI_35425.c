//FormAI DATASET v1.0 Category: Sorting ; Style: enthusiastic
#include<stdio.h>

int main() {
  // Declare and initialize an array of integers
  int arr[] = {8, 3, 10, 1, 7};
  
  // Get the length of the array
  int len = sizeof(arr)/sizeof(arr[0]);
  
  // Print the unsorted array
  printf("Unsorted Array: ");
  for(int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  
  // Sort the array using Bubble Sort Algorithm
  int temp;
  for(int i = 0; i < len-1; i++) {
    for(int j = 0; j < len-i-1; j++) {
      if(arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

  // Print the sorted array
  printf("\nSorted Array: ");
  for(int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  
  return 0;
}