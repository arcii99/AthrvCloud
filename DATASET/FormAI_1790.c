//FormAI DATASET v1.0 Category: Memory management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main() {
  // simple memory allocation example
  int n = 10;
  int *arr = (int*) malloc(n * sizeof(int));
  
  // if allocation fails
  if (arr == NULL) {
    printf("Memory allocation failed.\n");
    return 0;
  }
  
  // set values of dynamic array
  for (int i = 0; i < n; i++) {
    arr[i] = i;
  }
  
  // print values of dynamic array
  printf("Dynamic array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  
  // reallocate memory example
  int m = 15;
  int *new_arr = (int*) realloc(arr, m * sizeof(int));
  
  // if reallocation fails
  if (new_arr == NULL) {
    printf("\nMemory reallocation failed.\n");
    return 0;
  }
  
  // set remaining values of dynamic array
  for (int i = n; i < m; i++) {
    new_arr[i] = i;
  }
  
  // print new values of expanded dynamic array
  printf("\nExpanded dynamic array: ");
  for (int i = 0; i < m; i++) {
    printf("%d ", new_arr[i]);
  }
  
  // free allocated memory
  free(new_arr);
  
  return 0;
}