//FormAI DATASET v1.0 Category: Sorting ; Style: synchronous
#include <stdio.h>

// function prototype
void bubble_sort(int array[], int size);

int main() {
  // example array
  int num_array[] = {23, 1, 45, 5, 8, 3, 56, 98, 9, 76};

  // determine size of array
  int size = sizeof(num_array)/sizeof(num_array[0]);

  // print original array
  printf("Original Array: \n");
  for(int i = 0; i < size; i++){
    printf("%d ", num_array[i]);
  }
  printf("\n\n");

  // call bubble sort function
  bubble_sort(num_array, size);

  // print sorted array
  printf("Sorted Array: \n");
  for(int i = 0; i < size; i++){
    printf("%d ", num_array[i]);
  }
  printf("\n");

  return 0;
}

// bubble sort function
void bubble_sort(int array[], int size){
  int temp;
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}