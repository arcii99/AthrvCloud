//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: scientific
#include<stdio.h>
#include<math.h>

//function to add two numbers
double add(double num1, double num2){
   return num1 + num2;
}

//function to subtract two numbers
double subtract(double num1, double num2){
   return num1 - num2;
}

//function to multiply two numbers
double multiply(double num1, double num2){
   return num1 * num2;
}

//function to divide two numbers
double divide(double num1, double num2){
   return num1 / num2;
}

//function to calculate square root of a number
double squareRoot(double num){
   return sqrt(num);
}

//function to calculate power of a number
double power(double base, double power){
   return pow(base, power);
}

//function to calculate factorial of a number
double factorial(double num){
   double result = 1;
   int i;
   for(i=1; i<=num; i++){
      result = result * i;
   }
   return result;
}

int main(){
   int choice;
   double num1, num2, result;

   printf("***Scientific Calculator***\n");
   printf("Choose an operation to perform:\n");
   printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Square Root\n6. Power\n7. Factorial\n");
   scanf("%d", &choice);

   switch(choice){
      case 1:
         printf("Enter two numbers to add: ");
         scanf("%lf %lf", &num1, &num2);
         result = add(num1, num2);
         printf("The result is: %lf", result);
         break;
      case 2:
         printf("Enter two numbers to subtract: ");
         scanf("%lf %lf", &num1, &num2);
         result = subtract(num1, num2);
         printf("The result is: %lf", result);
         break;
      case 3:
         printf("Enter two numbers to multiply: ");
         scanf("%lf %lf", &num1, &num2);
         result = multiply(num1, num2);
         printf("The result is: %lf", result);
         break;
      case 4:
         printf("Enter two numbers to divide: ");
         scanf("%lf %lf", &num1, &num2);
         result = divide(num1, num2);
         printf("The result is: %lf", result);
         break;
      case 5:
         printf("Enter a number to calculate square root: ");
         scanf("%lf", &num1);
         result = squareRoot(num1);
         printf("The result is: %lf", result);
         break;
      case 6:
         printf("Enter base and power to calculate: ");
         scanf("%lf %lf", &num1, &num2);
         result = power(num1, num2);
         printf("The result is: %lf", result);
         break;
      case 7:
         printf("Enter a number to calculate factorial: ");
         scanf("%lf", &num1);
         result = factorial(num1);
         printf("The result is: %lf", result);
         break;
      default:
         printf("Invalid choice!");
   }

   return 0;
}