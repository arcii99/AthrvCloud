//FormAI DATASET v1.0 Category: Memory management ; Style: lively
#include<stdio.h>
#include<stdlib.h>

int* allocateMemory(int size) {
  int* ptr = (int*)malloc(size * sizeof(int));
  if (ptr == NULL) {
    printf("Memory allocation failed!\n");
    exit(1);
  }
  return ptr;
}

int main() {
  printf("Welcome to the Memory Management Program!\n");
  
  int size;
  printf("Enter the size of the array: ");
  scanf("%d", &size);
  
  int* array = allocateMemory(size);
  
  printf("Enter the array elements: ");
  for (int i = 0; i < size; i++) {
    scanf("%d", &array[i]);
  }
  
  printf("The array elements are: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  
  free(array);
  printf("\nMemory has been freed!\n");
  
  return 0;
}