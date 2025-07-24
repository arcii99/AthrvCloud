//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
void displayMenu();
void addition();
void subtraction();
void multiplication();
void division();
void power();
void squareRoot();
void logarithm();
void sine();
void cosine();
void tangent();
void clearScreen();

int main() {
   int choice, exit = 0;
   double num1, num2;
   
   while (!exit) {
      displayMenu();
      scanf("%d", &choice);
      
      switch (choice) {
         case 1:
            addition();
            break;
         case 2:
            subtraction();
            break;
         case 3:
            multiplication();
            break;
         case 4:
            division();
            break;
         case 5:
            power();
            break;
         case 6:
            squareRoot();
            break;
         case 7:
            logarithm();
            break;
         case 8:
            sine();
            break;
         case 9:
            cosine();
            break;
         case 10:
            tangent();
            break;
         case 11:
            clearScreen();
            break;
         case 12:
            printf("Thank you for using the calculator!\n\n");
            exit = 1;
            break;
         default:
            printf("Invalid input. Please try again.\n\n");
      }
   }
   
   return 0;
}

void displayMenu() {
   printf("Mind-Bending Scientific Calculator\n");
   printf("---------------------------------\n");
   printf("1. Addition\n");
   printf("2. Subtraction\n");
   printf("3. Multiplication\n");
   printf("4. Division\n");
   printf("5. Power\n");
   printf("6. Square root\n");
   printf("7. Logarithm\n");
   printf("8. Sine\n");
   printf("9. Cosine\n");
   printf("10. Tangent\n");
   printf("11. Clear screen\n");
   printf("12. Exit\n");
   printf("Enter choice: ");
}

void addition() {
   double num1, num2, result;
   
   printf("Enter first number: ");
   scanf("%lf", &num1);
   printf("Enter second number: ");
   scanf("%lf", &num2);
   
   result = num1 + num2;
   
   printf("Result: %lf\n\n", result);
}

void subtraction() {
   double num1, num2, result;
   
   printf("Enter first number: ");
   scanf("%lf", &num1);
   printf("Enter second number: ");
   scanf("%lf", &num2);
   
   result = num1 - num2;
   
   printf("Result: %lf\n\n", result);
}

void multiplication() {
   double num1, num2, result;
   
   printf("Enter first number: ");
   scanf("%lf", &num1);
   printf("Enter second number: ");
   scanf("%lf", &num2);
   
   result = num1 * num2;
   
   printf("Result: %lf\n\n", result);
}

void division() {
   double num1, num2, result;
   
   printf("Enter first number: ");
   scanf("%lf", &num1);
   printf("Enter second number: ");
   scanf("%lf", &num2);
   
   if (num2 == 0) {
      printf("Error: division by zero.\n\n");
   } else {
      result = num1 / num2;
      printf("Result: %lf\n\n", result);
   }
}

void power() {
   double num1, num2, result;
   
   printf("Enter first number: ");
   scanf("%lf", &num1);
   printf("Enter second number: ");
   scanf("%lf", &num2);
   
   result = pow(num1, num2);
   
   printf("Result: %lf\n\n", result);
}

void squareRoot() {
   double num, result;
   
   printf("Enter number: ");
   scanf("%lf", &num);
   
   if (num < 0) {
      printf("Error: cannot compute square root of a negative number.\n\n");
   } else {
      result = sqrt(num);
      printf("Result: %lf\n\n", result);
   }
}

void logarithm() {
   double num, result;
   
   printf("Enter number: ");
   scanf("%lf", &num);
   
   if (num <= 0) {
      printf("Error: cannot compute logarithm of a non-positive number.\n\n");
   } else {
      result = log(num);
      printf("Result: %lf\n\n", result);
   }
}

void sine() {
   double num, result;
   
   printf("Enter angle in degrees: ");
   scanf("%lf", &num);
   
   result = sin(num * M_PI / 180.0);
   
   printf("Result: %lf\n\n", result);
}

void cosine() {
   double num, result;
   
   printf("Enter angle in degrees: ");
   scanf("%lf", &num);
   
   result = cos(num * M_PI / 180.0);
   
   printf("Result: %lf\n\n", result);
}

void tangent() {
   double num, result;
   
   printf("Enter angle in degrees: ");
   scanf("%lf", &num);
   
   result = tan(num * M_PI / 180.0);
   
   printf("Result: %lf\n\n", result);
}

void clearScreen() {
   system("clear");
}