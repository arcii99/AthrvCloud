//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: funny
#include<stdio.h>
#include<math.h>

/* This is a scientific calculator implementation that can perform basic arithmetic and some advanced mathematical operations */

int main()
{
    char option;
    float num1, num2, result;
    printf("Welcome to the Fun Scientific Calculator!\n");
    do
    {
        printf("\n\nSelect an operation to perform: \n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Exponentiation (x^y)\n");
        printf("6. Square root (√)\n");
        printf("7. Sine (sin)\n");
        printf("8. Cosine (cos)\n");
        printf("9. Tangent (tan)\n");
        printf("0. Exit\n");
        fflush(stdin);
        scanf("%c", &option);

        switch(option)
        {
            case '0':
                printf("Thank you for using the Fun Scientific Calculator!");
                break;

            case '1':
                printf("Enter two numbers to add: ");
                scanf("%f%f", &num1, &num2);
                result = num1 + num2;
                printf("Result: %.2f\n", result);
                break;

            case '2':
                printf("Enter two numbers to subtract: ");
                scanf("%f%f", &num1, &num2);
                result = num1 - num2;
                printf("Result: %.2f\n", result);
                break;

            case '3':
                printf("Enter two numbers to multiply: ");
                scanf("%f%f", &num1, &num2);
                result = num1 * num2;
                printf("Result: %.2f\n", result);
                break;

            case '4':
                printf("Enter two numbers to divide: ");
                scanf("%f%f", &num1, &num2);
                if(num2 == 0)
                {
                    printf("Cannot divide by zero!");
                }
                else
                {
                    result = num1 / num2;
                    printf("Result: %.2f\n", result);
                }
                break;

            case '5':
                printf("Enter two numbers to find the exponent: ");
                scanf("%f%f", &num1, &num2);
                result = pow(num1, num2);
                printf("Result: %.2f\n", result);
                break;

            case '6':
                printf("Enter a number to find the square root: ");
                scanf("%f", &num1);
                if(num1 < 0)
                {
                    printf("Invalid input! Cannot find square root of negative number.");
                }
                else
                {
                    result = sqrt(num1);
                    printf("Result: %.2f\n", result);
                }
                break;

            case '7':
                printf("Enter a number to find the sine: ");
                scanf("%f", &num1);
                result = sin(num1);
                printf("Result: %.2f\n", result);
                break;

            case '8':
                printf("Enter a number to find the cosine: ");
                scanf("%f", &num1);
                result = cos(num1);
                printf("Result: %.2f\n", result);
                break;

            case '9':
                printf("Enter a number to find the tangent: ");
                scanf("%f", &num1);
                result = tan(num1);
                printf("Result: %.2f\n", result);
                break;

            default:
                printf("Invalid input! Please select a valid option.\n");
        }

    } while(option != '0');

    return 0;
}