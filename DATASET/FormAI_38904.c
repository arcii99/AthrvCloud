//FormAI DATASET v1.0 Category: Arithmetic ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

/*
 * Function to perform arithmetic operations
 * on two given integers a and b
 */
void perform_arithmetic_operations(int a, int b) {

    // Addition of a and b
    int sum = a + b;
    printf("Sum of %d and %d is: %d \n", a, b, sum);

    // Subtraction of b from a
    int difference = a - b;
    printf("Difference of %d and %d is: %d \n", a, b, difference);

    // Multiplication of a and b
    int multiplication = a * b;
    printf("Product of %d and %d is: %d \n", a, b, multiplication);

    // Division of a by b
    if (b != 0) {
        float division = (float)a / b;
        printf("Division of %d by %d is: %.2f \n", a, b, division);
    }

    // Modulus of a and b
    if (b != 0) {
        int modulus = a % b;
        printf("Modulus of %d and %d is: %d \n", a, b, modulus);
    }

    // Incrementing a and storing it in a new variable
    int increment_a = ++a;
    printf("Incrementing %d by 1 gives: %d \n", --a, increment_a);

    // Decrementing b and storing it in a new variable
    int decrement_b = --b;
    printf("Decrementing %d by 1 gives: %d \n", ++b, decrement_b);
}

/*
 * Main function to test the above logic
 */
int main() {
    int a = 10, b = 5;
    perform_arithmetic_operations(a, b);
    return 0;
}