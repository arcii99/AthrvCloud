//FormAI DATASET v1.0 Category: Math exercise ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // Seed random number generator with time

    // Generate two random integers between 1 and 10
    int num1 = rand() % 10 + 1;
    int num2 = rand() % 10 + 1;

    // Calculate sum, difference, product, and quotient of the two numbers
    int sum = num1 + num2;
    int diff = num1 - num2;
    int prod = num1 * num2;
    float quot = (float)num1 / num2;

    // Print the numbers and results
    printf("Number 1: %d\n", num1);
    printf("Number 2: %d\n", num2);
    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", diff);
    printf("Product: %d\n", prod);
    printf("Quotient: %f\n", quot);

    // Generate a random integer between 1 and 100
    int num3 = rand() % 100 + 1;

    // Calculate the square root and logarithm base 10 of num3
    float sqrt_num3 = sqrt(num3);
    float log_num3 = log10(num3);

    // Print the square root and logarithm base 10 of num3
    printf("\nNumber 3: %d\n", num3);
    printf("Square Root: %f\n", sqrt_num3);
    printf("Logarithm Base 10: %f\n", log_num3);

    return 0;
}