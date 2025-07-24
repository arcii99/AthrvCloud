//FormAI DATASET v1.0 Category: Sorting ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int n) {
  int i, j, temp;
  
  for (i = 0; i < n-1; i++) {
    for (j = 0; j < n-i-1; j++) {
      if (arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

void display_array(int arr[], int n) {
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main() {
  int n = 10;
  int arr[] = {7, 2, 9, 1, 4, 6, 5, 8, 3, 0};
  
  printf("Before sorting: ");
  display_array(arr, n);
  
  bubble_sort(arr, n);
  
  printf("After sorting: ");
  display_array(arr, n);
  
  return 0;
}