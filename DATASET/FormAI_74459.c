//FormAI DATASET v1.0 Category: Memory management ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the memory management program!\n");
  int *nums = (int*) malloc(10 * sizeof(int));
  if (nums == NULL) {
    printf("Error: malloc failed to allocate memory.\n");
    exit(1);
  } else {
    printf("Successfully allocated memory using malloc!\n");
  }

  for (int i = 0; i < 10; i++) {
    nums[i] = i * 2;
  }

  printf("Printing contents of nums array:\n");
  for (int i = 0; i < 10; i++) {
    printf("%d ", *(nums + i));
  }
  printf("\n");

  printf("Increasing the size of the array using realloc...\n");
  nums = (int*) realloc(nums, 20 * sizeof(int));
  if (nums == NULL) {
    printf("Error: realloc failed to allocate memory.\n");
    free(nums);
    exit(1);
  } else {
    printf("Successfully reallocated memory using realloc!\n");
    for (int i = 10; i < 20; i++) {
      nums[i] = i * 2;
    }

    printf("Printing updated contents of nums array:\n");
    for (int i = 0; i < 20; i++) {
      printf("%d ", *(nums + i));
    }
    printf("\n");
  }

  printf("Freeing memory...\n");
  free(nums);
  printf("Memory has been successfully freed!\n");

  return 0;
}