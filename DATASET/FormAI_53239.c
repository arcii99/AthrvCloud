//FormAI DATASET v1.0 Category: Sorting ; Style: bold
#include <stdio.h>

int main() {
  int arr[] = {5, 8, 2, 0, 3, 1};
  int n = 6;

  printf("Original array:\n");
  for(int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // Bubble sort
  for(int i = 0; i < n-1; i++) {
    for(int j = 0; j < n-i-1; j++) {
      if(arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }

  printf("Sorted array using Bubble Sort:\n");
  for(int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // Selection Sort
  for(int i = 0; i < n-1; i++) {
    int min = i;
    for(int j = i+1; j < n; j++) {
      if(arr[j] < arr[min]) {
        min = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
  }

  printf("Sorted array using Selection Sort:\n");
  for(int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // Insertion Sort
  for(int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while(j >= 0 && arr[j] > key) {
      arr[j+1] = arr[j];
      j = j - 1;
    }
    arr[j+1] = key;
  }

  printf("Sorted array using Insertion Sort:\n");
  for(int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}