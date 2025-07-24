//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: future-proof
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

/* Function prototypes */
double add(double num1, double num2);
double subtract(double num1, double num2);
double multiply(double num1, double num2);
double divide(double num1, double num2);
double power(double num, int exponent);
double square_root(double num);
double sine(double num);
double cosine(double num);
double tangent(double num);

int main()
{
    char operation;
    double num1, num2, result;
    int exponent;
    
    printf("Welcome to the C Scientific Calculator!\n");
    printf("Please select an operation (+, -, *, /, ^, s, c, t): ");
    scanf("%c", &operation);
    
    switch(operation)
    {
        case '+':
            printf("Enter number 1: ");
            scanf("%lf", &num1);
            printf("Enter number 2: ");
            scanf("%lf", &num2);
            result = add(num1, num2);
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;
            
        case '-':
            printf("Enter number 1: ");
            scanf("%lf", &num1);
            printf("Enter number 2: ");
            scanf("%lf", &num2);
            result = subtract(num1, num2);
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;
            
        case '*':
            printf("Enter number 1: ");
            scanf("%lf", &num1);
            printf("Enter number 2: ");
            scanf("%lf", &num2);
            result = multiply(num1, num2);
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;
            
        case '/':
            printf("Enter number 1: ");
            scanf("%lf", &num1);
            printf("Enter number 2: ");
            scanf("%lf", &num2);
            result = divide(num1, num2);
            printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
            break;
            
        case '^':
            printf("Enter number: ");
            scanf("%lf", &num1);
            printf("Enter exponent: ");
            scanf("%d", &exponent);
            result = power(num1, exponent);
            printf("%.2lf ^ %d = %.2lf\n", num1, exponent, result);
            break;
            
        case 's':
            printf("Enter angle in degrees: ");
            scanf("%lf", &num1);
            result = sine(num1);
            printf("sin(%.2lf) = %.2lf\n", num1, result);
            break;
            
        case 'c':
            printf("Enter angle in degrees: ");
            scanf("%lf", &num1);
            result = cosine(num1);
            printf("cos(%.2lf) = %.2lf\n", num1, result);
            break;
            
        case 't':
            printf("Enter angle in degrees: ");
            scanf("%lf", &num1);
            result = tangent(num1);
            printf("tan(%.2lf) = %.2lf\n", num1, result);
            break;
            
        default:
            printf("Invalid operation! Please try again.\n");
            break;
    }
    
    return 0;
}

/* Function to add two numbers */
double add(double num1, double num2)
{
    return num1 + num2;
}

/* Function to subtract two numbers */
double subtract(double num1, double num2)
{
    return num1 - num2;
}

/* Function to multiply two numbers */
double multiply(double num1, double num2)
{
    return num1 * num2;
}

/* Function to divide two numbers */
double divide(double num1, double num2)
{
    if(num2 == 0)
    {
        printf("Error: Cannot divide by zero.");
        return -1;
    }
    
    return num1 / num2;
}

/* Function to calculate the power of a number */
double power(double num, int exponent)
{
    return pow(num, exponent);
}

/* Function to calculate the square root of a number */
double square_root(double num)
{
    if(num < 0)
    {
        printf("Error: Cannot calculate square root of a negative number.");
        return -1;
    }
    
    return sqrt(num);
}

/* Function to calculate the sine of an angle in degrees */
double sine(double num)
{
    double angle = num * PI / 180;
    return sin(angle);
}

/* Function to calculate the cosine of an angle in degrees */
double cosine(double num)
{
    double angle = num * PI / 180;
    return cos(angle);
}

/* Function to calculate the tangent of an angle in degrees */
double tangent(double num)
{
    double angle = num * PI / 180;
    return tan(angle);
}