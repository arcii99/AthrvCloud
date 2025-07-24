//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int choice;
    float num1, num2, result;

    printf("\nWelcome to the Scientific Calculator\n");

    do{
        printf("\nEnter 1 for Addition\n");
        printf("Enter 2 for Subtraction\n");
        printf("Enter 3 for Multiplication\n");
        printf("Enter 4 for Division\n");
        printf("Enter 5 for Power\n");
        printf("Enter 6 for Square Root\n");
        printf("Enter 7 for Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter two numbers: ");
                scanf("%f %f", &num1, &num2);
                result = num1 + num2;
                printf("The sum of %.2f and %.2f is %.2f\n", num1, num2, result);
                break;

            case 2:
                printf("\nEnter two numbers: ");
                scanf("%f %f", &num1, &num2);
                result = num1 - num2;
                printf("The difference between %.2f and %.2f is %.2f\n", num1, num2, result);
                break;

            case 3:
                printf("\nEnter two numbers: ");
                scanf("%f %f", &num1, &num2);
                result = num1*num2;
                printf("The product of %.2f and %.2f is %.2f\n", num1, num2, result);
                break;

            case 4:
                printf("\nEnter two numbers: ");
                scanf("%f %f", &num1, &num2);
                result = num1/num2;
                printf("The quotient of %.2f and %.2f is %.2f\n", num1, num2, result);
                break;

            case 5:
                printf("\nEnter the base number: ");
                scanf("%f", &num1);
                printf("Enter the exponent number: ");
                scanf("%f", &num2);
                result = pow(num1, num2);
                printf("%.2f raised to the power %.2f is %.2f\n", num1, num2, result);
                break;

            case 6:
                printf("\nEnter a number: ");
                scanf("%f", &num1);
                result = sqrt(num1);
                printf("The square root of %.2f is %.2f\n", num1, result);
                break;

            case 7:
                printf("\nThank you for using the Scientific Calculator, Have a Good Day! Bye\n");
                exit(0);

            default:
                printf("\nInvalid Choice, Please select a valid option from the menu\n");
        }
    }while(1);

    return 0;
}