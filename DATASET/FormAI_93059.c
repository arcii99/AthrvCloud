//FormAI DATASET v1.0 Category: Pattern printing ; Style: introspective
#include <stdio.h>

int main() {
  printf("Hello, I am a C program printing a unique pattern!\n\n");
  int height;

  // Get the height of the pattern from the user
  printf("Enter the height of the pattern: ");
  scanf("%d", &height);

  // Error handling for invalid input
  if (height < 1) {
    printf("Invalid input, height must be a positive integer.\n");
    return 1;
  }

  // Print the pattern
  printf("\n");
  for (int i = 1; i <= height; i++) {
    for (int j = 1; j <= i; j++) {
      printf("%d ", i * j);
    }
    printf("\n");
  }

  printf("\nI hope you enjoyed my code!\n");
  return 0;
}