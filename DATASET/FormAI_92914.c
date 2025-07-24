//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

// Define maximum number of gates and inputs
#define MAX_GATES 10
#define MAX_INPUTS 5

// Define gate structure
struct Gate {
    char type[4]; // AND, OR, NOT
    int inputs[MAX_INPUTS];
    int num_inputs;
};

// Define global variables
int num_gates = 0;
struct Gate gates[MAX_GATES];

// Function to print all gates and their inputs
void printGates() {
    printf("Circuit Gates:\n");
    for (int i = 0; i < num_gates; i++) {
        printf("%s(", gates[i].type);
        for (int j = 0; j < gates[i].num_inputs; j++) {
            printf("%d", gates[i].inputs[j]);
            if (j != gates[i].num_inputs - 1) {
                printf(", ");
            }
        }
        printf(")\n");
    }
}

// Function to add a gate to the circuit
void addGate(char type[4], int inputs[], int num_inputs) {
    if (num_gates == MAX_GATES) {
        printf("Error: Maximum number of gates reached.\n");
        exit(1);
    }
    struct Gate gate;
    strncpy(gate.type, type, sizeof(gate.type));
    for (int i = 0; i < num_inputs; i++) {
        gate.inputs[i] = inputs[i];
    }
    gate.num_inputs = num_inputs;
    gates[num_gates] = gate;
    num_gates++;
}

// Main function
int main() {
    printf("Welcome to the paranoid circuit simulator!\n");

    // Test adding gates to the circuit
    int inputs1[] = {0, 1};
    addGate("AND", inputs1, 2);
    int inputs2[] = {0};
    addGate("NOT", inputs2, 1);
    int inputs3[] = {1, 2};
    addGate("OR", inputs3, 2);

    // Print all gates
    printGates();

    return 0;
}