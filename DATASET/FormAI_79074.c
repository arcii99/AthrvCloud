//FormAI DATASET v1.0 Category: Calculator ; Style: expert-level
//Include header files
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Declare functions
float add(float num1, float num2);
float subtract(float num1, float num2);
float multiply(float num1, float num2);
float divide(float num1, float num2);
float power(float num1, float num2);
float square_root(float num);
float absolute_value(float num);
void display_menu();

int main()
{
   float num1, num2, result=0;
   char choice;
   int flag=0; //Flag for division by zero
   //Display calculator menu
   display_menu();
   printf("Enter your choice: ");
   scanf(" %c", &choice);

   switch(choice)
   {
      case '1':  //Addition
         printf("Enter two numbers: ");
         scanf("%f %f", &num1, &num2);
         result = add(num1, num2);
         printf("Result: %.2f", result);
         break;

      case '2':  //Subtraction
         printf("Enter two numbers: ");
         scanf("%f %f", &num1, &num2);
         result = subtract(num1, num2);
         printf("Result: %.2f", result);
         break;

      case '3':  //Multiplication
         printf("Enter two numbers: ");
         scanf("%f %f", &num1, &num2);
         result = multiply(num1, num2);
         printf("Result: %.2f", result);
         break;

      case '4':  //Division
         printf("Enter two numbers: ");
         scanf("%f %f", &num1, &num2);
         if(num2 == 0)
         {
            printf("Error: Division by zero\n");
            flag = 1;
         }
         else
         {
            result = divide(num1, num2);
            printf("Result: %.2f\n", result);
         }
         break;

      case '5':  //X to the power of Y
         printf("Enter two numbers: ");
         scanf("%f %f", &num1, &num2);
         result = power(num1, num2);
         printf("Result: %.2f", result);
         break;

      case '6':  //Square root
         printf("Enter a number: ");
         scanf("%f", &num1);
         if(num1 < 0)
         {
            printf("Error: Negative number\n");
         }
         else
         {
            result = square_root(num1);
            printf("Result: %.2f", result);
         }
         break;

      case '7':  //Absolute value
         printf("Enter a number: ");
         scanf("%f", &num1);
         result = absolute_value(num1);
         printf("Result: %.2f", result);
         break;

      default:
         printf("Invalid choice. Please choose from the given options.\n");
   }

   return 0;
}

//Define functions
float add(float num1, float num2)
{
   return num1 + num2;
}

float subtract(float num1, float num2)
{
   return num1 - num2;
}

float multiply(float num1, float num2)
{
   return num1 * num2;
}

float divide(float num1, float num2)
{
   return num1 / num2;
}

float power(float num1, float num2)
{
   return pow(num1, num2);
}

float square_root(float num)
{
   return sqrt(num);
}

float absolute_value(float num)
{
   return fabs(num);
}

void display_menu()
{
   printf("Welcome to Expert Calculator: \n");
   printf("1. Addition \n");
   printf("2. Subtraction \n");
   printf("3. Multiplication \n");
   printf("4. Division \n");
   printf("5. X to the power of Y \n");
   printf("6. Square root \n");
   printf("7. Absolute value \n");
}