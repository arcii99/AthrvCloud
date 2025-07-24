//FormAI DATASET v1.0 Category: Educational ; Style: high level of detail
#include <stdio.h>

/* This program calculates the average of 5 numbers entered by the user */

int main()
{
  float num1, num2, num3, num4, num5, average;

  printf("Enter the first number: ");
  scanf("%f", &num1);

  printf("Enter the second number: ");
  scanf("%f", &num2);

  printf("Enter the third number: ");
  scanf("%f", &num3);

  printf("Enter the fourth number: ");
  scanf("%f", &num4);

  printf("Enter the fifth number: ");
  scanf("%f", &num5);

  average = (num1 + num2 + num3 + num4 + num5) / 5;

  printf("The average of %.2f, %.2f, %.2f, %.2f, and %.2f is %.2f\n", num1, num2, num3, num4, num5, average);

  return 0;
}