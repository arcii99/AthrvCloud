//FormAI DATASET v1.0 Category: Calculator ; Style: inquisitive
#include <stdio.h>

int main() {
  float num1, num2;
  char operator;

  printf("Enter first number:\n");
  scanf("%f", &num1);

  printf("Enter operator (+, -, *, /):\n");
  scanf("%c", &operator); //must have a leading space or it reads the newline character from the previous entry

  printf("Enter second number:\n");
  scanf("%f", &num2);

  switch(operator) {
    case '+':
      printf("The sum of %.2f and %.2f is %.2f.", num1, num2, num1 + num2);
      break;
    case '-':
      printf("The difference between %.2f and %.2f is %.2f.", num1, num2, num1 - num2);
      break;
    case '*':
      printf("%.2f multiplied by %.2f is equal to %.2f.", num1, num2, num1 * num2);
      break;
    case '/':
      if(num2 != 0) {
        printf("%.2f divided by %.2f is equal to %.2f.", num1, num2, num1 / num2);
      } else {
        printf("Error: division by zero is not allowed.");
      }
      break;
    default:
      printf("Invalid operator. Please enter one of the following: +, -, *, /");
  }

  return 0;
}