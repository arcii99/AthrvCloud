//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int choice;
    float num1, num2;
    do {
        printf("\nWelcome to The Awesome Calculator, please choose an operation (1-6, 7 to exit):\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Square Root (sqrt)\n");
        printf("6. Power (^)\n");
        printf("7. Exit\n");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                // ADDITION
                printf("Enter two numbers to add: ");
                scanf("%f %f",&num1, &num2);
                printf("%.2f + %.2f = %.2f\n", num1, num2, num1+num2);
                break;

            case 2:
                // SUBTRACTION
                printf("Enter two numbers to subtract (first - second): ");
                scanf("%f %f",&num1, &num2);
                printf("%.2f - %.2f = %.2f\n", num1, num2, num1-num2);
                break;

            case 3:
                // MULTIPLICATION
                printf("Enter two numbers to multiply: ");
                scanf("%f %f",&num1, &num2);
                printf("%.2f * %.2f = %.2f\n", num1, num2, num1*num2);
                break;

            case 4:
                // DIVISION
                printf("Enter two numbers to divide (first / second): ");
                scanf("%f %f",&num1, &num2);
                if(num2 == 0) {
                    printf("Cannot divide by zero! Please try again.\n");
                }
                else {
                    printf("%.2f / %.2f = %.2f\n", num1, num2, num1/num2);
                }
                break;

            case 5:
                // SQUARE ROOT
                printf("Enter a number to find the square root of: ");
                scanf("%f",&num1);
                if(num1 < 0) {
                    printf("Cannot find the square root of a negative number! Please try again.\n");
                }
                else {
                    printf("sqrt(%.2f) = %.2f\n", num1, sqrt(num1));
                }
                break;

            case 6:
                // POWER
                printf("Enter a number followed by the power you would like to raise it to: ");
                scanf("%f %f",&num1, &num2);
                printf("%.2f ^ %.2f = %.2f\n", num1, num2, pow(num1,num2));
                break;

            case 7:
                // EXIT
                printf("Thanks for using The Awesome Calculator!\n");
                break;

            default:
                printf("Invalid input! Please try again.\n");
        }
    } while(choice != 7);

    return 0;
}