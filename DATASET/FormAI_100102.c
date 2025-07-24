//FormAI DATASET v1.0 Category: Calculator ; Style: synchronous
#include <stdio.h>

int main() {
  char operator;
  float num1, num2;

  printf("Enter an operator (+, -, *, /): ");
  scanf("%c", &operator);

  printf("Enter two numbers: ");
  scanf("%f %f", &num1, &num2);

  switch(operator) {
    case '+':
      printf("%.1f + %.1f = %.1f", num1, num2, num1 + num2);
      break;

    case '-':
      printf("%.1f - %.1f = %.1f", num1, num2, num1 - num2);
      break;

    case '*':
      printf("%.1f * %.1f = %.1f", num1, num2, num1 * num2);
      break;

    case '/':
      if(num2 == 0) {
        printf("Error! Cannot divide by 0");
      } else {
        printf("%.1f / %.1f = %.1f", num1, num2, num1 / num2);
      }
      break;

    default:
      printf("Error! Invalid operator");
  }

  return 0;
}