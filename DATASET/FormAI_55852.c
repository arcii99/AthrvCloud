//FormAI DATASET v1.0 Category: Sorting ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define function for bubble sort algorithm
void bubbleSort(int arr[], int n) {
  int i, j;
  for (i = 0; i < n-1; i++) {
    for (j = 0; j < n-i-1; j++) {
      if (arr[j] > arr[j+1]) {
        // swap arr[j] with arr[j+1] using XOR operator
        arr[j] = arr[j] ^ arr[j+1];
        arr[j+1] = arr[j] ^ arr[j+1];
        arr[j] = arr[j] ^ arr[j+1];
      }
    }
  }
}

int main() {
  srand(time(NULL)); //seed random number generator
  int arr[10]; //declare integer array of size 10

  // fill array with random integers between 1 and 100
  for (int i = 0; i < 10; i++) {
    arr[i] = rand() % 100 + 1;
  }

  //print unsorted array
  printf("Unsorted array: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  bubbleSort(arr, 10); //sort the array using bubble sort

  //print sorted array
  printf("Sorted array: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0; //exit program
}