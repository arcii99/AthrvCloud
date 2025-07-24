//FormAI DATASET v1.0 Category: Error handling ; Style: genious
#include <stdio.h>

// defining an error code
#define ERROR_CODE -1

// function prototype
int divide_numbers(int num1, int num2);

// main function
int main() {
    int dividend, divisor, result;
    
    printf("Enter the dividend: ");
    scanf("%d", &dividend);
    
    printf("Enter the divisor: ");
    scanf("%d", &divisor);
    
    result = divide_numbers(dividend, divisor);
    
    if (result == ERROR_CODE) {
        printf("Oops! Division by zero not possible\n");
    } else {
        printf("Result of division is: %d\n", result);
    }
    
    return 0;
}

// function to divide two numbers
int divide_numbers(int num1, int num2) {
    if (num2 == 0) {
        // error handling
        return ERROR_CODE;
    } else {
        return num1 / num2;
    }
}