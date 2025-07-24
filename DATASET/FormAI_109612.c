//FormAI DATASET v1.0 Category: Sorting ; Style: intelligent
#include <stdio.h>

int main() {
  // initialize the array of values to sort
  int values[] = {3, 8, 1, 6, 0, 5, 2, 7, 4, 9};
  
  // find the number of values in the array
  int num_values = sizeof(values) / sizeof(int);
  
  // print the initial list of values
  printf("Before sorting:\n");
  for (int i = 0; i < num_values; i++) {
    printf("%d ", values[i]);
  }
  
  // perform selection sort on the array of values
  for (int i = 0; i < num_values; i++) {
    int min_index = i;
    for (int j = i + 1; j < num_values; j++) {
      if (values[j] < values[min_index]) {
        min_index = j;
      }
    }
    int temp = values[i];
    values[i] = values[min_index];
    values[min_index] = temp;
  }
  
  // print the final sorted list of values
  printf("\nAfter sorting:\n");
  for (int i = 0; i < num_values; i++) {
    printf("%d ", values[i]);
  }
  
  return 0;
}