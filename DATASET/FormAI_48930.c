//FormAI DATASET v1.0 Category: Memory management ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {

  printf("Welcome to the Memory Arcade!\n");
  printf("Let's play a game of Memory Management!\n\n");

  // Allocate memory for five integers
  int *nums = (int*) malloc(5 * sizeof(int));
  if (nums == NULL) {
    printf("Oops! Memory allocation error.\n");
    printf("Please try again later.\n");
    return 1;
  }

  // Set values for the five integers
  for (int i = 0; i < 5; i++) {
    nums[i] = i + 1;
  }

  // Display the values
  printf("Here are the numbers you have:\n");
  for (int i = 0; i < 5; i++) {
    printf("%d\n", nums[i]);
  }

  // Release the memory
  free(nums);

  printf("\nCongratulations, you won Memory Management!\n");
  printf("Come back to the Memory Arcade soon!\n");

  return 0;
}