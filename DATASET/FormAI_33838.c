//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

// Declaration of Functions
double add(double num1, double num2);
double subtract(double num1, double num2);
double multiply(double num1, double num2);
double divide(double num1, double num2);
double power(double num1, int num2);
double sine(double num);
double cosine(double num);
double tangent(double num);

int main()
{
    // Declaration of Variables
    int choice;
    double num1, num2, result;
    int num3;
    
    // Displaying the options to the user
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Power\n");
    printf("6. Sine\n");
    printf("7. Cosine\n");
    printf("8. Tangent\n");
    
    // Taking the choice from the user
    printf("Enter the operation you want to perform: ");
    scanf("%d", &choice);

    // Switch case to select the appropriate function based on the user choice
    switch(choice)
    {
        case 1:
            printf("Enter two numbers:\n");
            scanf("%lf %lf", &num1, &num2);
            result = add(num1, num2);
            printf("%.20lf", result);
            break;
        case 2:
            printf("Enter two numbers:\n");
            scanf("%lf %lf", &num1, &num2);
            result = subtract(num1, num2);
            printf("%.20lf", result);
            break;
        case 3:
            printf("Enter two numbers:\n");
            scanf("%lf %lf", &num1, &num2);
            result = multiply(num1, num2);
            printf("%.20lf", result);
            break;
        case 4:
            printf("Enter two numbers:\n");
            scanf("%lf %lf", &num1, &num2);
            result = divide(num1, num2);
            printf("%.20lf", result);
            break;
        case 5:
            printf("Enter a number and its power:\n");
            scanf("%lf %d", &num1, &num3);
            result = power(num1, num3);
            printf("%.20lf", result);
            break;
        case 6:
            printf("Enter a number:\n");
            scanf("%lf", &num1);
            result = sine(num1);
            printf("%.20lf", result);
            break;
        case 7:
            printf("Enter a number:\n");
            scanf("%lf", &num1);
            result = cosine(num1);
            printf("%.20lf", result);
            break;
        case 8:
            printf("Enter a number:\n");
            scanf("%lf", &num1);
            result = tangent(num1);
            printf("%.20lf", result);
            break;
        default:
            printf("Invalid Choice!");
    }

    return 0;
}

// Function Definitions
double add(double num1, double num2)
{
    return num1 + num2;
}

double subtract(double num1, double num2)
{
    return num1 - num2;
}

double multiply(double num1, double num2)
{
    return num1 * num2;
}

double divide(double num1, double num2)
{
    if(num2 == 0)
    {
        printf("Division by 0 Error!");
        return 0;
    }
    else
    {
        return num1 / num2;
    }
}

double power(double num1, int num2)
{
    return pow(num1, num2);
}

double sine(double num)
{
    return sin(num);
}

double cosine(double num)
{
    return cos(num);
}

double tangent(double num)
{
    return tan(num);
}