//FormAI DATASET v1.0 Category: Arithmetic ; Style: bold
#include<stdio.h>

int main()
{
  int num1, num2;
  float num3;
  
  printf("\n Enter the first integer number:");
  scanf("%d",&num1);
  
  printf("\n Enter the second integer number:");
  scanf("%d",&num2);
  
  printf("\n Enter the floating point number:");
  scanf("%f",&num3);
  
  printf("\n Addition of %d and %d= %d",num1,num2,num1+num2);
  printf("\n Subtraction of %d and %d= %d",num1,num2,num1-num2);
  printf("\n Multiplication of %d and %d= %d",num1,num2,num1*num2);
  printf("\n Division of %d and %d= %f",num1,num2,(float)num1/num2);
  printf("\n Modulus of %d and %d= %d",num1,num2,num1%num2);
  
  if(num3>0)
   printf("\n Absolute value of %.2f is %.2f ",num3,num3);
  else if(num3<0)
   printf("\n Absolute value of %.2f is %.2f ",num3,-num3);
  else
   printf("\n Absolute value of %.2f is %.2f ",num3,num3);
  
  if(num1%2==0)
   printf("\n %d is an even number",num1);
  else
   printf("\n %d is an odd number",num1);
   
  if(num2>0)
   printf("\n %d is a positive number",num2);
  else if(num2<0)
   printf("\n %d is a negative number",num2);
  else
   printf("\n %d is neither positive nor negative",num2);
   
  return 0;
}