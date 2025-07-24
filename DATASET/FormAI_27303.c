//FormAI DATASET v1.0 Category: Error handling ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Declare input variable
  char input[10];

  // Prompt user for input
  printf("Please enter a number between 1 and 10:\n");
  scanf("%s", input);

  // Convert input to integer
  int num = atoi(input);

  // Check if input is within range
  if (num < 1 || num > 10) {
    printf("Error: Input must be between 1 and 10.\n");
    exit(1);
  }

  // Calculate and print factorial of input
  int factorial = 1;
  for (int i = 1; i <= num; i++) {
    factorial *= i;
  }

  printf("%d! = %d\n", num, factorial);

  return 0;
}