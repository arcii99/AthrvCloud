//FormAI DATASET v1.0 Category: Memory management ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

int main() {
  int size;
  printf("Enter the number of integers you want to store: ");
  scanf("%d", &size);

  // Allocate memory dynamically
  int* arr = (int*)malloc(size * sizeof(int));

  // Populate the array
  for (int i = 0; i < size; i++) {
    printf("Enter value of element %d: ", i+1);
    scanf("%d", &arr[i]);
  }

  // Compute sum of all elements in the array
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }

  printf("The sum of all %d elements in the array is: %d\n", size, sum);

  // Deallocate memory
  free(arr);

  return 0;
}