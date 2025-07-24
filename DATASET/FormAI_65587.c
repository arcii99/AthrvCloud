//FormAI DATASET v1.0 Category: Educational ; Style: enthusiastic
#include <stdio.h>

int main() {
  printf("Welcome to mySuperProgram!\n");
  printf("This program takes two integers and calculates their sum, difference, product and quotient.\n");
  printf("Enter the first integer:\n");
  int num1;
  scanf("%d", &num1);
  printf("Enter the second integer:\n");
  int num2;
  scanf("%d", &num2);
  int sum = num1 + num2;
  int dif = num1 - num2;
  int prod = num1 * num2;
  float quo = (float) num1 / num2;
  printf("The sum of %d and %d is %d\n", num1, num2, sum);
  printf("The difference of %d and %d is %d\n", num1, num2, dif);
  printf("The product of %d and %d is %d\n", num1, num2, prod);
  printf("The quotient of %d and %d is %.2f\n", num1, num2, quo);
  printf("Thank you for using mySuperProgram!\n");
  return 0;
}