//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: peaceful
#include<stdio.h>
#include<math.h>

// Function declarations
float Addition(float, float);
float Subtraction(float, float);
float Multiplication(float, float);
float Division(float, float);
float Exponential(float, float);
float SquareRoot(float);
float CubeRoot(float);
float Sin(float);
float Cos(float);
float Tan(float);
float Log(float);
float Log10(float);

int main()
{
    char operation;
    float num1, num2, result;

    printf("\nWelcome to the Scientific Calculator\n");
    printf("------------------------------------\n");

    while (1) {
        printf("\nEnter an operation\n");
        printf("+ for Addition\n");
        printf("- for Subtraction\n");
        printf("* for Multiplication\n");
        printf("/ for Division\n");
        printf("^ for Exponential\n");
        printf("r for Square Root\n");
        printf("c for Cube Root\n");
        printf("s for Sin\n");
        printf("o for Cos\n");
        printf("t for Tan\n");
        printf("l for Log\n");
        printf("n for Log10\n");
        printf("q to Quit\n");

        printf("\nEnter the operation: ");
        scanf("%c", &operation);

        // Quit the program
        if (operation == 'q') {
            printf("\nThank you for using the calculator!\n");
            break;
        }

        // Get user input
        printf("\nEnter number 1: ");
        scanf("%f", &num1);
        if (operation != 'r' && operation != 'c' && operation != 's' && operation != 'o' && operation != 't' && operation != 'l' && operation != 'n') {
            printf("Enter number 2: ");
            scanf("%f", &num2);
        }

        // Check the operation and perform calculation
        switch (operation) {
            case '+':
                result = Addition(num1, num2);
                break;
            case '-':
                result = Subtraction(num1, num2);
                break;
            case '*':
                result = Multiplication(num1, num2);
                break;
            case '/':
                result = Division(num1, num2);
                break;
            case '^':
                result = Exponential(num1, num2);
                break;
            case 'r':
                result = SquareRoot(num1);
                break;
            case 'c':
                result = CubeRoot(num1);
                break;
            case 's':
                result = Sin(num1);
                break;
            case 'o':
                result = Cos(num1);
                break;
            case 't':
                result = Tan(num1);
                break;
            case 'l':
                result = Log(num1);
                break;
            case 'n':
                result = Log10(num1);
                break;
            default:
                printf("Invalid operation\n");
                continue;
        }

        // Print the result
        printf("Result: %f\n", result);
    }

    return 0;
}

// Function definitions

float Addition(float num1, float num2)
{
    return num1 + num2;
}

float Subtraction(float num1, float num2)
{
    return num1 - num2;
}

float Multiplication(float num1, float num2)
{
    return num1 * num2;
}

float Division(float num1, float num2)
{
    if (num2 == 0) {
        printf("Cannot divide by zero\n");
        return 0;
    } else {
        return num1 / num2;
    }
}

float Exponential(float num1, float num2)
{
    return pow(num1, num2);
}

float SquareRoot(float num1)
{
    if (num1 < 0) {
        printf("Invalid input for square root\n");
        return 0;
    } else {
        return sqrt(num1);
    }
}

float CubeRoot(float num1)
{
    return cbrt(num1);
}

float Sin(float num1)
{
    return sin(num1);
}

float Cos(float num1)
{
    return cos(num1);
}

float Tan(float num1)
{
    return tan(num1);
}

float Log(float num1)
{
    if (num1 <= 0) {
        printf("Invalid input for logarithm\n");
        return 0;
    } else {
        return log(num1);
    }
}

float Log10(float num1)
{
    if (num1 <= 0) {
        printf("Invalid input for logarithm\n");
        return 0;
    } else {
        return log10(num1);
    }
}