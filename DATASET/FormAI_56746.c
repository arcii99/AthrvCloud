//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_GATES 10
#define MAX_INPUTS 5
#define MAX_OUTPUTS 5

// Define a gate structure
typedef struct Gate {
    char type; // type of gate (AND/OR/XOR/NOT)
    int num_inputs; // number of inputs to the gate
    int inputs[MAX_INPUTS]; // array of inputs to the gate
    int output; // output of the gate
} Gate;

// Function to print the circuit
void print_circuit(Gate* gates, int num_gates, int num_inputs, int num_outputs) {
    printf("Circuit:\n");
    for (int i = 0; i < num_gates; i++) {
        printf("Gate %d: %c(", i, gates[i].type);
        for (int j = 0; j < gates[i].num_inputs; j++) {
            printf("%d", gates[i].inputs[j]);
            if (j < gates[i].num_inputs-1) {
                printf(",");
            }
        }
        printf(") => %d\n", gates[i].output);
    }
}

// Function to evaluate a gate
void evaluate_gate(Gate* gate) {
    int result;
    switch (gate->type) {
        case 'A': // AND gate
            result = gate->inputs[0];
            for (int i = 1; i < gate->num_inputs; i++) {
                result &= gate->inputs[i];
            }
            gate->output = result;
            break;
        case 'O': // OR gate
            result = gate->inputs[0];
            for (int i = 1; i < gate->num_inputs; i++) {
                result |= gate->inputs[i];
            }
            gate->output = result;
            break;
        case 'X': // XOR gate
            result = gate->inputs[0];
            for (int i = 1; i < gate->num_inputs; i++) {
                result ^= gate->inputs[i];
            }
            gate->output = result;
            break;
        case 'N': // NOT gate
            gate->output = !(gate->inputs[0]);
            break;
        default:
            printf("Error: invalid gate type\n");
            exit(1);
            break;
    }
}

// Function to simulate the circuit
void simulate_circuit(Gate* gates, int num_gates, int num_inputs, int num_outputs, int* inputs, int* outputs) {
    // Transfer input values to input gates
    for (int i = 0; i < num_inputs; i++) {
        gates[i].output = inputs[i];
    }

    // Evaluate gates in topological order
    for (int i = num_inputs; i < num_gates; i++) {
        for (int j = 0; j < gates[i].num_inputs; j++) {
            gates[i].inputs[j] = gates[gates[i].inputs[j]].output;
        }
        evaluate_gate(&gates[i]);
    }

    // Transfer output values from output gates
    for (int i = 0; i < num_outputs; i++) {
        outputs[i] = gates[num_gates-num_outputs+i].output;
    }
}

int main() {
    // Define the circuit
    int num_gates = 7;
    int num_inputs = 2;
    int num_outputs = 1;
    Gate gates[MAX_GATES] = {
        {'N', 1, {0}, 0}, // NOT gate with input from gate 0
        {'N', 1, {1}, 0}, // NOT gate with input from gate 1
        {'A', 2, {0,1}, 0}, // AND gate with inputs from gates 0 and 1
        {'O', 2, {0,1}, 0}, // OR gate with inputs from gates 0 and 1
        {'X', 2, {0,1}, 0}, // XOR gate with inputs from gates 0 and 1
        {'A', 2, {2,3}, 0}, // AND gate with inputs from gates 2 and 3
        {'O', 2, {4,5}, 0} // OR gate with inputs from gates 4 and 5
    };

    // Define input and output values
    int inputs[MAX_INPUTS] = {0, 1};
    int outputs[MAX_OUTPUTS];

    // Simulate the circuit
    simulate_circuit(gates, num_gates, num_inputs, num_outputs, inputs, outputs);

    // Print the circuit and output
    print_circuit(gates, num_gates, num_inputs, num_outputs);
    printf("Output: %d\n", outputs[0]);

    return 0;
}