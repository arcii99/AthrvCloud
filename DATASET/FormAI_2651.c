//FormAI DATASET v1.0 Category: Arithmetic ; Style: safe
#include <stdio.h>
#include <math.h>

int main() {
  float num1, num2;
  char op;

  printf("Enter first number: ");
  scanf("%f", &num1);

  printf("Enter second number: ");
  scanf("%f", &num2);

  printf("Enter operator (+, -, *, /, %%): ");
  scanf(" %c", &op);

  switch(op) {
    case '+':
      printf("%.2f + %.2f = %.2f", num1, num2, num1 + num2);
      break;
    case '-':
      printf("%.2f - %.2f = %.2f", num1, num2, num1 - num2);
      break;
    case '*':
      printf("%.2f * %.2f = %.2f", num1, num2, num1 * num2);
      break;
    case '/':
      if(num2 == 0) {
        printf("Error: Cannot divide by zero");
      } else {
        printf("%.2f / %.2f = %.2f", num1, num2, num1 / num2);
      }
      break;
    case '%':
      printf("%d %% %d = %d", (int)num1, (int)num2, (int)num1 % (int)num2);
      break;
    default:
      printf("Error: Invalid operator");
  }
  
  return 0;
}