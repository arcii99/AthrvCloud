//FormAI DATASET v1.0 Category: Arithmetic ; Style: sophisticated
#include <stdio.h>

int main() {
    // Declare variables
    int num1, num2, sum, diff, prod, quo, rem;
    
    // Ask user for input
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    
    // Perform arithmetic operations
    sum = num1 + num2;
    diff = num1 - num2;
    prod = num1 * num2;
    quo = num1 / num2;
    rem = num1 % num2;
    
    // Output results
    printf("The sum of %d and %d is %d\n", num1, num2, sum);
    printf("The difference between %d and %d is %d\n", num1, num2, diff);
    printf("The product of %d and %d is %d\n", num1, num2, prod);
    printf("The quotient when %d is divided by %d is %d\n", num1, num2, quo);
    printf("The remainder when %d is divided by %d is %d\n", num1, num2, rem);
    
    return 0;
}