//FormAI DATASET v1.0 Category: Memory management ; Style: minimalist
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 10

void print_array(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int *arr = NULL;
  int size = 0;
  int new_size = 0;
  
  while (1) {
    printf("Size: %d, Elements: ", size);
    print_array(arr, size);
    printf("Enter a new size (0 to exit): ");
    scanf("%d", &new_size);
    
    if (new_size == 0) {
      break;
    }
    
    // Allocate memory
    int *tmp = (int *)realloc(arr, new_size * sizeof(int));
    if (tmp == NULL) {
      printf("Error: Unable to resize array.\n");
      exit(EXIT_FAILURE);
    }
    
    arr = tmp;
    
    // Initialize new elements
    for (int i = size; i < new_size; i++) {
      arr[i] = i * i;
    }
    
    size = new_size;
  }
  
  // Free memory
  free(arr);
  
  return 0;
}