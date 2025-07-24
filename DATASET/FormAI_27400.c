//FormAI DATASET v1.0 Category: Error handling ; Style: complete
#include <stdio.h> // Required for standard input/output functions
#include <stdlib.h> // Required for exit() function

int main() {
  int number;

  printf("Enter a number between 1 and 10: ");
  scanf("%d", &number);

  // Error handling code
  if (number < 1 || number > 10) {
    printf("Error: Number must be between 1 and 10!\n");
    exit(1); // Terminate the program with a non-zero exit code
  }

  // Rest of the program code
  printf("You entered: %d\n", number);
  return 0;

}