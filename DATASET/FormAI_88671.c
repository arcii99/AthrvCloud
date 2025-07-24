//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Function Declarations */
float add(float, float);
float subtract(float, float);
float multiply(float, float);
float divide(float, float);
float power(float, int);
float square_root(float);
float sine(float);
float cosine(float);
float tangent(float);
float arcsine(float);
float arccosine(float);
float arctangent(float);
void menu();

/* Main Function */
int main()
{
    int choice;
    float num1, num2, result;
    int power_num;

    /* Continuously display the menu until the user chooses to exit */
    while (1)
    {
        menu(); /* Displays the menu */

        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                result = add(num1, num2);
                printf("Result = %.2f\n", result);
                break;
            case 2:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                result = subtract(num1, num2);
                printf("Result = %.2f\n", result);
                break;
            case 3:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                result = multiply(num1, num2);
                printf("Result = %.2f\n", result);
                break;
            case 4:
                printf("Enter two numbers: ");
                scanf("%f %f", &num1, &num2);
                result = divide(num1, num2);
                printf("Result = %.2f\n", result);
                break;
            case 5:
                printf("Enter the number and exponent: ");
                scanf("%f %d", &num1, &power_num);
                result = power(num1, power_num);
                printf("Result = %.2f\n", result);
                break;
            case 6:
                printf("Enter the number: ");
                scanf("%f", &num1);
                result = square_root(num1);
                printf("Result = %.2f\n", result);
                break;
            case 7:
                printf("Enter the angle in radians: ");
                scanf("%f", &num1);
                result = sine(num1);
                printf("Result = %.2f\n", result);
                break;
            case 8:
                printf("Enter the angle in radians: ");
                scanf("%f", &num1);
                result = cosine(num1);
                printf("Result = %.2f\n", result);
                break;
            case 9:
                printf("Enter the angle in radians: ");
                scanf("%f", &num1);
                result = tangent(num1);
                printf("Result = %.2f\n", result);
                break;
            case 10:
                printf("Enter the value: ");
                scanf("%f", &num1);
                result = arcsine(num1);
                printf("Result = %.2f\n", result);
                break;
            case 11:
                printf("Enter the value: ");
                scanf("%f", &num1);
                result = arccosine(num1);
                printf("Result = %.2f\n", result);
                break;
            case 12:
                printf("Enter the value: ");
                scanf("%f", &num1);
                result = arctangent(num1);
                printf("Result = %.2f\n", result);
                break;
            case 13:
                exit(0); /* Exits the program */
            default:
                printf("Please enter a valid input.\n");
        }
    }

    return 0;
}

/* Function Definitions */
float add(float num1, float num2)
{
    return num1 + num2;
}

float subtract(float num1, float num2)
{
    return num1 - num2;
}

float multiply(float num1, float num2)
{
    return num1 * num2;
}

float divide(float num1, float num2)
{
    return num1 / num2;
}

float power(float num1, int power_num)
{
    return pow(num1, power_num);
}

float square_root(float num1)
{
    return sqrt(num1);
}

float sine(float num1)
{
    return sin(num1);
}

float cosine(float num1)
{
    return cos(num1);
}

float tangent(float num1)
{
    return tan(num1);
}

float arcsine(float num1)
{
    return asin(num1);
}

float arccosine(float num1)
{
    return acos(num1);
}

float arctangent(float num1)
{
    return atan(num1);
}

void menu()
{
    printf("\n");
    printf("***Scientific Calculator***\n");
    printf("\n");
    printf("1 - Addition\n");
    printf("2 - Subtraction\n");
    printf("3 - Multiplication\n");
    printf("4 - Division\n");
    printf("5 - Power\n");
    printf("6 - Square Root\n");
    printf("7 - Sine\n");
    printf("8 - Cosine\n");
    printf("9 - Tangent\n");
    printf("10 - Arcsine\n");
    printf("11 - Arccosine\n");
    printf("12 - Arctangent\n");
    printf("13 - Exit\n");
    printf("\n");
}