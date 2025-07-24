//FormAI DATASET v1.0 Category: Arithmetic ; Style: detailed
#include <stdio.h>

int main() {
  int num1, num2, result, option;

  printf("Welcome to the Arithmetic Program!\n");
  printf("Please enter the first number: ");
  scanf("%d", &num1);
  printf("Please enter the second number: ");
  scanf("%d", &num2);

  printf("Please select an operation:\n");
  printf("1. Addition\n");
  printf("2. Subtraction\n");
  printf("3. Multiplication\n");
  printf("4. Division\n");
  scanf("%d", &option);

  switch (option) {
    case 1:
      result = num1 + num2;
      printf("%d + %d = %d\n", num1, num2, result);
      break;
    case 2:
      result = num1 - num2;
      printf("%d - %d = %d\n", num1, num2, result);
      break;
    case 3:
      result = num1 * num2;
      printf("%d * %d = %d\n", num1, num2, result);
      break;
    case 4:
      if (num2 == 0) {
        printf("Cannot divide by zero!\n");
      } else {
        result = num1 / num2;
        printf("%d / %d = %d\n", num1, num2, result);
      }
      break;
    default:
      printf("Invalid option selected!\n");
  }

  return 0;
}