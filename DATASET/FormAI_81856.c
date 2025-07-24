//FormAI DATASET v1.0 Category: Arithmetic ; Style: rigorous
#include<stdio.h>

int main()
{
    int num1, num2, sum, difference, product, quotient, remainder;       // Variable declaration

    printf("Enter the first number: ");                                  // Prompt user to enter the first number
    scanf("%d", &num1);                                                  // Read user input

    printf("Enter the second number: ");                                 // Prompt user to enter the second number
    scanf("%d", &num2);                                                  // Read user input

    sum = num1 + num2;                                                    // Calculate the sum of two numbers
    difference = num1 - num2;                                             // Calculate the difference of two numbers
    product = num1 * num2;                                                // Calculate the product of two numbers
    
    if (num2 == 0)                                                        // Check if divisor is zero
    {
        printf("Error! Division by zero is not allowed.");                // Display error message and terminate the program
        return 1;
    }
    
    quotient = num1 / num2;                                               // Calculate the quotient of two numbers
    remainder = num1 % num2;                                              // Calculate the remainder of two numbers

    printf("The sum of %d and %d is %d\n", num1, num2, sum);              // Display the sum of two numbers
    printf("The difference between %d and %d is %d\n", num1, num2, difference);  // Display the difference of two numbers
    printf("The product of %d and %d is %d\n", num1, num2, product);      // Display the product of two numbers
    printf("The quotient of %d divided by %d is %d\n", num1, num2, quotient);     // Display the quotient of two numbers
    printf("The remainder when %d is divided by %d is %d\n", num1, num2, remainder);   // Display the remainder of two numbers

    return 0;
}