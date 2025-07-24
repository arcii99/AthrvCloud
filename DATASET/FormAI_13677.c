//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: expert-level
// C Scientific Calculator Implementation Example Program
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function declarations
int display_menu();
void get_operands(double *operand1, double *operand2);
double add(double operand1, double operand2);
double subtract(double operand1, double operand2);
double multiply(double operand1, double operand2);
double divide(double operand1, double operand2);
double square(double operand);
double cube(double operand);
double power(double operand1, double operand2);
double absolute(double operand);
double square_root(double operand);
double logarithm(double operand);
double sine(double operand);
double cosine(double operand);
double tangent(double operand);

// main function
int main()
{
    int choice;
    double operand1, operand2;

    printf("****Welcome to C Scientific Calculator****\n");

    while (1)
    {
        choice = display_menu();

        switch (choice)
        {
        case 1:
            get_operands(&operand1, &operand2);
            printf("Result: %lf + %lf = %lf\n\n", operand1, operand2, add(operand1, operand2));
            break;

        case 2:
            get_operands(&operand1, &operand2);
            printf("Result: %lf - %lf = %lf\n\n", operand1, operand2, subtract(operand1, operand2));
            break;
            
        case 3:
            get_operands(&operand1, &operand2);
            printf("Result: %lf * %lf = %lf\n\n", operand1, operand2, multiply(operand1, operand2));
            break;
            
        case 4:
            get_operands(&operand1, &operand2);
            if (operand2 == 0)
            {
                printf("Error: Division by zero.\n\n");
            }
            else
            {
                printf("Result: %lf / %lf = %lf\n\n", operand1, operand2, divide(operand1, operand2));
            }
            break;
            
        case 5:
            printf("Enter the operand: ");
            scanf("%lf", &operand1);
            printf("Result: Square(%lf) = %lf\n\n", operand1, square(operand1));
            break;
            
        case 6:
            printf("Enter the operand: ");
            scanf("%lf", &operand1);
            printf("Result: Cube(%lf) = %lf\n\n", operand1, cube(operand1));
            break;
            
        case 7:
            get_operands(&operand1, &operand2);
            printf("Result: %lf to the power of %lf = %lf\n\n", operand1, operand2, power(operand1, operand2));
            break;
            
        case 8:
            printf("Enter the operand: ");
            scanf("%lf", &operand1);
            printf("Result: Absolute(%lf) = %lf\n\n", operand1, absolute(operand1));
            break;
            
        case 9:
            printf("Enter the operand: ");
            scanf("%lf", &operand1);
            if (operand1 < 0)
            {
                printf("Error: Square root of negative operand.\n\n");
            }
            else
            {
                printf("Result: Square root(%lf) = %lf\n\n", operand1, square_root(operand1));
            }
            break;
            
        case 10:
            printf("Enter the operand: ");
            scanf("%lf", &operand1);
            printf("Result: Log(%lf) = %lf\n\n", operand1, logarithm(operand1));
            break;
            
        case 11:
            printf("Enter the operand: ");
            scanf("%lf", &operand1);
            printf("Result: Sin(%lf) = %lf\n\n", operand1, sine(operand1));
            break;
            
        case 12:
            printf("Enter the operand: ");
            scanf("%lf", &operand1);
            printf("Result: Cos(%lf) = %lf\n\n", operand1, cosine(operand1));
            break;
            
        case 13:
            printf("Enter the operand: ");
            scanf("%lf", &operand1);
            printf("Result: Tan(%lf) = %lf\n\n", operand1, tangent(operand1));
            break;

        case 14:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid Choice! Please try again.\n\n");
            break;
        }
    }

    return 0;
}

// function to display menu and return user choice
int display_menu()
{
    int choice;

    printf("Please select an option from the following: \n\n"
           "1. Add\n"
           "2. Subtract\n"
           "3. Multiply\n"
           "4. Divide\n"
           "5. Square\n"
           "6. Cube\n"
           "7. Power\n"
           "8. Absolute\n"
           "9. Square Root\n"
           "10. Logarithm\n"
           "11. Sine\n"
           "12. Cosine\n"
           "13. Tangent\n"
           "14. Exit\n\n"
           "Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

// function to get operands from user
void get_operands(double *operand1, double *operand2)
{
    printf("Enter first operand: ");
    scanf("%lf", operand1);
    printf("Enter second operand: ");
    scanf("%lf", operand2);
}

// function to add two operands
double add(double operand1, double operand2)
{
    return operand1 + operand2;
}

// function to subtract two operands
double subtract(double operand1, double operand2)
{
    return operand1 - operand2;
}

// function to multiply two operands
double multiply(double operand1, double operand2)
{
    return operand1 * operand2;
}

// function to divide two operands
double divide(double operand1, double operand2)
{
    return operand1 / operand2;
}

// function to calculate square of an operand
double square(double operand)
{
    return operand * operand;
}

// function to calculate cube of an operand
double cube(double operand)
{
    return operand * operand * operand;
}

// function to calculate power of an operand
double power(double operand1, double operand2)
{
    return pow(operand1, operand2);
}

// function to calculate absolute value of an operand
double absolute(double operand)
{
    return fabs(operand);
}

// function to calculate square root of an operand
double square_root(double operand)
{
    return sqrt(operand);
}

// function to calculate logarithm of an operand
double logarithm(double operand)
{
    return log(operand);
}

// function to calculate sine of an operand
double sine(double operand)
{
    return sin(operand);
}

// function to calculate cosine of an operand
double cosine(double operand)
{
    return cos(operand);
}

// function to calculate tangent of an operand
double tangent(double operand)
{
    return tan(operand);
}