//FormAI DATASET v1.0 Category: Memory management ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int main() {
  int *arr = (int*)malloc(SIZE * sizeof(int));
  
  if(arr == NULL) {
    printf("Error! Memory not allocated.");
    exit(0);
  }
  
  for(int i=0; i<SIZE; i++) {
    *(arr+i) = i+1;
  }
  
  printf("Content of array: ");
  for(int i=0; i<SIZE; i++) {
    printf("%d ", *(arr+i));
  }
  
  free(arr);
  printf("\nMemory freed!");
  
  return 0;
}