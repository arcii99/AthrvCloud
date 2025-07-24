//FormAI DATASET v1.0 Category: Arithmetic ; Style: single-threaded
#include <stdio.h>

int main() {
  int num1, num2, choice, result;
  printf("Enter the first number: ");
  scanf("%d", &num1);
  printf("Enter the second number: ");
  scanf("%d", &num2);
  
  printf("\nSelect an arithmetic operation:\n");
  printf("1. Addition\n2. Substraction\n3. Multiplication\n4. Division\n");
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      result = num1 + num2;
      printf("The result of addition is %d", result);
      break;
    case 2:
      result = num1 - num2;
      printf("The result of substraction is %d", result);
      break;
    case 3:
      result = num1 * num2;
      printf("The result of multiplication is %d", result);
      break;
    case 4:
      if (num2 == 0) {
        printf("Cannot divide by zero.");
      } else {
        result = num1 / num2;
        printf("The result of division is %d", result);
      }
      break;
    default:
      printf("Invalid choice, please try again.");
  }
  return 0;
}