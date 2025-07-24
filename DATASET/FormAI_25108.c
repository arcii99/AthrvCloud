//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: genious
#include <stdio.h>
#include <math.h>

/* Function prototypes */
void printMenu();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double a, double b);
double modulus(double a, double b);
double sine(double a);
double cosine(double a);
double tangent(double a);
double arcsine(double a);
double arccosine(double a);
double arctangent(double a);

/* Main function */
int main()
{
    int choice;
    double a, b, result;

    while (1) // Infinite loop to keep the program running until user exits
    {
        printMenu(); // Print the menu
        scanf("%d", &choice); // Get user's choice

        switch (choice)
        {
            case 1:
                printf("Enter two numbers to add: ");
                scanf("%lf %lf", &a, &b);
                result = add(a, b);
                printf("Result: %lf\n", result);
                break;

            case 2:
                printf("Enter two numbers to subtract: ");
                scanf("%lf %lf", &a, &b);
                result = subtract(a, b);
                printf("Result: %lf\n", result);
                break;

            case 3:
                printf("Enter two numbers to multiply: ");
                scanf("%lf %lf", &a, &b);
                result = multiply(a, b);
                printf("Result: %lf\n", result);
                break;

            case 4:
                printf("Enter two numbers to divide: ");
                scanf("%lf %lf", &a, &b);

                if (b == 0)
                {
                    printf("Error: Division by zero!\n");
                }
                else
                {
                    result = divide(a, b);
                    printf("Result: %lf\n", result);
                }
                break;

            case 5:
                printf("Enter the base and exponent: ");
                scanf("%lf %lf", &a, &b);
                result = power(a, b);
                printf("Result: %lf\n", result);
                break;

            case 6:
                printf("Enter two numbers to find modulus: ");
                scanf("%lf %lf", &a, &b);
                result = modulus(a, b);
                printf("Result: %lf\n", result);
                break;

            case 7:
                printf("Enter the angle in degrees: ");
                scanf("%lf", &a);
                result = sine(a);
                printf("Result: %lf\n", result);
                break;

            case 8:
                printf("Enter the angle in degrees: ");
                scanf("%lf", &a);
                result = cosine(a);
                printf("Result: %lf\n", result);
                break;

            case 9:
                printf("Enter the angle in degrees: ");
                scanf("%lf", &a);
                result = tangent(a);
                printf("Result: %lf\n", result);
                break;

            case 10:
                printf("Enter the value of sine: ");
                scanf("%lf", &a);
                result = arcsine(a);
                printf("Result: %lf\n", result);
                break;

            case 11:
                printf("Enter the value of cosine: ");
                scanf("%lf", &a);
                result = arccosine(a);
                printf("Result: %lf\n", result);
                break;

            case 12:
                printf("Enter the value of tangent: ");
                scanf("%lf", &a);
                result = arctangent(a);
                printf("Result: %lf\n", result);
                break;

            case 13:
                printf("Exiting the program...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}

/* Function definitions */

/* Prints the menu */
void printMenu()
{
    printf("\nChoose an operation:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Power\n");
    printf("6. Modulus\n");
    printf("7. Sine\n");
    printf("8. Cosine\n");
    printf("9. Tangent\n");
    printf("10. Arcsine\n");
    printf("11. Arccosine\n");
    printf("12. Arctangent\n");
    printf("13. Exit\n\n");
}

/* Adds two numbers */
double add(double a, double b)
{
    return a + b;
}

/* Subtracts two numbers */
double subtract(double a, double b)
{
    return a - b;
}

/* Multiplies two numbers */
double multiply(double a, double b)
{
    return a * b;
}

/* Divides two numbers */
double divide(double a, double b)
{
    return a / b;
}

/* Raises an number to a power */
double power(double a, double b)
{
    return pow(a, b);
}

/* Finds the modulus of two numbers */
double modulus(double a, double b)
{
    return fmod(a, b);
}

/* Finds the sine of an angle in degrees */
double sine(double a)
{
    double rad = a * M_PI / 180;
    return sin(rad);
}

/* Finds the cosine of an angle in degrees */
double cosine(double a)
{
    double rad = a * M_PI / 180;
    return cos(rad);
}

/* Finds the tangent of an angle in degrees */
double tangent(double a)
{
    double rad = a * M_PI / 180;
    return tan(rad);
}

/* Finds the arcsine of a value */
double arcsine(double a)
{
    double rad = asin(a);
    return rad * 180 / M_PI;
}

/* Finds the arccosine of a value */
double arccosine(double a)
{
    double rad = acos(a);
    return rad * 180 / M_PI;
}

/* Finds the arctangent of a value */
double arctangent(double a)
{
    double rad = atan(a);
    return rad * 180 / M_PI;
}