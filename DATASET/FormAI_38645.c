//FormAI DATASET v1.0 Category: Arithmetic ; Style: brave
#include <stdio.h>

/* Brave Style Arithmetic Example Program */

int main() {
    // Declare and initialize variables and constants
    int num1 = 50; 
    int num2 = 10;
    const int NUM3 = 5;
    
    // Perform arithmetic operations
    int sum = num1 + num2;
    int diff = num1 - num2;
    int prod = num1 * num2;
    int div = num1 / num2;
    int mod = num1 % NUM3;
    int power = 1;
    
    // Calculate power using for loop
    for (int i = 1; i < NUM3+1; i++) {
        power *= num2;
    }
    
    // Print results
    printf("The sum of %d and %d is %d\n", num1, num2, sum);
    printf("The difference between %d and %d is %d\n", num1, num2, diff);
    printf("The product of %d and %d is %d\n", num1, num2, prod);
    printf("The quotient of %d divided by %d is %d\n", num1, num2, div);
    printf("%d modulo %d is %d\n", num1, NUM3, mod);
    printf("%d raised to the power of %d is %d\n", num2, NUM3, power);

    return 0;
}