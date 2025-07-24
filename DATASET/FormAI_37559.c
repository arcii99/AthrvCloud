//FormAI DATASET v1.0 Category: Sorting ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int size) {
  for(int i=0; i < size-1; i++) {
    for(int j=0; j < size-i-1; j++) {
      if(arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

void selectionSort(int arr[], int size) {
  for(int i=0; i < size-1; i++) {
    int minIndex = i;
    for(int j=i+1; j < size; j++) {
      if(arr[minIndex] > arr[j]) {
        minIndex = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
  }
}

void insertionSort(int arr[], int size) {
  for(int i=1; i < size; i++) {
    int current = arr[i];
    int j = i - 1;
    while(j >= 0 && arr[j] > current) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = current;
  }
}

int main() {
  int arr[] = {3, 7, 1, 9, 5};
  int size = 5;

  printf("Original Array: ");
  for(int i=0; i<size; i++) {
    printf("%d ", arr[i]);
  }

  // Sort with Bubble Sort
  bubbleSort(arr, size);
  printf("\nSorted Array using Bubble Sort: ");
  for(int i=0; i<size; i++) {
    printf("%d ", arr[i]);
  }

  // Sort with Selection Sort
  selectionSort(arr, size);
  printf("\nSorted Array using Selection Sort: ");
  for(int i=0; i<size; i++) {
    printf("%d ", arr[i]);
  }

  // Sort with Insertion Sort
  insertionSort(arr, size);
  printf("\nSorted Array using Insertion Sort: ");
  for(int i=0; i<size; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}