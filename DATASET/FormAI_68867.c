//FormAI DATASET v1.0 Category: Arithmetic ; Style: brave
#include<stdio.h>

int main(){
  int num1, num2, num3, result; //declaring variables

  printf("Greetings, brave programmer! Let's perform some arithmetic operations\n");
  printf("Please enter the first number: ");
  scanf("%d", &num1); //taking user input for num1
  printf("Please enter the second number: ");
  scanf("%d", &num2); //taking user input for num2
  printf("Please enter the third number: ");
  scanf("%d", &num3); //taking user input for num3

  //addition operation
  result = num1 + num2 + num3;
  printf("\nThe sum of %d, %d, and %d is %d\n", num1, num2, num3, result);

  //subtraction operation
  result = num1 - num2 - num3;
  printf("\nThe subtraction of %d from %d and then %d is %d\n", num2, num3, num1, result);

  //multiplication operation
  result = num1 * num2 * num3;
  printf("\nThe product of %d, %d, and %d is %d\n", num1, num2, num3, result);

  //division operation
  result = num1 / num2 / num3;
  printf("\nThe division of %d by %d and then by %d is %d\n", num1, num2, num3, result);

  //modulus operation
  result = num1 % num2 % num3;
  printf("\nThe remainder after dividing %d by %d and then by %d is %d\n", num1, num2, num3, result);

  printf("Congratulations, brave programmer! You have successfully completed these arithmetic operations. May the programming gods bless you!\n");
  return 0;
}