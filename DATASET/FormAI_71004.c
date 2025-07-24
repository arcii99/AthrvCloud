//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: unmistakable
#include <stdio.h>
#include <math.h>

// Constants
#define MAX_INPUT_CHARS 100

// Functions
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
double power(double, double);
double squareRoot(double);
double sine(double);
double cosine(double);
double tangent(double);
void clearInputBuffer();

int main()
{
    // Variables
    char input[MAX_INPUT_CHARS];
    int operation = 0;
    double num1 = 0, num2 = 0, result = 0;
    
    // Display menu
    printf("Scientific Calculator\n");
    printf("---------------------\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Sine\n");
    printf("8. Cosine\n");
    printf("9. Tangent\n");
    printf("---------------------\n");
    
    // Get user input
    printf("Enter operation number: ");
    fgets(input, MAX_INPUT_CHARS, stdin);
    operation = atoi(input);
    
    // If operation is valid, get numbers and calculate
    if (operation >= 1 && operation <= 9)
    {
        printf("Enter first number: ");
        fgets(input, MAX_INPUT_CHARS, stdin);
        num1 = atof(input);
        
        if (operation != 6 && operation != 7 && operation != 8 && operation != 9)
        {
            printf("Enter second number: ");
            fgets(input, MAX_INPUT_CHARS, stdin);
            num2 = atof(input);
        }
        
        switch(operation)
        {
            case 1:
                result = add(num1, num2);
                printf("Result: %g\n", result);
                break;
            case 2:
                result = subtract(num1, num2);
                printf("Result: %g\n", result);
                break;
            case 3:
                result = multiply(num1, num2);
                printf("Result: %g\n", result);
                break;
            case 4:
                if (num2 == 0)
                {
                    printf("Error: Cannot divide by zero\n");
                }
                else
                {
                    result = divide(num1, num2);
                    printf("Result: %g\n", result);
                }
                break;
            case 5:
                result = power(num1, num2);
                printf("Result: %g\n", result);
                break;
            case 6:
                if (num1 < 0)
                {
                    printf("Error: Cannot find square root of negative number\n");
                }
                else
                {
                    result = squareRoot(num1);
                    printf("Result: %g\n", result);
                }
                break;
            case 7:
                result = sine(num1);
                printf("Result: %g\n", result);
                break;
            case 8:
                result = cosine(num1);
                printf("Result: %g\n", result);
                break;
            case 9:
                if (cos(num1) == 0)
                {
                    printf("Error: Cannot find tangent of pi/2\n");
                }
                else
                {
                    result = tangent(num1);
                    printf("Result: %g\n", result);
                }
                break;
        }
    }
    else
    {
        printf("Error: Invalid operation number\n");
    }
    
    return 0;
}

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
    return num1 / num2;
}

double power(double num1, double num2)
{
    return pow(num1, num2);
}

double squareRoot(double num1)
{
    return sqrt(num1);
}

double sine(double num1)
{
    return sin(num1);
}

double cosine(double num1)
{
    return cos(num1);
}

double tangent(double num1)
{
    return tan(num1);
}

void clearInputBuffer()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}