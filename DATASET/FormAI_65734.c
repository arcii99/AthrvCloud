//FormAI DATASET v1.0 Category: Error handling ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num = 69; // Nice.
  int denom = 0;
  int result;

  printf("Let's divide %d by %d\n", num, denom);

  // Let's try to divide and catch the error
  if (denom == 0) {
    printf("ERROR: Division by zero detected\n");
    printf("The FBI has been notified...\n");
    exit(1);
  }

  result = num / denom;

  // Display the result
  printf("The result is: %d\n", result);

  // But what if there's another error?
  if (result == 420) {
    printf("ERROR: The result is 420. Blaze it up!\n");
    printf("This is too high for this calculator. I'm calling the fire department...\n");
    exit(1);
  }

  printf("No errors detected. Have a nice day!\n");

  return 0;
}