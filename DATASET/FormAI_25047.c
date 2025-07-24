//FormAI DATASET v1.0 Category: Sorting ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Function to print the array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

// Function to perform bubble sort
void bubbleSort(int arr[], int size) {
  int temp;
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main() {
  int size;
  printf("Enter the size of the array: ");
  scanf("%d", &size);

  int *arr = (int *)malloc(size * sizeof(int));
  printf("Enter the elements separated by space: ");

  for (int i = 0; i < size; i++)
    scanf("%d", &arr[i]);

  printf("The original array is: ");
  printArray(arr, size);

  bubbleSort(arr, size);

  printf("The sorted array is: ");
  printArray(arr, size);

  free(arr);
  return 0;
}