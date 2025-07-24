//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: genious
/*
Classical Circuit Simulator Example Program

Description:
This program simulates a simple classical circuit consisting of two gates performing a logical AND operation.

Instructions:
1. Run the program
2. Follow the prompts to input values for A and B
3. The output of the circuit will be printed to the console

*/

#include <stdio.h>

// Define the logical AND gate
int andGate(int a, int b) {
    if (a == 1 && b == 1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int A, B, output;

    // Prompt the user to input values for A and B
    printf("Enter a value for A (0 or 1): ");
    scanf("%d", &A);
    printf("Enter a value for B (0 or 1): ");
    scanf("%d", &B);

    // Calculate the output of the circuit using the AND gate
    output = andGate(A, B);

    // Print the output to the console
    printf("The output of the circuit is: %d\n", output);

    return 0;
}