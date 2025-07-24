//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

int main()
{
    float num1, num2, result;
    char operator, again;

    printf("Welcome to the Paranoid Scientific Calculator!\n");

    do
    {
        printf("\nEnter a mathematical expression (e.g. 2 + 2): ");
        scanf("%f %c %f", &num1, &operator, &num2);

        switch(operator)
        {
            case '+':
                result = num1 + num2;
                printf("Result: %.2f\n", result);
                break;
            case '-':
                result = num1 - num2;
                printf("Result: %.2f\n", result);
                break;
            case '*':
                result = num1 * num2;
                printf("Result: %.2f\n", result);
                break;
            case '/':
                if(num2 == 0)
                {
                    printf("Paranoia Alert! Divide by zero error!\n");
                    exit(0);
                }
                else
                {
                    result = num1 / num2;
                    printf("Result: %.2f\n", result);
                }
                break;
            case '^':
                result = pow(num1, num2);
                printf("Result: %.2f\n", result);
                break;
            case '%':
                if(num2 == 0)
                {
                    printf("Paranoia Alert! Divide by zero error!\n");
                    exit(0);
                }
                else
                {
                    result = fmod(num1, num2);
                    printf("Result: %.2f\n", result);
                }
                break;
            case 's':
                result = sin(num1 * PI / 180.0);
                printf("Result: %.2f\n", result);
                break;
            case 'c':
                result = cos(num1 * PI / 180.0);
                printf("Result: %.2f\n", result);
                break;
            case 't':
                result = tan(num1 * PI / 180.0);
                printf("Result: %.2f\n", result);
                break;
            case 'r':
                result = sqrt(num1);
                printf("Result: %.2f\n", result);
                break;
            default:
                printf("Invalid input! Paranoia Alert!\n");
        }

        printf("\nEnter 'y' to perform another calculation or any other key to exit: ");
        scanf(" %c", &again);

    } while(again == 'y' || again == 'Y');

    printf("Thank you for using the Paranoid Scientific Calculator!\n");

    return 0;
}