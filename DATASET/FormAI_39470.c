//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: configurable
#include<stdio.h>
#include<math.h>

#define ADDITION 1
#define SUBTRACTION 2
#define MULTIPLICATION 3
#define DIVISION 4
#define POWER 5
#define FACTORIAL 6
#define SQUARE_ROOT 7
#define NATURAL_LOG 8
#define LOG_BASE_10 9
#define EXIT 0

void printMenu()
{
    printf("Welcome to the Scientific Calculator\n");
    printf("Please choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Factorial\n");
    printf("7. Square Root\n");
    printf("8. Natural Logarithm\n");
    printf("9. Logarithm with base 10\n");
    printf("0. Exit\n\n");
}

int getInput()
{
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

double getOperand()
{
    double operand;
    printf("Enter the operand: ");
    scanf("%lf", &operand);
    return operand;
}

int getFactorial(int n)
{
    int i, factorial = 1;
    for(i=1; i<=n; i++)
        factorial *= i;
    return factorial;
}

int main()
{
    int choice;
    double operand1, operand2, result;

    do
    {
        printMenu();
        choice = getInput();

        switch(choice)
        {
            case ADDITION:
                operand1 = getOperand();
                operand2 = getOperand();
                result = operand1 + operand2;
                printf("Result: %lf\n", result);
                break;

            case SUBTRACTION:
                operand1 = getOperand();
                operand2 = getOperand();
                result = operand1 - operand2;
                printf("Result: %lf\n", result);
                break;

            case MULTIPLICATION:
                operand1 = getOperand();
                operand2 = getOperand();
                result = operand1 * operand2;
                printf("Result: %lf\n", result);
                break;

            case DIVISION:
                operand1 = getOperand();
                operand2 = getOperand();
                if(operand2 == 0)
                    printf("Cannot divide by zero\n");
                else
                {
                    result = operand1 / operand2;
                    printf("Result: %lf\n", result);
                }
                break;

            case POWER:
                operand1 = getOperand();
                operand2 = getOperand();
                result = pow(operand1, operand2);
                printf("Result: %lf\n", result);
                break;

            case FACTORIAL:
                operand1 = getOperand();
                if(operand1 < 0)
                    printf("Cannot find factorial of a negative number\n");
                else if(operand1 == 0 || operand1 == 1)
                    printf("Result: 1\n");
                else
                {
                    result = getFactorial(operand1);
                    printf("Result: %lf\n", result);
                }
                break;

            case SQUARE_ROOT:
                operand1 = getOperand();
                if(operand1 < 0)
                    printf("Cannot find square root of a negative number\n");
                else
                {
                    result = sqrt(operand1);
                    printf("Result: %lf\n", result);
                }
                break;

            case NATURAL_LOG:
                operand1 = getOperand();
                if(operand1 < 0)
                    printf("Cannot find natural logarithm of a negative number\n");
                else
                {
                    result = log(operand1);
                    printf("Result: %lf\n", result);
                }
                break;

            case LOG_BASE_10:
                operand1 = getOperand();
                if(operand1 < 0)
                    printf("Cannot find logarithm with base 10 of a negative number\n");
                else
                {
                    result = log10(operand1);
                    printf("Result: %lf\n", result);
                }
                break;

            case EXIT:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    }while(choice != EXIT);

    return 0;
}