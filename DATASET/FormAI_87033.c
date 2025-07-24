//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: excited
#include <stdio.h> // header file for standard input/output
#include <stdlib.h> // header file for standard library functions
#include <math.h> // header file for math operations

int main()
{
   int choice; // variable to hold user's choice of operation
   float num1, num2, result; // variables to hold input and result of operation

   printf("=====Welcome to Scientific Calculator=====\n\n");
   printf("Please choose the operation you wish to perform:\n");
   printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Power\n6. Square Root\n7. Logarithm\n8. Trigonometric Functions\n9. Exit\n\n");

   while(1) // keep running until user chooses to exit
   {
      printf("Enter your choice: ");
      scanf("%d",&choice);

      switch(choice)
      {
         case 1: // addition operation
            printf("\nEnter two numbers: ");
            scanf("%f %f",&num1,&num2);
            result=num1+num2;
            printf("Result: %.2f\n\n",result);
            break;

         case 2: // subtraction operation
            printf("\nEnter two numbers: ");
            scanf("%f %f",&num1,&num2);
            result=num1-num2;
            printf("Result: %.2f\n\n",result);
            break;

         case 3: // multiplication operation
            printf("\nEnter two numbers: ");
            scanf("%f %f",&num1,&num2);
            result=num1*num2;
            printf("Result: %.2f\n\n",result);
            break;

         case 4: // division operation
            printf("\nEnter two numbers: ");
            scanf("%f %f",&num1,&num2);
            if(num2==0) {
                printf("Cannot divide by zero!\n\n");
                break;
            }
            else {
                result=num1/num2;
                printf("Result: %.2f\n\n",result);
                break;
            }

         case 5: // power operation
            printf("\nEnter the base and exponent: ");
            scanf("%f %f",&num1,&num2);
            result=pow(num1,num2);
            printf("Result: %.2f\n\n",result);
            break;

         case 6: // square root operation
            printf("\nEnter a number: ");
            scanf("%f",&num1);
            if(num1<0) {
                printf("Cannot compute square root of negative number!\n\n");
                break;
            }
            else {
                result=sqrt(num1);
                printf("Result: %.2f\n\n",result);
                break;
            }

         case 7: // logarithm operation
            printf("\nEnter a number: ");
            scanf("%f",&num1);
            if(num1<=0) {
                printf("Cannot compute logarithm of non-positive number!\n\n");
                break;
            }
            else {
                result=log10(num1);
                printf("Result: %.2f\n\n",result);
                break;
            }

         case 8: // trigonometric functions
            printf("\nEnter an angle in radians: ");
            scanf("%f",&num1);
            result=sin(num1);
            printf("Sine: %.2f\n",result);
            result=cos(num1);
            printf("Cosine: %.2f\n",result);
            result=tan(num1);
            printf("Tangent: %.2f\n\n",result);
            break;

         case 9: // exit program
            printf("\nThank you for using Scientific Calculator!\n");
            exit(0);

         default:
            printf("\nInvalid choice!\n\n");
            break;
      }
   }
   return 0; // indicate successful completion of program
}