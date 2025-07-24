//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: surprised
#include <stdio.h>
#include <math.h>

int main()
{
    float num1, num2;
    int choice;

    printf("Welcome to CALCULATOR.PY!\n");
    printf("\n");
    printf("Please enter the first number: ");
    scanf("%f", &num1);

    printf("\n");

    printf("Please enter the second number: ");
    scanf("%f", &num2);

    printf("\n");

    printf("Please select an operation:\n");
    printf("\n");
    printf("1 - Addition\n");
    printf("2 - Subtraction\n");
    printf("3 - Multiplication\n");
    printf("4 - Division\n");
    printf("5 - Power\n");
    printf("6 - Modulus\n");
    printf("\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("\n");

    switch(choice)
    {
        case 1:
            printf("%.2f + %.2f = %.2f\n", num1, num2, num1+num2);
            break;
        case 2:
            printf("%.2f - %.2f = %.2f\n", num1, num2, num1-num2);
            break;
        case 3:
            printf("%.2f * %.2f = %.2f\n", num1, num2, num1*num2);
            break;
        case 4:
            if(num2 == 0)
            {
                printf("Error! Division by zero not allowed.\n");
            }
            else
            {
                printf("%.2f / %.2f = %.2f\n", num1, num2, num1/num2);
            }
            break;
        case 5:
            printf("%.2f ^ %.2f = %.2f\n", num1, num2, pow(num1,num2));
            break;
        case 6:
            printf("%.2f %% %.2f = %.2f\n", num1, num2, fmod(num1,num2));
            break;
        default:
            printf("Invalid choice! Please select a number between 1-6.\n");
    }

    printf("\n");
    printf("Thank you for using CALCULATOR.PY!\n");

    return 0;
}