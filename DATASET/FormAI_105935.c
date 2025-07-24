//FormAI DATASET v1.0 Category: Arithmetic ; Style: sophisticated
#include<stdio.h> // Standard Input Output Header File

int main()
{
    // Declaring Variables
    int num1, num2, result;
    char operator;

    // Taking User Input
    printf("Enter a mathematical expression: ");
    scanf("%d %c %d", &num1, &operator, &num2);

    // Performing Arithmetic Operations According to the Operator Entered by the User
    switch(operator)
    {
        case '+':  result = num1 + num2; // Addition
                   break;

        case '-':  result = num1 - num2; // Subtraction
                   break;

        case '*':  result = num1 * num2; // Multiplication
                   break;

        case '/':  result = num1 / num2; // Division
                   break;

        case '%':  result = num1 % num2; // Modulus Operation
                   break;

        default: printf("\nInvalid Operator! Please enter the correct operator."); // When the User Enters an Invalid Operator
                 return 0;
    }

    // Printing the final result
    printf("\nThe result of '%d %c %d' is: %d", num1, operator, num2, result);
    return 0;
}