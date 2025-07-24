//FormAI DATASET v1.0 Category: Sorting ; Style: surprised
#include <stdio.h>

int main() {
  int arr[10] = {5, 2, 9, 1, 7, 4, 8, 3, 6, 0};
  int n = 10;
  printf("Original array: ");
  for(int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  
  printf("\n\nSorting array using Bubble Sort...\n");
  
  // Bubble Sort Algorithm
  for(int i = 0; i < n-1; i++) {
    for(int j = 0; j < n-i-1; j++) {
      if(arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  
  printf("\nSorted array: ");
  for(int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  
  printf("\n\nSorting array using Selection Sort...\n");
  
  // Selection Sort Algorithm
  for(int i = 0; i < n-1; i++) {
    int min_index = i;
    for(int j = i+1; j < n; j++) {
      if(arr[j] < arr[min_index]) {
        min_index = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[min_index];
    arr[min_index] = temp;
  }
  
  printf("\nSorted array: ");
  for(int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  
  printf("\n\nSorting array using Insertion Sort...\n");
  
  // Insertion Sort Algorithm
  for(int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i-1;
    while(j >= 0 && arr[j] > key) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }
  
  printf("\nSorted array: ");
  for(int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  
  return 0;
}