//FormAI DATASET v1.0 Category: Sorting ; Style: immersive
#include <stdio.h>

int main() {
  printf("Welcome to the Sorting Immersion Program!\n");
  printf("In this program, you will experience the wonders of sorting as if you were immersed in a game.\n");

  printf("Let's get started by creating an array of random numbers.\n");
  int arr[10] = {4, 2, 8, 6, 1, 3, 9, 7, 5, 0};
  
  // Print out the original array
  printf("Original Array: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  
  printf("Now we will begin the sorting process...\n");

  int temp; // Temporary storage variable

  // Bubble Sort
  printf("\nBubble Sorting...\n");
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 9; j++) {
      if (arr[j] > arr[j+1]) {
        // Swap the elements
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  // Print out the sorted array
  printf("Sorted Array: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // Selection Sort
  printf("\nSelection Sorting...\n");
  for (int i = 0; i < 9; i++) {
    int minIdx = i;
    for (int j = i+1; j < 10; j++) {
      if (arr[j] < arr[minIdx]) {
        minIdx = j;
      }
    }
    // Swap the elements
    temp = arr[i];
    arr[i] = arr[minIdx];
    arr[minIdx] = temp;
  }
  // Print out the sorted array
  printf("Sorted Array: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // Insertion Sort
  printf("\nInsertion Sorting...\n");
  for (int i = 1; i < 10; i++) {
    int key = arr[i];
    int j = i-1;
    while (j >= 0 && arr[j] > key) {
      arr[j+1] = arr[j];
      j = j-1;
    }
    arr[j+1] = key;
  }
  // Print out the sorted array
  printf("Sorted Array: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  printf("\nCongratulations! You have successfully completed the Sorting Immersion Program.\n");
  return 0;
}