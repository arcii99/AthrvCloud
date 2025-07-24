//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: futuristic
#include <stdio.h>
#include <stdbool.h>

// Function to simulate a classical circuit and compute the output
bool simulate_circuit(bool input1, bool input2, bool input3, bool input4) {
    bool gate1 = input1 && input2;
    bool gate2 = !input3;
    bool gate3 = (gate1 || gate2) && input4;
    return gate3;
}

int main() {
    printf("Welcome to the futuristic Classical Circuit Simulator!\n\n");

    // Get the input values from the user
    bool input1, input2, input3, input4;
    printf("Please enter the input values (0 or 1) for the circuit:\n");
    printf("Input 1: ");
    scanf("%d", &input1);
    printf("Input 2: ");
    scanf("%d", &input2);
    printf("Input 3: ");
    scanf("%d", &input3);
    printf("Input 4: ");
    scanf("%d", &input4);

    // Simulate the circuit and compute the output
    bool output = simulate_circuit(input1, input2, input3, input4);

    // Print the output value
    printf("\nThe output of the circuit is: %d", output);

    return 0;
}