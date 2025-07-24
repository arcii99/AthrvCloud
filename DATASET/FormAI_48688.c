//FormAI DATASET v1.0 Category: Memory management ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int *arr; // declaring a pointer for integer array
  int size, i;
 
  printf("Enter the size of the array: ");
  scanf("%d", &size);

  arr = (int*) calloc(size, sizeof(int)); // allocating memory dynamically
 
  if (arr == NULL)  {
     printf("Memory allocation failed!\n");
     exit(0);
  }
  
  printf("Enter %d elements into the array:\n", size);
  for(i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  printf("The elements in the array are: ");
  for(i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  
  free(arr); // deallocate the memory
  
  return 0;
}