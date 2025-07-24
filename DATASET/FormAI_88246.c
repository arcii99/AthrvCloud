//FormAI DATASET v1.0 Category: Memory management ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
  int size = 5;
  int* arr = (int*)malloc(size * sizeof(int));
  
  if (arr == NULL) {
    printf("Out of memory!\n");
    return 1;
  }
  
  for (int i = 0; i < size; i++) {
    arr[i] = i * i;
  }

  printf("Array contents:\n");
  for (int i = 0; i < size; i++) {
    printf("%d\n", arr[i]);
  }

  free(arr);

  size = 7;
  arr = (int*)malloc(size * sizeof(int));

  if (arr == NULL) {
    printf("Out of memory!\n");
    return 1;
  }

  for (int i = 0; i < size; i++) {
    arr[i] = i * i * i;
  }

  printf("New array contents:\n");
  for (int i = 0; i < size; i++) {
    printf("%d\n", arr[i]);
  }

  free(arr);

  return 0;
}