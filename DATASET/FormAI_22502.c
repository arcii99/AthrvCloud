//FormAI DATASET v1.0 Category: Arithmetic ; Style: secure
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, sum, diff, prod, quo, remainder;
    
    // Prompt user to enter two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    // Perform arithmetic operations
    sum = num1 + num2;
    diff = num1 - num2;
    prod = num1 * num2;
    quo = num1 / num2;
    remainder = num1 % num2;
    
    // Display the results
    printf("Sum = %d\n", sum);
    printf("Difference = %d\n", diff);
    printf("Product = %d\n", prod);
    printf("Quotient = %d\n", quo);
    printf("Remainder = %d\n", remainder);
    
    // Check for security issue and prompt user to exit
    if (num2 == 0) {
        printf("Division by zero is not allowed! Exiting the program.");
        exit(0);
    }
    
    return 0;
}