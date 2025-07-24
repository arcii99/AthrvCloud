//FormAI DATASET v1.0 Category: Sorting ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int main() {
  int n, i;
  printf("Enter the length of the array: ");
  scanf("%d", &n);
  int arr[n];
  srand(time(NULL));
  for (i = 0; i < n; i++) {
     arr[i] = rand() % 100;
  }
  printf("Original Array: ");
  for (i = 0; i < n; i++) {
     printf("%d ", arr[i]);
  }
  bubble_sort(arr, n);
  printf("\nSorted Array: ");
  for (i = 0; i < n; i++) {
     printf("%d ", arr[i]);
  }
  return 0;
}