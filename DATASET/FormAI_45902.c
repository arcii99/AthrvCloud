//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: paranoid
#include <stdio.h>

#define MAX_GATES 100
#define MAX_INPUTS 10

typedef struct Circuit {
    int num_gates;
    int num_inputs;
    int inputs[MAX_INPUTS];
    int gate_inputs[MAX_GATES][2];
    int gate_outputs[MAX_GATES];
} Circuit;

void init_circuit(Circuit* circuit, int num_inputs) {
    circuit->num_gates = 0;
    circuit->num_inputs = num_inputs;
    for (int i = 0; i < num_inputs; ++i) {
        circuit->inputs[i] = 0;
    }
}

void add_gate(Circuit* circuit, int in1, int in2) {
    if (circuit->num_gates < MAX_GATES) {
        circuit->gate_inputs[circuit->num_gates][0] = in1;
        circuit->gate_inputs[circuit->num_gates][1] = in2;
        circuit->gate_outputs[circuit->num_gates] = 0;
        circuit->num_gates++;
    }
}

void set_input(Circuit* circuit, int idx, int value) {
    if (idx < circuit->num_inputs) {
        circuit->inputs[idx] = value;
    }
}

int evaluate_gate(Circuit* circuit, int gate_idx) {
    int in1 = circuit->gate_inputs[gate_idx][0];
    int in2 = circuit->gate_inputs[gate_idx][1];
    int val1 = (in1 < circuit->num_inputs) ? circuit->inputs[in1] : circuit->gate_outputs[in1 - circuit->num_inputs];
    int val2 = (in2 < circuit->num_inputs) ? circuit->inputs[in2] : circuit->gate_outputs[in2 - circuit->num_inputs];
    int output = (val1 & val2);
    circuit->gate_outputs[gate_idx] = output;

    // introduce paranoia
    switch (output) {
        case 0:
            printf("Gate %d evaluates to 0\n", gate_idx);
            break;
        case 1:
            printf("Gate %d evaluates to 1\n", gate_idx);
            break;
        default:
            printf("ERROR: Gate %d evaluates to %d\n", gate_idx, output);
            break;
    }

    return output;
}

int evaluate_circuit(Circuit* circuit) {
    for (int i = 0; i < circuit->num_gates; ++i) {
        evaluate_gate(circuit, i);
    }
    return circuit->gate_outputs[circuit->num_gates - 1];
}

int main() {
    Circuit circuit;
    int num_inputs = 3;
    init_circuit(&circuit, num_inputs);

    // add some paranoid gates
    add_gate(&circuit, 1, 2);
    add_gate(&circuit, 0, 3);
    add_gate(&circuit, 4, 5);

    set_input(&circuit, 0, 1);
    set_input(&circuit, 1, 0);
    set_input(&circuit, 2, 1);

    int output = evaluate_circuit(&circuit);
    printf("Final output: %d\n", output);

    return 0;
}