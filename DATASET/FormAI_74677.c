//FormAI DATASET v1.0 Category: Memory management ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int* ptr1;
  int* ptr2;
  int* ptr3;
  int* ptr4;

  // allocate memory using malloc() function
  ptr1 = (int*) malloc(10 * sizeof(int));
  ptr2 = (int*) malloc(20 * sizeof(int));
  ptr3 = (int*) malloc(30 * sizeof(int));

  // allocate memory blocks using calloc() function
  ptr4 = (int*) calloc(5, sizeof(int));

  if (ptr1 == NULL || ptr2 == NULL || ptr3 == NULL || ptr4 == NULL){
    printf("Memory allocation failed! Program terminated.\n");
    exit(1);
  }

  // free memory
  free(ptr1);
  free(ptr2);
  free(ptr3);
  free(ptr4);

  printf("Memory allocation and deallocation completed successfully!\n");

  return 0;
}