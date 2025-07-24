//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: calm
#include<stdio.h>
#include<math.h>

int main()
{
   int choice;
   float a, b, result;
   
   printf("Welcome to the Simple Scientific Calculator program\n");
   
   do
   {
      printf("\nPlease select an operation: \n");
      printf("1. Addition (+)\n");
      printf("2. Subtraction (-)\n");
      printf("3. Multiplication (*)\n");
      printf("4. Division (/)\n");
      printf("5. Square Root (√)\n");
      printf("6. Exponential (x^y)\n");
      printf("7. Logarithm (log)\n");
      printf("8. Exit\n");
      
      printf("Enter your choice: ");
      scanf("%d", &choice);
      
      switch (choice)
      {
         case 1: //Addition
            printf("\nEnter the two numbers to be added: ");
            scanf("%f %f", &a, &b);
            result = a + b;
            printf("\nThe sum of %.2f and %.2f is %.2f\n", a, b, result);
            break;
            
        case 2: //Subtraction
            printf("\nEnter the two numbers to be subtracted: ");
            scanf("%f %f", &a, &b);
            result = a - b;
            printf("\nThe difference between %.2f and %.2f is %.2f\n", a, b, result);
            break;
         
        case 3: //Multiplication
            printf("\nEnter the two numbers to be multiplied: ");
            scanf("%f %f", &a, &b);
            result = a * b;
            printf("\nThe product of %.2f and %.2f is %.2f\n", a, b, result);
            break;
         
        case 4: //Division
            printf("\nEnter the two numbers to be divided: ");
            scanf("%f %f", &a, &b);
            result = a / b;
            printf("\nThe quotient of %.2f and %.2f is %.2f\n", a, b, result);
            break;
         
        case 5: //Square root
            printf("\nEnter the number to find its square root: ");
            scanf("%f", &a);
            result = sqrt(a);
            printf("\nThe square root of %.2f is %.2f\n", a, result);
            break;
         
        case 6: //Exponential
            printf("\nEnter the base and exponent: ");
            scanf("%f %f", &a, &b);
            result = pow(a,b);
            printf("\n%.2f to the power of %.2f is %.2f\n", a, b, result);
            break;
         
        case 7: //Logarithm
            printf("\nEnter the number to find its logarithm (base 10): ");
            scanf("%f", &a);
            result = log10(a);
            printf("\nThe logarithm of %.2f is %.2f\n", a, result);
            break;
            
        case 8: //Exit
            printf("\nThank you for using the Simple Scientific Calculator program!\n");
            break;
         
        default:
            printf("\nInvalid choice. Please try again.\n");
      }
      
   }while(choice != 8);
   
   return 0;
}