//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: expert-level
#include <stdio.h>
#include <math.h>

/* Function Declarations */
void printMenu(void);
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
double power(double, double);
double squareRoot(double);
double sine(double);
double cosine(double);
double tangent(double);
double inverseSine(double);
double inverseCosine(double);
double inverseTangent(double);

int main(void)
{
    int choice;
    double num1, num2, result;

    printf("\t\t Scientific Calculator\n");

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two numbers to add: ");
                scanf("%lf %lf", &num1, &num2);
                result = add(num1, num2);
                printf("Result: %lf\n", result);
                break;
            case 2:
                printf("Enter two numbers to subtract: ");
                scanf("%lf %lf", &num1, &num2);
                result = subtract(num1, num2);
                printf("Result: %lf\n", result);
                break;
            case 3:
                printf("Enter two numbers to multiply: ");
                scanf("%lf %lf", &num1, &num2);
                result = multiply(num1, num2);
                printf("Result: %lf\n", result);
                break;
            case 4:
                printf("Enter two numbers to divide: ");
                scanf("%lf %lf", &num1, &num2);
                result = divide(num1, num2);
                printf("Result: %lf\n", result);
                break;
            case 5:
                printf("Enter a number and its power: ");
                scanf("%lf %lf", &num1, &num2);
                result = power(num1, num2);
                printf("Result: %lf\n", result);
                break;
            case 6:
                printf("Enter a number to find the square root of: ");
                scanf("%lf", &num1);
                result = squareRoot(num1);
                printf("Result: %lf\n", result);
                break;
            case 7:
                printf("Enter a number in radians to find its sine: ");
                scanf("%lf", &num1);
                result = sine(num1);
                printf("Result: %lf\n", result);
                break;
            case 8:
                printf("Enter a number in radians to find its cosine: ");
                scanf("%lf", &num1);
                result = cosine(num1);
                printf("Result: %lf\n", result);
                break;
            case 9:
                printf("Enter a number in radians to find its tangent: ");
                scanf("%lf", &num1);
                result = tangent(num1);
                printf("Result: %lf\n", result);
                break;
            case 10:
                printf("Enter a number to find its inverse sine (in radians): ");
                scanf("%lf", &num1);
                result = inverseSine(num1);
                printf("Result: %lf\n", result);
                break;
            case 11:
                printf("Enter a number to find its inverse cosine (in radians): ");
                scanf("%lf", &num1);
                result = inverseCosine(num1);
                printf("Result: %lf\n", result);
                break;
            case 12:
                printf("Enter a number to find its inverse tangent (in radians): ");
                scanf("%lf", &num1);
                result = inverseTangent(num1);
                printf("Result: %lf\n", result);
                break;
            case 13:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 13.\n");
                break;
        }
    } while (choice != 13);

    return 0;
}

/* Function Definitions */

void printMenu(void)
{
    printf("Menu\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Sine\n");
    printf("8. Cosine\n");
    printf("9. Tangent\n");
    printf("10. Inverse Sine\n");
    printf("11. Inverse Cosine\n");
    printf("12. Inverse Tangent\n");
    printf("13. Exit\n");
    printf("Enter your choice: ");
}

double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    return a / b;
}

double power(double base, double exponent)
{
    return pow(base, exponent);
}

double squareRoot(double num)
{
    return sqrt(num);
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

double inverseSine(double num)
{
    return asin(num);
}

double inverseCosine(double num)
{
    return acos(num);
}

double inverseTangent(double num)
{
    return atan(num);
}