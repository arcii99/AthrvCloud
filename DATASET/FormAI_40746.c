//FormAI DATASET v1.0 Category: Error handling ; Style: funny
#include <stdio.h>

int main() {
  printf("Welcome to my Error Handling Program!\n");
  printf("Do not worry, I'll handle all errors with my magic wand!\n");

  int num1, num2, result;

  printf("Enter two numbers to multiply: ");
  if(scanf("%d %d", &num1, &num2) != 2) {
    printf("Oops! You did not enter two valid numbers.\n");
    printf("Please enter two numbers to multiply: ");
    scanf("%d %d", &num1, &num2);
  }

  if(num1 == 0 || num2 == 0) {
    printf("You cannot multiply by zero! Let me fix that for you.\n");
    if(num1 == 0) {
      printf("Enter a non-zero value for the first number: ");
      scanf("%d", &num1);
    } else {
      printf("Enter a non-zero value for the second number: ");
      scanf("%d", &num2);
    }
  }

  result = num1 * num2;

  printf("The result of %d and %d is: %d\n", num1, num2, result);

  printf("Thanks for trusting me with your error handling needs. Have a magical day!\n");

  return 0;
}