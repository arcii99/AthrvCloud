//FormAI DATASET v1.0 Category: Syntax parsing ; Style: funny
#include <stdio.h>

int main() {
  int num1, num2, result;
  char operator;

  printf("Welcome to the Funny Calculator!\n");
  printf("Please enter your first number:\n");
  scanf("%d", &num1);

  printf("Now, please enter your second number:\n");
  scanf("%d", &num2);

  printf("What operation would you like to perform? Please enter one of the following symbols:\n");
  printf("+ for addition\n- for subtraction\n* for multiplication\n/ for division\n");
  scanf(" %c", &operator); // leave a space before %c to consume newline from previous scanf

  switch(operator) {
    case '+':
      result = num1 + num2;
      printf("The result of %d + %d = %d\n", num1, num2, result);
      break;

    case '-':
      result = num1 - num2;
      printf("The result of %d - %d = %d\n", num1, num2, result);
      break;

    case '*':
      result = num1 * num2;
      printf("The result of %d * %d = %d\n", num1, num2, result);
      break;

    case '/':
      if(num2 == 0) {
        printf("Sorry, I cannot divide by zero. Please try again!\n");
      } else {
        result = num1 / num2;
        printf("The result of %d / %d = %d\n", num1, num2, result);
      }
      break;

    default:
      printf("Sorry, I do not recognize that operator. Please try again!\n");
      break;
  }

  return 0;
}