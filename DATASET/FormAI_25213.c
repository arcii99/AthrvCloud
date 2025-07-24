//FormAI DATASET v1.0 Category: Error handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void divide_numbers(int dividend, int divisor) {
    if (divisor == 0) {
        // example of handling divide by zero error
        fprintf(stderr, "Error: Cannot divide by zero.\n");
        exit(EXIT_FAILURE);
    } else {
        int quotient = dividend / divisor;
        printf("The quotient is: %d\n", quotient);
    }
}

int main() {
    int dividend, divisor;
    
    printf("Enter the dividend: ");
    if (scanf("%d", &dividend) != 1) {
        // example of handling input error
        perror("Error");
        exit(EXIT_FAILURE);
    }
    
    printf("Enter the divisor: ");
    if (scanf("%d", &divisor) != 1) {
        // example of handling input error
        perror("Error");
        exit(EXIT_FAILURE);
    }
    
    divide_numbers(dividend, divisor);
    
    return 0;
}