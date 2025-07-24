//FormAI DATASET v1.0 Category: Syntax parsing ; Style: funny
#include<stdio.h>
int main()
{
  int a,b,c,d,add,sub,mul,div,mod;
  printf("Welcome to the crazy calculator!\n\n");

  printf("Enter the first number: ");
  scanf("%d",&a);

  printf("Enter the second number: ");
  scanf("%d",&b);

  printf("Enter the third number: ");
  scanf("%d",&c);

  printf("Enter the fourth number: ");
  scanf("%d",&d);

  add = a + b + c + d;
  sub = a - b - c - d;
  mul = a * b * c * d;
  div = a / b / c / d;
  mod = a % b % c % d;

  printf("\nWoohoo! Here's the result of your crazy calculations:\n\n");
  printf("The sum of all the numbers is: %d\n",add);
  printf("The subtraction of all the numbers is: %d\n",sub);
  printf("The multiplication of all the numbers is: %d\n",mul);
  printf("The division of all the numbers is: %d\n",div);
  printf("The mod of all the numbers is: %d\n",mod);

  printf("\nBut wait, there's more! Let's play a game of swapsies with the numbers!\n\n");

  int temp;

  temp=a;
  a=b;
  b=c;
  c=d;
  d=temp;

  printf("Alright, we have swapped the numbers! Let's print them out again:\n\n");
  printf("Number 1: %d\n",a);
  printf("Number 2: %d\n",b);
  printf("Number 3: %d\n",c);
  printf("Number 4: %d\n",d);

  printf("\nAre you feeling dizzy yet? Well, hold on tight because we're about to enter the if-else universe!\n\n");

  int num1,num2;

  printf("Enter the first integer number: ");
  scanf("%d",&num1);

  printf("Enter the second integer number: ");
  scanf("%d",&num2);

  if(num1 == num2)
  printf("\nThe two numbers are the same!");


  else if(num1 > num2)
  printf("\nThe first number is greater than the second number!");


  else
  printf("\nThe second number is greater than the first number!");

  printf("\nThat's all for today folks! Hope you enjoyed the crazy ride!\n");

  return 0;
}