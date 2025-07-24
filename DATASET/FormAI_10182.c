//FormAI DATASET v1.0 Category: Math exercise ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This program generates unique math exercise examples.
// Each time it runs, a different set of exercises is created
// based on the random values generated for each exercise.

int main() {
    srand(time(0)); // Seed the random number generator with the current time

    int numExercises = 10; // Number of exercises to generate
    int maxNum = 100; // Maximum value for operands

    printf("Welcome to Math Exercise Generator!\n\n");
    printf("You will be presented with %d unique math exercises:\n\n", numExercises);

    for (int i=0; i<numExercises; i++) {
        int a = rand() % maxNum + 1; // Generate random value for operand a
        int b = rand() % maxNum + 1; // Generate random value for operand b
        int op = rand() % 3; // Generate random value for operator

        int result = 0; // Variable to store the result of the exercise
        char sign = ' '; // Variable to store the operator symbol

        switch (op) {
            case 0: // Addition operator
                result = a + b;
                sign = '+';
                break;
            case 1: // Subtraction operator
                result = a - b;
                sign = '-';
                break;
            case 2: // Multiplication operator
                result = a * b;
                sign = '*';
                break;
        }

        printf("%d. %d %c %d = ________\n", i+1, a, sign, b); // Print the exercise
    }

    return 0;
}