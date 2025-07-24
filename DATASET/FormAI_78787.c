//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: peaceful
#include<stdio.h>
#include<math.h>

int main()
{
  int choice;
  float num1,num2,result;
  float validEntry(char);
  float add(float,float);
  float subtract(float,float);
  float multiply(float,float);
  float divide(float,float);
  float power(float,float);
  float squareRoot(float);
  float logBase10(float);
  
  printf("\n---------------------------Welcome to Scientific Calculator---------------------------\n\n");

  do
  {
      printf("\n\nPlease select the operation you want to perform:\n");
      printf("\t1. Addition\n");
      printf("\t2. Subtraction\n");
      printf("\t3. Multiplication\n");
      printf("\t4. Division\n");
      printf("\t5. Power\n");
      printf("\t6. Square Root\n");
      printf("\t7. Logarithm(base 10)\n");
      printf("\t0. Exit\n\n");

      printf("Your choice : ");
      scanf("%d",&choice);

      switch(choice)
      {
          case 1:
              num1=validEntry('A');
              num2=validEntry('B');
              result = add(num1,num2);
              printf("\nResult : %.2f\n",result);
              break;

          case 2:
              num1=validEntry('A');
              num2=validEntry('B');
              result = subtract(num1,num2);
              printf("\nResult : %.2f\n",result);
              break;

          case 3:
              num1=validEntry('A');
              num2=validEntry('B');
              result = multiply(num1,num2);
              printf("\nResult : %.2f\n",result);
              break;

          case 4:
              num1=validEntry('A');
              num2=validEntry('B');
              if(num2==0)
              {
                  printf("\nError: Division by zero!\n");
              }
              else
              {
                  result = divide(num1,num2);
                  printf("\nResult : %.2f\n",result);
              }
              break;

          case 5:
              num1=validEntry('A');
              num2=validEntry('B');
              result = power(num1,num2);
              printf("\nResult : %.2f\n",result);
              break;

          case 6:
              num1=validEntry('A');
              result = squareRoot(num1);
              printf("\nResult : %.2f\n",result);
              break;

          case 7:
              num1=validEntry('A');
              result = logBase10(num1);
              printf("\nResult : %.2f\n",result);
              break;

          case 0:
              printf("\nThank you for using the calculator!\n");
              break;

          default:
              printf("\nInvalid Selection, Please Try Again!\n");
              break;
      }

  }while(choice!=0);

  return 0;
}

float validEntry(char ch)
{
  float num;
  printf("Enter the value of number %c : ",ch);
  scanf("%f",&num);
  return num;
}

float add(float a,float b)
{
  return a+b;
}

float subtract(float a,float b)
{
  return a-b;
}

float multiply(float a,float b)
{
  return a*b;
}

float divide(float a,float b)
{
  return a/b;
}

float power(float a,float b)
{
  return pow(a,b);
}

float squareRoot(float a)
{
  if(a<0)
  {
      printf("\nError: Square Root of a Negative Number is Undefined!\n");
      return -1;
  }
  else
  {
      return sqrt(a);
  }
}

float logBase10(float a)
{
  if(a<=0)
  {
      printf("\nError: Logarithm of a Non-Positive Number is Undefined!\n");
      return -1;
  }
  else
  {
      return log10(a);
  }
}