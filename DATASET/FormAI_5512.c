//FormAI DATASET v1.0 Category: Sorting ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

void quickSort(int[], int, int);
int partition(int[], int, int);

int main() {
  int arr[] = {8, 4, 15, 2, 9, 5, 7, 13, 1, 6, 12, 3, 10, 11, 14}; // Sample array
  int n = sizeof(arr) / sizeof(arr[0]); // Size of array
  
  printf("Unsorted array: ");
  for(int i = 0; i < n; i++){
    printf("%d ", arr[i]); // Print unsorted array
  }

  quickSort(arr, 0, n - 1); // Sort the array

  printf("\n\nSorted array: ");
  for(int i = 0; i < n; i++){
    printf("%d ", arr[i]); // Print sorted array
  }
  
  return 0;
}

void quickSort(int arr[], int low, int high) {
  if(low < high) {
    int pivotIndex = partition(arr, low, high); // Find partition index
    
    quickSort(arr, low, pivotIndex - 1); // Sort left sub array
    quickSort(arr, pivotIndex + 1, high); // Sort right sub array
  }
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high]; // Pivot element
  int i = low - 1; // Starting index

  for(int j = low; j <= high - 1; j++){
    if(arr[j] < pivot){
      i++; // Increment index
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp; // Swap element
    }
  }
  int temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp; // Swap element
  
  return i + 1;
}