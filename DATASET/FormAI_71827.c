//FormAI DATASET v1.0 Category: Sorting ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int n) {
  int i, j, temp;
  for(i = 0; i < n-1; i++) {
    for(j = 0; j < n-i-1; j++) {
      // Checking if element at index j is greater than element at index j+1
      if(arr[j] > arr[j+1]) {
        // Swapping elements
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

int main() {
  int n, i;
  printf("Enter the number of elements in the array:\n");
  scanf("%d", &n);
  int arr[n];
  printf("Enter %d elements of the array:\n", n);
  for(i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  
  printf("\nBefore Sorting:\n");
  for(i = 0; i < n; i++)
    printf("%d ", arr[i]);
  
  // Sorting array in ascending order using Bubble Sort
  bubble_sort(arr, n);
  
  printf("\nAfter Sorting:\n");
  for(i = 0; i < n; i++)
    printf("%d ", arr[i]);
  
  return 0;
}