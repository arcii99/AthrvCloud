//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: visionary
#include <stdio.h>
#include <math.h>

#define MAX_N 256

typedef struct CircuitNode {
    int gateType; // type of the gate (0 for input, 1 for output, 2 for NOT, 3 for AND, 4 for OR, 5 for XOR)
    int input1; // index of the first input (ignore if not applicable)
    int input2; // index of the second input (ignore if not applicable)
    int output; // index of the output wire (ignore if type is 0 or 1)
} CircuitNode;

void simulate(CircuitNode* circuit, int n) {
    int values[MAX_N] = {0}; // initialize all values to 0
    for (int i = 0; i < n; i++) {
        switch (circuit[i].gateType) {
            case 0: // input gate
                printf("Enter value for input wire %d: ", i);
                scanf("%d", &values[i]);
                break;
            case 2: // NOT gate
                values[circuit[i].output] = !values[circuit[i].input1];
                break;
            case 3: // AND gate
                values[circuit[i].output] = values[circuit[i].input1] && values[circuit[i].input2];
                break;
            case 4: // OR gate
                values[circuit[i].output] = values[circuit[i].input1] || values[circuit[i].input2];
                break;
            case 5: // XOR gate
                values[circuit[i].output] = !!values[circuit[i].input1] ^ !!values[circuit[i].input2];
                break;
            case 1: // output gate
                printf("Output for output wire %d: %d\n", i, values[circuit[i].input1]);
                break;
        }
    }
}

int main() {
    CircuitNode circuit[MAX_N] = {
        {0, 0, 0, 0}, // input for wire 0
        {0, 0, 0, 0}, // input for wire 1
        {3, 0, 1, 2}, // AND gate with inputs from wires 0 and 1, output on wire 2
        {1, 2, 0, 0}  // output for wire 2
    };
    simulate(circuit, 4);
    return 0;
}