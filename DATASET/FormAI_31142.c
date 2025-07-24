//FormAI DATASET v1.0 Category: Arithmetic ; Style: genious
#include <stdio.h>

int main() {
  // Welcome message
  printf("Welcome to the Genius Arithmetic program!\n");
  printf("This program will show you some incredible arithmetic examples.\n");

  // Declare variables
  int num1, num2, sum, diff, prod;
  float quot;

  // Take input from user
  printf("\nEnter first number: ");
  scanf("%d", &num1);
  printf("Enter second number: ");
  scanf("%d", &num2);

  // Perform arithmetic operations
  sum = num1 + num2;
  diff = num1 - num2;
  prod = num1 * num2;
  quot = (float)num1 / num2;

  // Display results
  printf("\nThe sum of %d and %d is %d.\n", num1, num2, sum);
  printf("The difference between %d and %d is %d.\n", num1, num2, diff);
  printf("The product of %d and %d is %d.\n", num1, num2, prod);
  printf("The quotient of %d and %d is %.2f.\n", num1, num2, quot);

  // Genius bonus
  printf("\nBut wait, let's take this a step further...\n");
  int i;
  printf("%d times %d is ", num1, num2);
  for (i = 0; i < num1; i++) {
    printf("%d", num2);
    if (i != num1-1) {
      printf(" + ");
    }
    prod += num2;
  }
  printf(" which is %d!\n", prod);

  // Conclusion
  printf("\nWow, that was some genius arithmetic!\n");
  printf("Thanks for using this program. Have a great day!\n");

  return 0;
}