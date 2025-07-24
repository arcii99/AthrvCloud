//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: protected
/*
*  Author: Your Name
*  Program: Scientific Calculator
*/

#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
 
int main() 
{
    int choice;
    float num1, num2;
 
    while(1)  // loop until user wants to exit
    {
        printf("\nWhich operation would you like to perform?");
        printf("\n1. Addition \n2. Subtraction \n3. Multiplication \n4. Division \n5. Power \n6. Square Root \n7. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
 
        switch(choice) 
        {
            case 1:
                printf("\nEnter two numbers to add: ");
                scanf("%f %f",&num1, &num2);
                printf("%.2f + %.2f = %.2f\n", num1, num2, num1+num2);
                break;
 
            case 2:
                printf("\nEnter two numbers to subtract: ");
                scanf("%f %f",&num1, &num2);
                printf("%.2f - %.2f = %.2f\n", num1, num2, num1-num2);
                break;
 
            case 3:
                printf("\nEnter two numbers to multiply: ");
                scanf("%f %f",&num1, &num2);
                printf("%.2f * %.2f = %.2f\n", num1, num2, num1*num2);
                break;
 
            case 4:
                printf("\nEnter two numbers to divide: ");
                scanf("%f %f",&num1, &num2);
                if(num2 == 0) {
                    printf("Error: Division by zero!");
                    break;
                }
                printf("%.2f / %.2f = %.2f\n", num1, num2, num1/num2);
                break;
 
            case 5:
                printf("\nEnter a number and its power: ");
                scanf("%f %f",&num1, &num2);
                printf("%.2f raised to %.2f = %.2f\n", num1, num2, pow(num1,num2));
                break;
 
            case 6:
                printf("\nEnter a number to find square root: ");
                scanf("%f",&num1);
                if(num1 < 0) {
                    printf("Error: Cannot find square root of negative number!");
                    break;
                }
                printf("Square root of %.2f = %.2f\n", num1, sqrt(num1));
                break;
 
            case 7:
                printf("Exiting the program...");
                exit(0);  // exit the program
        
            default:
                printf("Invalid choice; Please enter a valid choice number!");
        }
    }
    return 0;
}