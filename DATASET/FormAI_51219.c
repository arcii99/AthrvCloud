//FormAI DATASET v1.0 Category: Educational ; Style: beginner-friendly
#include<stdio.h>

int main()
{
  int num1, num2;
  printf("Enter the first number: ");
  scanf("%d", &num1);

  printf("Enter the second number: ");
  scanf("%d", &num2);

  printf("The sum of %d and %d is %d\n", num1, num2, num1+num2);
  printf("The difference of %d and %d is %d\n", num1, num2, num1-num2);
  printf("The product of %d and %d is %d\n", num1, num2, num1*num2);
  
  if(num2 == 0)
    printf("Division by zero is undefined!\n");
  else
    printf("The quotient of %d divided by %d is %.2f\n", num1, num2, (float)num1/num2);
  
  return 0;
}