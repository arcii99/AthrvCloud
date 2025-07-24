//FormAI DATASET v1.0 Category: Error handling ; Style: irregular
#include <stdio.h>

int main() {
  double x = 9, y = 0, result;

  printf("Enter a number to divide by: ");
  scanf("%lf", &y);

  if (y != 0) {
    result = x / y;
    printf("%lf divided by %lf is %lf\n", x, y, result);
  }
  else {
    printf("Error: Cannot divide by zero!\n");

    // error handling
    int choice;
    printf("Enter 1 to exit or 2 to try again: ");
    scanf("%d", &choice);

    if (choice == 1) {
      return 0;
    } else if (choice == 2) {
      // recursion
      main();
    } else {
      printf("Invalid choice, exiting program.\n");
      return 0;
    }
  }

  return 0;
}