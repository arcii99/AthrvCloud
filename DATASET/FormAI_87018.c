//FormAI DATASET v1.0 Category: Memory management ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main() 
{
  // Allocate memory for an array of size 5
  int* arr = (int*) malloc(5 * sizeof(int));
  
  if (arr == NULL) 
  {
    printf("Memory allocation failed.\n");
    return 0;
  }
  
  // Set some values in the array
  for(int i = 0; i < 5; i++) 
  {
    arr[i] = i * 2;
  }
  
  // Print out the values in the array
  for(int i = 0; i < 5; i++) 
  {
    printf("%d ", arr[i]);
  }
  
  // Reallocate memory for an array of size 10
  arr = (int*) realloc(arr, 10 * sizeof(int));
  
  if (arr == NULL) 
  {
    printf("Memory reallocation failed.\n");
    return 0;
  }
  
  // Set some more values in the array
  for(int i = 5; i < 10; i++) 
  {
    arr[i] = i * 2;
  }
  
  // Print out the values in the array
  for(int i = 0; i < 10; i++) 
  {
    printf("%d ", arr[i]);
  }
  
  // Free the memory allocated for the array
  free(arr);
  
  return 0;
}