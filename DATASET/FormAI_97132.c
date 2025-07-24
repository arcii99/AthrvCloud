//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: safe
#include<stdio.h>
#include<stdlib.h>

// This program simulates a classical circuit using C programming.

// Define some variables
int input_1, input_2, output;

int main() {
    // Get user input
    printf("Enter input 1 (0 or 1): ");
    scanf("%d", &input_1);
    printf("Enter input 2 (0 or 1): ");
    scanf("%d", &input_2);

    // Perform AND gate operation
    output = input_1 && input_2;

    // Print the result
    printf("Output: %d\n", output);

    return 0;
}