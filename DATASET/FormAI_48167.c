//FormAI DATASET v1.0 Category: Math exercise ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num1 = rand() % 101; // Generates a random number between 0 and 100 inclusive
    int num2 = rand() % 101;
    int num3 = rand() % 101;
    double result;

    printf("Welcome to the Genius Math Problem Solver!\n");
    printf("Today's challenge: Calculate the roots of the quadratic equation ax^2 + bx + c = 0\n");
    printf("Given: a = %d, b = %d, c = %d\n", num1, num2, num3);

    result = pow(num2, 2) - 4 * num1 * num3; // Calculate the discriminant

    if (result < 0) { // No real solutions
        printf("This equation has no real roots.\n");
    } else if (result == 0) { // One real solution
        printf("This equation has one real root, which is:\n");
        printf("x = %.2f\n", (-num2 / (2.0 * num1)));
    } else { // Two real solutions
        printf("This equation has two real roots, which are:\n");
        printf("x = %.2f and x = %.2f\n", (-num2 + sqrt(result)) / (2.0 * num1), (-num2 - sqrt(result)) / (2.0 * num1));
    }

    printf("Congratulations, you solved the problem like a true genius!\n");

    return 0;
}