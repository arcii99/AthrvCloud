//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate power
double power(double base, double exponent)
{
    return pow(base, exponent);
}

// Function to calculate square root
double sqroot(double number)
{
    return sqrt(number);
}

// Function to calculate factorial
double factorial(double number)
{
    if(number == 0)
        return 1;
    else
        return number * factorial(number - 1);
}

// Function to calculate sin value
double sine(double value)
{
    double radian = value * (3.142 / 180);
    return sin(radian);
}

// Function to calculate cos value
double cosine(double value)
{
    double radian = value * (3.142 / 180);
    return cos(radian);
}

// Function to calculate tan value
double tangent(double value)
{
    double radian = value * (3.142 / 180);
    return tan(radian);
}

// Function to calculate log value
double logarithm(double value)
{
    return log10(value);
}

int main()
{
    int choice;
    double value, exponent, result;

    printf("Welcome to the Scientific Calculator!\n");
    printf("1. Power\n2. Square Root\n3. Factorial\n4. Sine\n5. Cosine\n6. Tangent\n7. Logarithm\n8. Exit");

    do
    {
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter the base: ");
                scanf("%lf", &value);

                printf("Enter the exponent: ");
                scanf("%lf", &exponent);

                result = power(value, exponent);
                printf("Result: %.2lf", result);
                break;

            case 2:
                printf("\nEnter the number: ");
                scanf("%lf", &value);

                result = sqroot(value);
                printf("Result: %.2lf", result);
                break;

            case 3:
                printf("\nEnter the number: ");
                scanf("%lf", &value);

                if(value < 0)
                {
                    printf("Invalid Input");
                    break;
                }

                result = factorial(value);
                printf("Result: %.2lf", result);
                break;

            case 4:
                printf("\nEnter the value in degrees: ");
                scanf("%lf", &value);

                result = sine(value);
                printf("Result: %.2lf", result);
                break;

            case 5:
                printf("\nEnter the value in degrees: ");
                scanf("%lf", &value);

                result = cosine(value);
                printf("Result: %.2lf", result);
                break;

            case 6:
                printf("\nEnter the value in degrees: ");
                scanf("%lf", &value);

                result = tangent(value);
                printf("Result: %.2lf", result);
                break;

            case 7:
                printf("\nEnter the value: ");
                scanf("%lf", &value);

                if(value <= 0)
                {
                    printf("Invalid Input");
                    break;
                }

                result = logarithm(value);
                printf("Result: %.2lf", result);
                break;

            case 8:
                printf("\nThank you for using the Scientific Calculator!");
                exit(0);

            default:
                printf("Invalid Choice! Please choose between 1-8");
                break;
        }
    } while(choice != 8);

    return 0;
}