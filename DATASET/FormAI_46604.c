//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

// Function prototypes
float addition(float num1, float num2);
float subtraction(float num1, float num2);
float multiplication(float num1, float num2);
float division(float num1, float num2);
float power(float base, float exp);
float square_root(float num);
float sine(float angle);
float cosine(float angle);
float tangent(float angle);
float cosecant(float angle);
float secant(float angle);
float cotangent(float angle);

int main()
{
    float num1, num2, result;
    int choice;
    
    printf("Welcome to the Scientific Calculator\n\n");
    
    printf("Please select from the following options:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Sine\n");
    printf("8. Cosine\n");
    printf("9. Tangent\n");
    printf("10. Cosecant\n");
    printf("11. Secant\n");
    printf("12. Cotangent\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1:
            printf("Enter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
            result = addition(num1, num2);
            printf("Result: %f", result);
            break;
            
        case 2:
            printf("Enter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
            result = subtraction(num1, num2);
            printf("Result: %f", result);
            break;
            
        case 3:
            printf("Enter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
            result = multiplication(num1, num2);
            printf("Result: %f", result);
            break;
            
        case 4:
            printf("Enter first number: ");
            scanf("%f", &num1);
            printf("Enter second number: ");
            scanf("%f", &num2);
            result = division(num1, num2);
            printf("Result: %f", result);
            break;
            
        case 5:
            printf("Enter base: ");
            scanf("%f", &num1);
            printf("Enter exponent: ");
            scanf("%f", &num2);
            result = power(num1, num2);
            printf("Result: %f", result);
            break;
            
        case 6:
            printf("Enter number: ");
            scanf("%f", &num1);
            result = square_root(num1);
            printf("Result: %f", result);
            break;
            
        case 7:
            printf("Enter angle in degrees: ");
            scanf("%f", &num1);
            result = sine(num1);
            printf("Result: %f", result);
            break;
            
        case 8:
            printf("Enter angle in degrees: ");
            scanf("%f", &num1);
            result = cosine(num1);
            printf("Result: %f", result);
            break;
            
        case 9:
            printf("Enter angle in degrees: ");
            scanf("%f", &num1);
            result = tangent(num1);
            printf("Result: %f", result);
            break;
            
        case 10:
            printf("Enter angle in degrees: ");
            scanf("%f", &num1);
            result = cosecant(num1);
            printf("Result: %f", result);
            break;
            
        case 11:
            printf("Enter angle in degrees: ");
            scanf("%f", &num1);
            result = secant(num1);
            printf("Result: %f", result);
            break;
            
        case 12:
            printf("Enter angle in degrees: ");
            scanf("%f", &num1);
            result = cotangent(num1);
            printf("Result: %f", result);
            break;
            
        default:
            printf("Invalid choice");
    }
    
    return 0;
}

// Function to perform addition
float addition(float num1, float num2)
{
    return num1 + num2;
}

// Function to perform subtraction
float subtraction(float num1, float num2)
{
    return num1 - num2;
}

// Function to perform multiplication
float multiplication(float num1, float num2)
{
    return num1 * num2;
}

// Function to perform division
float division(float num1, float num2)
{
    return num1 / num2;
}

// Function to perform power
float power(float base, float exp)
{
    return pow(base, exp);
}

// Function to perform square root
float square_root(float num)
{
    return sqrt(num);
}

// Function to perform sine
float sine(float angle)
{
    float radian = angle * (PI / 180);
    return sin(radian);
}

// Function to perform cosine
float cosine(float angle)
{
    float radian = angle * (PI / 180);
    return cos(radian);
}

// Function to perform tangent
float tangent(float angle)
{
    float radian = angle * (PI / 180);
    return tan(radian);
}

// Function to perform cosecant
float cosecant(float angle)
{
    float radian = angle * (PI / 180);
    return 1/sin(radian);
}

// Function to perform secant
float secant(float angle)
{
    float radian = angle * (PI / 180);
    return 1/cos(radian);
}

// Function to perform cotangent
float cotangent(float angle)
{
    float radian = angle * (PI / 180);
    return 1/tan(radian);
}