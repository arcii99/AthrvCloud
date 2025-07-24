//FormAI DATASET v1.0 Category: Arithmetic ; Style: scalable
#include <stdio.h>

int main() {
  int num1, num2, choice, result;
  
  printf("Enter the first number: ");
  scanf("%d", &num1);
  
  printf("Enter the second number: ");
  scanf("%d", &num2);
  
  printf("Choose an operation:\n");
  printf("1. Addition (+)\n");
  printf("2. Subtraction (-)\n");
  printf("3. Multiplication (*)\n");
  printf("4. Division (/)\n");
  
  scanf("%d", &choice);
  
  switch (choice) {
    case 1:
      result = num1 + num2;
      printf("The sum of %d and %d is %d.", num1, num2, result);
      break;
    case 2:
      result = num1 - num2;
      printf("The difference between %d and %d is %d.", num1, num2, result);
      break;
    case 3:
      result = num1 * num2;
      printf("The product of %d and %d is %d.", num1, num2, result);
      break;
    case 4:
      if (num2 == 0) {
        printf("Error: Cannot divide by zero.");
      } else {
        result = num1 / num2;
        printf("%d divided by %d is %d with a remainder of %d.", num1, num2, result, num1 % num2);
      }
      break;
    default:
      printf("Invalid choice.");
  }
  
  return 0;
}