//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: active
#include<stdio.h>
#include<math.h>

int addition(int a, int b) { return a + b; }    //function to perform addition
int subtraction(int a, int b) { return a - b; } //function to perform subtraction
int multiplication(int a, int b) { return a * b; } //function to perform multiplication
int division(int a, int b) { return a / b; } //function to perform division
int modulus(int a, int b) { return a % b; } //function to perform modulus
double power(int a, int b) { return pow(a,b); } //function to perform power
double cosine(int a) { return cos(a); } //function to perform cosine
double sine(int a) { return sin(a); } //function to perform sine
double tangent(int a) { return tan(a); } //function to perform tangent
double logarithm(int a) { return log(a); } //function to perform logarithm

int main()
{
  int num1, num2, choice;
  char option;

  do {
      // Displaying the Menu
      printf("Welcome to Scientific Calculator \n");
      printf("1. Addition \n");
      printf("2. Subtraction \n");
      printf("3. Multiplication \n");
      printf("4. Division \n");
      printf("5. Modulus \n");
      printf("6. Power \n");
      printf("7. Cosine \n");
      printf("8. Sine \n");
      printf("9. Tangent \n");
      printf("10. Logarithm \n");

      printf("\nPlease choose the operation you want to perform: ");
      scanf("%d", &choice);

      if (choice > 0 && choice < 10) {
          printf("Enter the first number: ");
          scanf("%d",&num1);
          printf("Enter the second number: ");
          scanf("%d",&num2);
      }
      else {
          printf("Enter the number: ");
          scanf("%d",&num1);
      }

      switch (choice) {
          case 1:
              printf("The addition of %d and %d is: %d\n", num1, num2, addition(num1,num2));
              break;
          case 2:
              printf("The subtraction of %d and %d is: %d\n", num1, num2, subtraction(num1,num2));
              break;
          case 3:
              printf("The multiplication of %d and %d is: %d\n", num1, num2, multiplication(num1,num2));
              break;
          case 4:
              printf("The division of %d and %d is: %d\n", num1, num2, division(num1,num2));
              break;
          case 5:
              printf("The modulus of %d and %d is: %d\n", num1, num2, modulus(num1,num2));
              break;
          case 6:
              printf("The power of %d and %d is: %f\n", num1, num2, power(num1,num2));
              break;
          case 7:
              printf("The cosine of %d is: %f\n", num1, cosine(num1));
              break;
          case 8:
              printf("The sine of %d is: %f\n", num1, sine(num1));
              break;
          case 9:
              printf("The tangent of %d is: %f\n", num1, tangent(num1));
              break;
          case 10:
              printf("The logarithm of %d is: %f\n", num1, logarithm(num1));
              break;
          default:
              printf("Invalid Operation\n");
      }

      // Asking the user if he/she wants to continue using calculator
      printf("\nDo you want to continue using calculator (Y/N)? ");
      scanf(" %c", &option);

  } while (option == 'y' || option == 'Y');

  return 0;
}