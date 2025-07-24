//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: decentralized
// C Scientific Calculator Implementation in a Decentralized Style

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function declarations
double addition();
double subtraction();
double multiplication();
double division();
double power();
double squareRoot();
double absoluteValue();
double naturalLogarithm();
double decimalLogarithm();
double sine();
double cosine();
double tangent();

int main()
{
    int choice;
    do
    {
        // Display the Calculator Menu
        printf("\n\n ***** Decentralized Scientific Calculator Menu *****\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Power\n");
        printf("6. Square Root\n");
        printf("7. Absolute Value\n");
        printf("8. Natural Logarithm\n");
        printf("9. Decimal Logarithm\n");
        printf("10. Sine\n");
        printf("11. Cosine\n");
        printf("12. Tangent\n");
        printf("13. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // Perform the desired operation based on user's choice
        switch(choice)
        {
            case 1:
                printf("\nResult: %lf", addition());
                break;
            case 2:
                printf("\nResult: %lf", subtraction());
                break;
            case 3:
                printf("\nResult: %lf", multiplication());
                break;
            case 4:
                printf("\nResult: %lf", division());
                break;
            case 5:
                printf("\nResult: %lf", power());
                break;
            case 6:
                printf("\nResult: %lf", squareRoot());
                break;
            case 7:
                printf("\nResult: %lf", absoluteValue());
                break;
            case 8:
                printf("\nResult: %lf", naturalLogarithm());
                break;
            case 9:
                printf("\nResult: %lf", decimalLogarithm());
                break;
            case 10:
                printf("\nResult: %lf", sine());
                break;
            case 11:
                printf("\nResult: %lf", cosine());
                break;
            case 12:
                printf("\nResult: %lf", tangent());
                break;
            case 13:
                printf("\nThank you for using the calculator!");
                exit(0);
                break;
            default:
                printf("\nInvalid choice! Please enter a valid choice.");
                break;
        }
    } while(1);

    return 0;
}

// Function definitions

double addition()
{
    double a, b;
    printf("\nEnter two numbers to add: ");
    scanf("%lf %lf", &a, &b);
    
    return a + b;
}

double subtraction()
{
    double a, b;
    printf("\nEnter two numbers to subtract: ");
    scanf("%lf %lf", &a, &b);
    
    return a - b;
}

double multiplication()
{
    double a, b;
    printf("\nEnter two numbers to multiply: ");
    scanf("%lf %lf", &a, &b);
    
    return a * b;
}

double division()
{
    double a, b;
    printf("\nEnter the dividend and divisor: ");
    scanf("%lf %lf", &a, &b);
    
    return a / b;
}

double power()
{
    double a, b;
    printf("\nEnter the base and exponent: ");
    scanf("%lf %lf", &a, &b);

    return pow(a, b);
}

double squareRoot()
{
    double a;
    printf("\nEnter the number to find square root: ");
    scanf("%lf", &a);

    return sqrt(a);
}

double absoluteValue()
{
    double a;
    printf("\nEnter the number to find absolute value: ");
    scanf("%lf", &a);

    return fabs(a);
}

double naturalLogarithm()
{
    double a;
    printf("\nEnter the number to find natural logarithm: ");
    scanf("%lf", &a);

    return log(a);
}

double decimalLogarithm()
{
    double a;
    printf("\nEnter the number to find decimal logarithm: ");
    scanf("%lf", &a);

    return log10(a);
}

double sine()
{
    double a;
    printf("\nEnter the angle in degrees: ");
    scanf("%lf", &a);

    return sin(a * 3.14159 / 180);
}

double cosine()
{
    double a;
    printf("\nEnter the angle in degrees: ");
    scanf("%lf", &a);

    return cos(a * 3.14159 / 180);
}

double tangent()
{
    double a;
    printf("\nEnter the angle in degrees: ");
    scanf("%lf", &a);

    return tan(a * 3.14159 / 180);
}