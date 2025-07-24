//FormAI DATASET v1.0 Category: Error handling ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main() {
  int user_input;
  printf("Please enter a number between 1 and 10: ");
  scanf("%d", &user_input);

  if (user_input < 1 || user_input > 10) {
    printf("Error: invalid input. Please enter a number between 1 and 10.\n");
    exit(EXIT_FAILURE);
  }

  int result = 100 / user_input;
  printf("100 divided by %d is %d\n", user_input, result);

  // If everything works well, return 0
  return 0;
}