//FormAI DATASET v1.0 Category: Math exercise ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int num1 = rand() % 101; // Generates a random number in the range of 0 to 100
    int num2 = rand() % 101; // Generates another random number in the range of 0 to 100
    int sum = num1 + num2; // Calculates the sum of the two numbers

    printf("Oh my goodness! Can you believe the sum of %d and %d is %d?! I can't even!\n", num1, num2, sum);

    // Let's calculate the difference of the two numbers
    int diff = abs(num1 - num2); // abs to ensure a positive difference
    printf("Whoa, hold on a minute! The difference between %d and %d is %d?! Mind blown!\n", num1, num2, diff);

    // Let's calculate the product of the two numbers
    int prod = num1 * num2; // Calculates the product of the two numbers
    printf("I'm freaking out! The product of %d and %d is %d! This is madness!\n", num1, num2, prod);

    // Let's calculate the quotient of the two numbers
    double quot = (double)num1 / num2; // Calculates the quotient of the two numbers
    printf("What!? No way! The quotient of %d and %d is %0.2lf! Holy cow!\n", num1, num2, quot);

    // Let's calculate the remainder when num1 is divided by num2
    int rem = num1 % num2; // Calculates the remainder when num1 is divided by num2
    printf("Stop it! Just stop it! The remainder when %d is divided by %d is %d! I can't even deal!\n", num1, num2, rem);

    // Let's calculate the square of the first number
    int sq = num1 * num1; // Calculates the square of the first number
    printf("This is madness! The square of %d is %d! I can't handle this level of insanity!\n", num1, sq);

    // Let's calculate the cube of the second number
    int cube = num2 * num2 * num2; // Calculates the cube of the second number
    printf("What!? What!?? The cube of %d is %d! This is out of control!\n", num2, cube);

    return 0;
}