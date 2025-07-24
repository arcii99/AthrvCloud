//FormAI DATASET v1.0 Category: Arithmetic ; Style: multivariable
#include <stdio.h>

int main()
{
  int num1, num2, num3, sum, product;

  printf("This program adds and multiplies three numbers.\n");

  printf("Enter the first number: ");
  scanf("%d", &num1);

  printf("Enter the second number: ");
  scanf("%d", &num2);

  printf("Enter the third number: ");
  scanf("%d", &num3);

  sum = num1 + num2 + num3;
  printf("The sum of the three numbers is: %d\n", sum);

  product = num1 * num2 * num3;
  printf("The product of the three numbers is: %d\n", product);

  return 0;
}