//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_GATES 1000
#define MAX_NAME_LEN 10
#define true 1
#define false 0

enum GateType {not, and, or, xor};

// Definition of a single gate
typedef struct Gate Gate;
struct Gate {
    enum GateType type; // NOT, AND, OR, XOR
    char *output; // Output gate
    char *input1; // First input gate
    char *input2; // Second input gate
};

// Global array of gates
Gate gates[MAX_GATES];
int numGates = 0;

/* 
 * Adds a new gate to the circuit
 * type: The type of the new gate
 * output: The output gate of the new gate
 * input1: The first input gate of the new gate
 * input2: The second input gate of the new gate (NULL if gate is NOT)
 */
void addGate(enum GateType type, char *output, char *input1, char *input2) {
    if (numGates >= MAX_GATES) {
        fprintf(stderr, "ERROR: Maximum gates exceeded\n");
        exit(EXIT_FAILURE);
    }
    gates[numGates].type = type;
    gates[numGates].output = strdup(output);
    gates[numGates].input1 = strdup(input1);
    if (type != not) {
        gates[numGates].input2 = strdup(input2);
    } else {
        gates[numGates].input2 = NULL;
    }
    numGates++;
}

/* 
 * Prints the global array of gates
 */
void printGates() {
    for (int i = 0; i < numGates; i++) {
        printf("%d: %s = ", i, gates[i].output);
        switch (gates[i].type) {
            case not:
                printf("NOT %s\n", gates[i].input1);
                break;
            case and:
                printf("%s AND %s\n", gates[i].input1, gates[i].input2);
                break;
            case or:
                printf("%s OR %s\n", gates[i].input1, gates[i].input2);
                break;
            case xor:
                printf("%s XOR %s\n", gates[i].input1, gates[i].input2);
                break;
        }
    }
    printf("\n");
}

/* 
 * Simulates the circuit using the given input values
 * inputs: The array of input values (0 or 1)
 * numInputs: The number of input values
 * output: The output gate to simulate
 * Returns 0 or 1, depending on the value of the output gate
 */
int simulate(int inputs[], int numInputs, char *output) {
    for (int i = 0; i < numGates; i++) {
        Gate gate = gates[i];
        if (strcmp(gate.output, output) == 0) {
            switch (gate.type) {
                case not:
                    if (strcmp(gate.input1, "1") == 0) {
                        return 0;
                    } else {
                        return 1;
                    }
                    break;
                case and:
                    if (simulate(inputs, numInputs, gate.input1) == 1 &&
                            simulate(inputs, numInputs, gate.input2) == 1) {
                        return 1;
                    } else {
                        return 0;
                    }
                    break;
                case or:
                    if (simulate(inputs, numInputs, gate.input1) == 1 ||
                            simulate(inputs, numInputs, gate.input2) == 1) {
                        return 1;
                    } else {
                        return 0;
                    }
                    break;
                case xor:
                    if (simulate(inputs, numInputs, gate.input1) !=
                            simulate(inputs, numInputs, gate.input2)) {
                        return 1;
                    } else {
                        return 0;
                    }
                    break;
            }
        }
    }
    fprintf(stderr, "ERROR: Output gate not found\n");
    exit(EXIT_FAILURE);
}

int main() {
    addGate(not, "o1", "i1", NULL);
    addGate(and, "o2", "o1", "i2");
    addGate(or, "o3", "i3", "o2");
    addGate(xor, "o4", "i4", "i5");
    int inputs[] = {0, 1, 0, 1, 0};
    int output = simulate(inputs, 5, "o3");
    printf("Output: %d\n", output);
    printGates();
    return 0;
}