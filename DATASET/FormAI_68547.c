//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: mind-bending
#include<stdio.h>
#include<math.h>

// function prototypes
void menu();
void addition();
void subtraction();
void multiplication();
void division();
void power();
void squareRoot();
void factorial();

int main()
{
    int choice;

    printf("\tWelcome to the Mind-Bending Scientific Calculator\n\n");

    while(1)
    {
        menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
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
                factorial();
                break;
            case 8:
                printf("\nThank you for using the Mind-Bending Scientific Calculator!\n");
                return 0;
            default:
                printf("\nInvalid Choice! Please choose again.\n");
        }
    }

    return 0;
}

// function to display menu options
void menu()
{
    printf("\nPlease select an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Factorial\n");
    printf("8. Exit\n");
}

// function to perform addition
void addition()
{
    int num1, num2, result;

    printf("\nEnter two numbers:\n");
    printf("Number 1: ");
    scanf("%d", &num1);
    printf("Number 2: ");
    scanf("%d", &num2);

    result = num1 + num2;
    printf("\nResult: %d\n", result);
}

// function to perform subtraction
void subtraction()
{
    int num1, num2, result;

    printf("\nEnter two numbers:\n");
    printf("Number 1: ");
    scanf("%d", &num1);
    printf("Number 2: ");
    scanf("%d", &num2);

    result = num1 - num2;
    printf("\nResult: %d\n", result);
}

// function to perform multiplication
void multiplication()
{
    int num1, num2, result;

    printf("\nEnter two numbers:\n");
    printf("Number 1: ");
    scanf("%d", &num1);
    printf("Number 2: ");
    scanf("%d", &num2);

    result = num1 * num2;
    printf("\nResult: %d\n", result);
}

// function to perform division
void division()
{
    int num1, num2;
    float result;

    printf("\nEnter two numbers:\n");
    printf("Number 1: ");
    scanf("%d", &num1);
    printf("Number 2: ");
    scanf("%d", &num2);

    if(num2 == 0)
    {
        printf("\nDivision by zero is not possible\n");
        return;
    }

    result = num1 / (float) num2;
    printf("\nResult: %.2f\n", result);
}

// function to perform power operation
void power()
{
    int num, exponent;
    double result;

    printf("\nEnter a number: ");
    scanf("%d", &num);
    printf("Enter the exponent: ");
    scanf("%d", &exponent);

    result = pow(num, exponent);
    printf("\nResult: %.2lf\n", result);
}

// function to perform square root operation
void squareRoot()
{
    int num;
    double result;

    printf("\nEnter a number: ");
    scanf("%d", &num);

    if(num < 0)
    {
        printf("\nSquare root of a negative number is not possible\n");
        return;
    }

    result = sqrt(num);
    printf("\nResult: %.2lf\n", result);
}

// function to perform factorial operation
void factorial()
{
    int num, i;
    unsigned long long factorial = 1;

    printf("\nEnter a positive integer: ");
    scanf("%d", &num);

    if(num < 0)
    {
        printf("\nFactorial of a negative number is not possible\n");
        return;
    }

    for(i=1; i<=num; i++)
    {
        factorial *= i;
    }

    printf("\nResult: %llu\n", factorial);
}