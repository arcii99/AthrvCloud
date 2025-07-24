//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// function prototypes
double addition(double, double);
double subtraction(double, double);
double multiplication(double, double);
double division(double, double);
double power(double, double);
double factorial(double);
double squareRoot(double);

// main function
int main()
{
    int choice;
    double num1, num2, result;

    do{
        // Display choice menu to the user
        printf("\n\n");
        printf("Scientific Calculator\n");
        printf("--------------------------------------\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Power\n");
        printf("6. Factorial\n");
        printf("7. Square Root\n");
        printf("8. Exit\n");

        // Take user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        //Perform operations based on the user's choice
        switch(choice){
            case 1:
                printf("Enter two numbers to add: ");
                scanf("%lf %lf", &num1, &num2);
                result = addition(num1, num2);
                printf("Result: %.2lf\n", result);
                break;

            case 2:
                printf("Enter two numbers to subtract: ");
                scanf("%lf %lf", &num1, &num2);
                result = subtraction(num1, num2);
                printf("Result: %.2lf\n", result);
                break;

            case 3:
                printf("Enter two numbers to multiply: ");
                scanf("%lf %lf", &num1, &num2);
                result = multiplication(num1, num2);
                printf("Result: %.2lf\n", result);
                break;

            case 4:
                printf("Enter two numbers to divide: ");
                scanf("%lf %lf", &num1, &num2);

                // Check if second number is zero
                if(num2 == 0){
                    printf("Error: Divide by zero\n");
                    break;
                }

                result = division(num1, num2);
                printf("Result: %.2lf\n", result);
                break;


            case 5:
                printf("Enter base number: ");
                scanf("%lf", &num1);

                printf("Enter exponent number: ");
                scanf("%lf", &num2);

                result = power(num1, num2);
                printf("Result: %.2lf\n", result);
                break;

            case 6:
                printf("Enter a number to find factorial: ");
                scanf("%lf", &num1);

                // check if the number is negative or not an integer
                if (num1 < 0 || floor(num1) != num1){
                    printf("Error: Invalid input\n");
                    break;
                }

                result = factorial(num1);
                printf("Result: %.2lf\n", result);
                break;

            case 7:
                printf("Enter a number to find square root: ");
                scanf("%lf", &num1);

                // check if the number is negative
                if (num1 < 0){
                    printf("Error: Invalid input\n");
                    break;
                }

                result = squareRoot(num1);
                printf("Result: %.2lf\n", result);
                break;

            case 8:
                printf("Exiting...");
                exit(0);
                break;

            default:
                printf("Error: Invalid input\n");
                break;
        }

    } while(choice != 8);

    return 0;
}

// function definitions
double addition(double num1, double num2)
{
    return num1 + num2;
}

double subtraction(double num1, double num2)
{
    return num1 - num2;
}

double multiplication(double num1, double num2)
{
    return num1 * num2;
}

double division(double num1, double num2)
{
    return num1 / num2;
}

double power(double base, double exponent)
{
    return pow(base, exponent);
}

double factorial(double num)
{
    if (num == 0 || num == 1){
        return 1;
    } else{
        return num * factorial(num-1);
    }
}

double squareRoot(double num)
{
    return sqrt(num);
}