//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: high level of detail
#include <stdio.h>
#include <math.h>

// function prototypes
void displayMenu();
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
double power(double, double);
double root(double);

// main function
int main()
{
    int choice;
    double num1, num2, result;
    
    displayMenu();
    
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    // check if choice is valid
    if(choice < 1 || choice > 6) {
        printf("Invalid choice\n");
    }
    
    else if(choice == 5) {
        printf("Enter the number: ");
        scanf("%lf", &num1);
        result = root(num1);
        printf("Result = %.2lf\n", result);
    }
    
    else {
        printf("Enter first number: ");
        scanf("%lf", &num1);
        printf("Enter second number: ");
        scanf("%lf", &num2);
        
        switch(choice) {
            case 1:
                result = add(num1, num2);
                printf("Result = %.2lf\n", result);
                break;
            case 2:
                result = subtract(num1, num2);
                printf("Result = %.2lf\n", result);
                break;
            case 3:
                result = multiply(num1, num2);
                printf("Result = %.2lf\n", result);
                break;
            case 4:
                result = divide(num1, num2);
                printf("Result = %.2lf\n", result);
                break;
            case 6:
                result = power(num1, num2);
                printf("Result = %.2lf\n", result);
                break;
        }
    }
    
    return 0;
}

// function to display menu
void displayMenu()
{
    printf("Menu:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Square Root\n");
    printf("6. Power\n");
}

// function to add two numbers
double add(double num1, double num2)
{
    return num1 + num2;
}

// function to subtract two numbers
double subtract(double num1, double num2)
{
    return num1 - num2;
}

// function to multiply two numbers
double multiply(double num1, double num2)
{
    return num1 * num2;
}

// function to divide two numbers
double divide(double num1, double num2)
{
    // handling division by zero
    if(num2 == 0) {
        printf("Division by zero is not possible\n");
        return 0;
    }
    else {
        return num1 / num2;
    }
}

// function to calculate power of a number
double power(double num1, double num2)
{
    return pow(num1, num2);
}

// function to calculate square root of a number
double root(double num)
{
    if(num < 0) {
        printf("Square root of negative number is not possible\n");
        return 0;
    }
    else {
        return sqrt(num);
    }
}