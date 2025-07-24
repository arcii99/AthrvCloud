//FormAI DATASET v1.0 Category: Error handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Define variables
    double num1, num2, result;

    // Read input from user
    printf("Enter the first number: ");
    if (scanf("%lf", &num1) != 1) {
        printf("ERROR: Invalid input for num1. Please enter a number.\n");
        exit(1);
    }

    printf("Enter the second number: ");
    if (scanf("%lf", &num2) != 1) {
        printf("ERROR: Invalid input for num2. Please enter a number.\n");
        exit(1);
    }

    // Calculate result
    if (num2 == 0) {
        printf("ERROR: Cannot divide by zero\n");
        exit(1);
    }

    result = num1 / num2;

    // Display result
    printf("%.2lf divided by %.2lf is %.2lf\n", num1, num2, result);

    return 0;
}