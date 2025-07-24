//FormAI DATASET v1.0 Category: Arithmetic ; Style: grateful
#include <stdio.h>

int main() {
    int num1, num2;
    printf("Please enter a number: ");
    scanf("%d", &num1);
    printf("Please enter another number: ");
    scanf("%d", &num2);

    int sum = num1 + num2;
    int difference = num1 - num2;
    int product = num1 * num2;
    int quotient = num1 / num2;
    int remainder = num1 % num2;

    printf("The sum of %d and %d is %d.\n", num1, num2, sum);
    printf("The difference between %d and %d is %d.\n", num1, num2, difference);
    printf("The product of %d and %d is %d.\n", num1, num2, product);
  if(quotient!=0)
    printf("The quotient of %d and %d is %d with a remainder of %d.\n", num1, num2, quotient, remainder);
  else
    printf("Cannot divide by zero.\n");

    return 0;
}