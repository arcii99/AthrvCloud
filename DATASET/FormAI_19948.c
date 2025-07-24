//FormAI DATASET v1.0 Category: Error handling ; Style: high level of detail
#include <stdio.h>

void divide(int dividend, int divisor) {
    if (divisor == 0) {
        // Throw an error message and return
        printf("Error: Cannot divide by zero!\n");
        return;
    }
    int quotient = dividend / divisor;
    printf("Quotient = %d\n", quotient);
}

int main() {
    int dividend = 10, divisor = 5;
    
    // Call the divide function with valid inputs
    divide(dividend, divisor);
    
    // Call the divide function with an invalid input (divisor = 0)
    divide(dividend, 0);
    
    return 0;
}