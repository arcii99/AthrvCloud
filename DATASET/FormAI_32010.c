//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: cheerful
// Let's create a program that will put a smile on your face - a performance-critical calculator!
#include <stdio.h>    // Standard input-output library
#include <stdlib.h>   // Library for general functions
#include <math.h>     // Library for mathematical functions
#include <time.h>     // Library for time functions
 
int main() {
    printf("Hello, I'm your cheerful calculator!\n");
    printf("I'm going to help you solve some math problems with lightning-fast speed! I guarantee it!\n");
 
    // Get user input
    float num1, num2;
    printf("Enter the first number: ");
    scanf("%f", &num1);
    printf("Enter the second number: ");
    scanf("%f", &num2);
 
    // Basic arithmetic operations
    float sum = num1 + num2;
    float diff = num1 - num2;
    float prod = num1 * num2;
    float quot = num1 / num2;
 
    // Display the results
    printf("\nHere are the results, my friend:\n");
    printf("The sum of %.2f and %.2f is: %.2f\n", num1, num2, sum);
    printf("The difference of %.2f and %.2f is: %.2f\n", num1, num2, diff);
    printf("The product of %.2f and %.2f is: %.2f\n", num1, num2, prod);
    printf("The quotient of %.2f and %.2f is: %.2f\n", num1, num2, quot);
 
    // Some more advanced calculations
    float sqrt1 = sqrt(num1);
    float sqrt2 = sqrt(num2);
    float pow1 = pow(num1, num2);
    float pow2 = pow(num2, num1);
 
    // Display the results
    printf("\nHere are some extra results, my friend:\n");
    printf("The square root of %.2f is: %.2f\n", num1, sqrt1);
    printf("The square root of %.2f is: %.2f\n", num2, sqrt2);
    printf("The %.2f to the power of %.2f is: %.2f\n", num1, num2, pow1);
    printf("The %.2f to the power of %.2f is: %.2f\n", num2, num1, pow2);
 
    // Time for some more advanced calculations!
    clock_t start, end;
    start = clock();
 
    for (int i = 0; i < 500000000; i++) {
        float result = num1 * num2 / sqrt(num1 + num2) + pow(num1, num2) - sqrt(num1 * num2);
    }
 
    end = clock();
    float time_taken = (float)((end - start) / CLOCKS_PER_SEC);
    printf("\n\nWoo-hoo! That was fast! The time taken to perform 500 million complex calculations was %f seconds!\n", time_taken);
 
    return 0;
}