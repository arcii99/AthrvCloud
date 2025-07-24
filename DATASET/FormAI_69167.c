//FormAI DATASET v1.0 Category: Arithmetic ; Style: innovative
#include <stdio.h>

int main() {
    int num1, num2, num3, result;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    printf("Calculating...\n");

    // Add the first two numbers
    result = num1 + num2;

    // Subtract the third number from the result so far
    result -= num3;

    // Multiply the result so far by the first number
    result *= num1;

    // Divide the result so far by the second number
    result /= num2;

    // Add the third number to the result
    result += num3;

    printf("Result: %d\n", result);

    return 0;
}