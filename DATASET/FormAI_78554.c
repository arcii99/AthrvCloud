//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: accurate
#include <stdio.h>
#include <math.h>

//function declarations
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
double power(double, int);
double factorial(double);
double sine(double);
double cosine(double);
double tangent(double);

int main() {
   int choice;
   double num1, num2;

   printf("Welcome to the scientific calculator!\n\n");
   printf("Please select an option:\n");
   printf("1. add\n");
   printf("2. subtract\n");
   printf("3. multiply\n");
   printf("4. divide\n");
   printf("5. power\n");
   printf("6. factorial\n");
   printf("7. sine\n");
   printf("8. cosine\n");
   printf("9. tangent\n");
   printf("Enter your choice: ");
   scanf("%d", &choice);

   switch (choice) {
      case 1:
         printf("Enter two numbers to add: ");
         scanf("%lf %lf", &num1, &num2);
         printf("%0.2lf + %0.2lf = %0.2lf\n", num1, num2, add(num1, num2));
         break;

      case 2:
         printf("Enter two numbers to subtract: ");
         scanf("%lf %lf", &num1, &num2);
         printf("%0.2lf - %0.2lf = %0.2lf\n", num1, num2, subtract(num1, num2));
         break;

      case 3:
         printf("Enter two numbers to multiply: ");
         scanf("%lf %lf", &num1, &num2);
         printf("%0.2lf * %0.2lf = %0.2lf\n", num1, num2, multiply(num1, num2));
         break;

      case 4:
         printf("Enter two numbers to divide: ");
         scanf("%lf %lf", &num1, &num2);
         printf("%0.2lf / %0.2lf = %0.2lf\n", num1, num2, divide(num1, num2));
         break;

      case 5:
         printf("Enter a number and its power: ");
         scanf("%lf %lf", &num1, &num2);
         printf("%0.2lf ^ %0.2lf = %0.2lf\n", num1, num2, power(num1, num2));
         break;

      case 6:
         printf("Enter a number to find its factorial: ");
         scanf("%lf", &num1);
         printf("%0.2lf! = %0.2lf\n", num1, factorial(num1));
         break;

      case 7:
         printf("Enter an angle in radians to find its sine: ");
         scanf("%lf", &num1);
         printf("sin(%0.2lf) = %0.2lf\n", num1, sine(num1));
         break;

      case 8:
         printf("Enter an angle in radians to find its cosine: ");
         scanf("%lf", &num1);
         printf("cos(%0.2lf) = %0.2lf\n", num1, cosine(num1));
         break;

      case 9:
         printf("Enter an angle in radians to find its tangent: ");
         scanf("%lf", &num1);
         printf("tan(%0.2lf) = %0.2lf\n", num1, tangent(num1));
         break;

      default:
         printf("Invalid choice.");
   }

   return 0;
}

//function to add two numbers
double add(double num1, double num2) {
   return num1 + num2;
}

//function to subtract two numbers
double subtract(double num1, double num2) {
   return num1 - num2;
}

//function to multiply two numbers
double multiply(double num1, double num2) {
   return num1 * num2;
}

//function to divide two numbers
double divide(double num1, double num2) {
   return num1 / num2;
}

//function to find power of a number
double power(double num1, int num2) {
   return pow(num1, num2);
}

//function to find factorial of a number
double factorial(double num1) {
   if(num1 == 0) {
      return 1;
   } else {
      return(num1 * factorial(num1-1));
   }
}

//function to find sine of an angle
double sine(double num1) {
   return sin(num1);
}

//function to find cosine of an angle
double cosine(double num1) {
   return cos(num1);
}

//function to find tangent of an angle
double tangent(double num1) {
   return tan(num1);
}