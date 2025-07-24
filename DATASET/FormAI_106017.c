//FormAI DATASET v1.0 Category: Math exercise ; Style: inquisitive
#include <stdio.h>

int main() {
  int num1, den1, num2, den2;
  char op;
  
  printf("Welcome to the Fractions Solver!\n");

  printf("Please enter the first fraction (numerator and denominator separated by a space): ");
  scanf("%d %d", &num1, &den1);

  printf("Please enter the operator (+,-,*,/): ");
  scanf(" %c", &op);

  printf("Please enter the second fraction (numerator and denominator separated by a space): ");
  scanf("%d %d", &num2, &den2);

  int result_num, result_den;

  switch (op) {
    case '+':
      result_num = num1 * den2 + num2 * den1;
      result_den = den1 * den2;
      break;
    case '-':
      result_num = num1 * den2 - num2 * den1;
      result_den = den1 * den2;
      break;
    case '*':
      result_num = num1 * num2;
      result_den = den1 * den2;
      break;
    case '/':
      result_num = num1 * den2;
      result_den = den1 * num2;
      break;
    default:
      printf("Error: invalid operator\n");
      return 1;
  }

  printf("The result is: %d/%d\n", result_num, result_den);

  return 0;
}