//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: protected
#include <stdio.h>
#include <math.h>

#define MAX_EXPRESSION_LENGTH 100 // Maximum length of user input expression

// Function prototypes
double addition(double num1, double num2);
double subtraction(double num1, double num2);
double multiplication(double num1, double num2);
double division(double num1, double num2);
double power(double num1, double num2);
double square_root(double num);
double log_base_10(double num);
double factorial(double num);

int main()
{
    char expression[MAX_EXPRESSION_LENGTH]; // User input expression
    int operator; // Operator entered by user
    double num1, num2, result; // Numbers and result of operation
    
    printf("Welcome to the Scientific Calculator program!\n\n");
    
    // Loop until user quits program
    while (1)
    {
        // Get user input
        printf("Enter expression: ");
        fgets(expression, MAX_EXPRESSION_LENGTH, stdin);
        
        // Check if user wants to quit
        if (expression[0] == 'q' || expression[0] == 'Q')
        {
            printf("Exiting program...\n");
            break;
        }
        
        // Parse user input and perform operation
        if (sscanf(expression, "%lf %d %lf", &num1, &operator, &num2) == 3)
        {
            switch (operator)
            {
                case 1: // Addition
                    result = addition(num1, num2);
                    break;
                case 2: // Subtraction
                    result = subtraction(num1, num2);
                    break;
                case 3: // Multiplication
                    result = multiplication(num1, num2);
                    break;
                case 4: // Division
                    result = division(num1, num2);
                    break;
                case 5: // Power
                    result = power(num1, num2);
                    break;
                default: // Invalid operator
                    printf("Invalid operator %d\n", operator);
                    continue; // Restart loop
            }
            printf("Result: %lf\n", result);
        }
        else // Invalid expression
        {
            printf("Invalid expression \"%s\"\n", expression);
        }
        
    }
    
    return 0;
}

double addition(double num1, double num2)
{
    return num1 + num2;
}

double subtraction(double num1, double num2)
{
    return num1 - num2;
}

double multiplication(double num1, double num2)
{
    return num1 * num2;
}

double division(double num1, double num2)
{
    return num1 / num2;
}

double power(double num1, double num2)
{
    return pow(num1, num2);
}

double square_root(double num)
{
    return sqrt(num);
}

double log_base_10(double num)
{
    return log10(num);
}

double factorial(double num)
{
    double result = 1;
    for (int i = 1; i <= num; i++)
    {
        result *= i;
    }
    return result;
}