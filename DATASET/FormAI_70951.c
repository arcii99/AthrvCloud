//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: complete
#include <stdio.h>
#include <math.h>

int main()
{
    char input;
    double num1, num2, result;

    printf("Welcome to the Scientific Calculator!\n");
    printf("Select an operation:\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Modulus (%%)\n");
    printf("6. Power (^)\n");
    printf("7. Square Root (sqrt)\n");
    printf("8. Logarithm (log10)\n");
    printf("9. Natural Logarithm (ln)\n");

    printf("Enter your choice: ");
    scanf("%c", &input);

    switch(input)
    {
        case '+':
            printf("Enter the numbers to be added: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '-':
            printf("Enter the numbers to be subtracted: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '*':
            printf("Enter the numbers to be multiplied: ");
            scanf("%lf %lf", &num1, &num2);
            result = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '/':
            printf("Enter the numbers to be divided: ");
            scanf("%lf %lf", &num1, &num2);

            if(num2 == 0)
            {
                printf("Error: Cannot divide by zero\n");
            }
            else
            {
                result = num1 / num2;
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
            }
            break;
        case '%':
            printf("Enter the numbers to find modulus: ");
            scanf("%lf %lf", &num1, &num2);

            long int quotient = (long int)(num1 / num2);
            long int remainder = (long int)(num1 - quotient * num2);
            printf("%.2lf %% %.2lf = %ld\n", num1, num2, remainder);
            break;
        case '^':
            printf("Enter the numbers for power calculation: ");
            scanf("%lf %lf", &num1, &num2);
            result = pow(num1, num2);
            printf("%.2lf ^ %.2lf = %.2lf\n", num1, num2, result);
            break;
        case 's':
        case 'S':
            printf("Enter the number for square root calculation: ");
            scanf("%lf", &num1);
            result = sqrt(num1);
            printf("sqrt(%.2lf) = %.2lf\n", num1, result);
            break;
        case 'l':
        case 'L':
            printf("Enter the number for logarithm calculation: ");
            scanf("%lf", &num1);
            result = log10(num1);
            printf("log10(%.2lf) = %.2lf\n", num1, result);
            break;
        case 'n':
        case 'N':
            printf("Enter the number for natural logarithm calculation: ");
            scanf("%lf", &num1);
            result = log(num1);
            printf("ln(%.2lf) = %.2lf\n", num1, result);
            break;
        default:
            printf("Invalid input. Please select a valid operation.\n");
    }

    return 0;
}