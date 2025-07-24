//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float addition(float a, float b);
float subtraction(float a, float b);
float multiplication(float a, float b);
float division(float a, float b);
float power(float base, float exponent);
float sine(float x);
float cosine(float x);
float tangent(float x);
float inverse_sine(float x);
float inverse_cosine(float x);
float inverse_tangent(float x);

int main()
{
    int choice = 0;
    float result = 0, a, b;
    
    printf("Welcome to the Scientific Calculator\n");

    do {
        printf("\nPlease select an operation to perform:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Power\n");
        printf("6. Sine\n");
        printf("7. Cosine\n");
        printf("8. Tangent\n");
        printf("9. Inverse Sine\n");
        printf("10. Inverse Cosine\n");
        printf("11. Inverse Tangent\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter first number: ");
                scanf("%f", &a);
                printf("Enter second number: ");
                scanf("%f", &b);
                result = addition(a, b);
                printf("%.2f + %.2f = %.2f\n", a, b, result);
                break;
            case 2:
                printf("Enter first number: ");
                scanf("%f", &a);
                printf("Enter second number: ");
                scanf("%f", &b);
                result = subtraction(a, b);
                printf("%.2f - %.2f = %.2f\n", a, b, result);
                break;
            case 3:
                printf("Enter first number: ");
                scanf("%f", &a);
                printf("Enter second number: ");
                scanf("%f", &b);
                result = multiplication(a, b);
                printf("%.2f * %.2f = %.2f\n", a, b, result);
                break;
            case 4:
                printf("Enter first number: ");
                scanf("%f", &a);
                printf("Enter second number: ");
                scanf("%f", &b);
                result = division(a, b);
                printf("%.2f / %.2f = %.2f\n", a, b, result);
                break;
            case 5:
                printf("Enter base: ");
                scanf("%f", &a);
                printf("Enter exponent: ");
                scanf("%f", &b);
                result = power(a, b);
                printf("%.2f ^ %.2f = %.2f\n", a, b, result);
                break;
            case 6:
                printf("Enter angle in degrees: ");
                scanf("%f", &a);
                result = sine(a);
                printf("sin(%.2f) = %.2f\n", a, result);
                break;
            case 7:
                printf("Enter angle in degrees: ");
                scanf("%f", &a);
                result = cosine(a);
                printf("cos(%.2f) = %.2f\n", a, result);
                break;
            case 8:
                printf("Enter angle in degrees: ");
                scanf("%f", &a);
                result = tangent(a);
                printf("tan(%.2f) = %.2f\n", a, result);
                break;
            case 9:
                printf("Enter value between -1 and 1: ");
                scanf("%f", &a);
                result = inverse_sine(a);
                printf("sin^-1(%.2f) = %.2f degrees\n", a, result);
                break;
            case 10:
                printf("Enter value between -1 and 1: ");
                scanf("%f", &a);
                result = inverse_cosine(a);
                printf("cos^-1(%.2f) = %.2f degrees\n", a, result);
                break;  
            case 11:
                printf("Enter value: ");
                scanf("%f", &a);
                result = inverse_tangent(a);
                printf("tan^-1(%.2f) = %.2f degrees\n", a, result);
                break;  
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
        
    } while (choice != 0);
    
    printf("Thank you for using our calculator.\n");
    
    return 0;
}

float addition(float a, float b)
{
    return a + b;
}

float subtraction(float a, float b)
{
    return a - b;
}

float multiplication(float a, float b)
{
    return a * b;
}

float division(float a, float b)
{
    return a / b;
}

float power(float base, float exponent)
{
    return pow(base, exponent);
}

float sine(float x)
{
    return sin(x * M_PI / 180);
}

float cosine(float x)
{
    return cos(x * M_PI / 180);
}

float tangent(float x)
{
    return tan(x * M_PI / 180);
}

float inverse_sine(float x)
{
    return asin(x) * 180 / M_PI;
}

float inverse_cosine(float x)
{
    return acos(x) * 180 / M_PI;
}

float inverse_tangent(float x)
{
    return atan(x) * 180 / M_PI;
}