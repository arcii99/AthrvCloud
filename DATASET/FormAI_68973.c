//FormAI DATASET v1.0 Category: Arithmetic ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize random seed
    srand(time(NULL));

    // Generate random number between 1 and 10
    int num1 = rand() % 10 + 1;

    // Generate random number between 1 and 5
    int num2 = rand() % 5 + 1;

    // Print out the generated numbers
    printf("Random number 1: %d\n", num1);
    printf("Random number 2: %d\n\n", num2);

    // Add the two numbers
    int sum = num1 + num2;
    printf("Addition: %d\n", sum);

    // Subtract the two numbers
    int diff = num1 - num2;
    printf("Subtraction: %d\n", diff);

    // Multiply the two numbers
    int prod = num1 * num2;
    printf("Multiplication: %d\n", prod);

    // Divide the two numbers
    int quot = num1 / num2;
    printf("Division: %d\n", quot);

    // Modulus of the two numbers
    int rem = num1 % num2;
    printf("Modulus: %d\n", rem);

    // Increment and decrement the two numbers
    num1++;
    num2--;
    printf("Incremented num1: %d\n", num1);
    printf("Decremented num2: %d\n", num2);

    // Calculate the average of the two numbers
    float avg = (float)(num1 + num2) / 2;
    printf("Average: %f\n", avg);

    // Check if num1 is greater than num2
    if(num1 > num2)
    {
        printf("num1 is greater than num2\n");
    }
    else
    {
        printf("num2 is greater than num1\n");
    }

    // Check if num1 is even or odd
    if(num1 % 2 == 0)
    {
        printf("num1 is even\n");
    }
    else
    {
        printf("num1 is odd\n");
    }

    // Check if num2 is negative
    if(num2 < 0)
    {
        printf("num2 is negative\n");
    }
    else
    {
        printf("num2 is non-negative\n");
    }

    return 0;
}