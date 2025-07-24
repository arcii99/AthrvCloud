//FormAI DATASET v1.0 Category: Math exercise ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateNum(int max)
{
    // Generate a random number between 1 and max
    srand(time(NULL));
    int num = rand() % max + 1;
    return num;
}

int main()
{
    int num1 = generateNum(10);
    int num2 = generateNum(10);
    int sum, difference, product, quotient, remainder;

    // Calculate sum
    sum = num1 + num2;

    // Calculate difference
    difference = num1 - num2;

    // Calculate product
    product = num1 * num2;

    // Check if division is possible
    if (num2 == 0)
    {
        printf("Division is not possible since the second number is zero\n");
    }
    else
    {
        // Calculate quotient
        quotient = num1 / num2;

        // Calculate remainder
        remainder = num1 % num2;
    }

    // Print the initial numbers
    printf("Number 1: %d\n", num1);
    printf("Number 2: %d\n", num2);

    // Print the results
    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", difference);
    printf("Product: %d\n", product);

    if (num2 != 0)
    {
        printf("Quotient: %d\n", quotient);
        printf("Remainder: %d\n", remainder);
    }

    return 0;
}