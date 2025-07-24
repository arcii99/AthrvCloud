//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Function to calculate the power of a number
float power(float base, float exponent)
{
    return pow(base, exponent);
}

//Function to calculate the factorial of a number
int factorial(int num)
{
    int fact=1;
    for(int i=1;i<=num;i++)
        fact*=i;
    return fact;
}

void main()
{
    int choice, num1, num2;
    float fnum1, fnum2;
    printf("Welcome to the Scientific Calculator!\n\n");

    while(1)
    {
        printf("Please select an operation:\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Power\n");
        printf("6. Factorial\n");
        printf("7. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: //Addition
                printf("Enter two numbers to add: ");
                scanf("%d%d", &num1, &num2);
                printf("Result: %d\n\n", num1+num2);
                break;

            case 2: //Subtraction
                printf("Enter two numbers to subtract: ");
                scanf("%d%d", &num1, &num2);
                printf("Result: %d\n\n", num1-num2);
                break;

            case 3: //Multiplication
                printf("Enter two numbers to multiply: ");
                scanf("%d%d", &num1, &num2);
                printf("Result: %d\n\n", num1*num2);
                break;

            case 4: //Division
                printf("Enter two numbers to divide: ");
                scanf("%f%f", &fnum1, &fnum2);
                printf("Result: %f\n\n", fnum1/fnum2);
                break;

            case 5: //Power
                printf("Enter base number: ");
                scanf("%f", &fnum1);
                printf("Enter exponent number: ");
                scanf("%f", &fnum2);
                printf("Result: %f\n\n", power(fnum1, fnum2));
                break;

            case 6: //Factorial
                printf("Enter a number to find factorial: ");
                scanf("%d", &num1);
                printf("Result: %d\n\n", factorial(num1));
                break;

            case 7: //Exit
                printf("Goodbye!");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    }
}