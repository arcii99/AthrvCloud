//FormAI DATASET v1.0 Category: Error handling ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int dividend, divisor, quotient;
    printf("Enter dividend: ");
    if (scanf("%d", &dividend) != 1) { 
        printf("Error: Invalid input.\n");
        return 1;
    }
    printf("Enter divisor: ");
    if (scanf("%d", &divisor) != 1) {
        printf("Error: Invalid input.\n");
        return 1;
    }
    if (divisor == 0) {
        printf("Error: Division by zero.\n");
        return 1;
    }
    quotient = dividend / divisor;
    printf("Quotient: %d\n", quotient);
    if (quotient < 0 || quotient > 100) {
        printf("Error: Quotient out of range.\n");
        return 1;
    }
    double root = sqrt(quotient);
    if (isnan(root)) {
        printf("Error: Square root of negative number.\n");
        return 1;
    }
    printf("Square root of quotient: %lf\n", root);
    return 0;
}