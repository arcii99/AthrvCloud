//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_GATES 100 // Maximum number of gates allowed in a circuit
#define MAX_WIRES 100 // Maximum number of wires allowed in a circuit

typedef struct {
    int in1;
    int in2;
    int out;
    char op; // Operation of the gate (AND, OR, XOR)
} Gate;

int num_wires; // Number of wires in the circuit
int num_gates; // Number of gates in the circuit
bool wires[MAX_WIRES]; // Values of each wire in the circuit
Gate gates[MAX_GATES]; // List of gates in the circuit

// Function to retrieve the value of a wire
bool get_wire_value(int wire) {
    if (wire < 0 || wire >= num_wires) {
        printf("ERROR: Invalid wire index\n");
        exit(1);
    }
    return wires[wire];
}

// Function to set the value of a wire
void set_wire_value(int wire, bool value) {
    if (wire < 0 || wire >= num_wires) {
        printf("ERROR: Invalid wire index\n");
        exit(1);
    }
    wires[wire] = value;
}

// Function to simulate a gate
void simulate_gate(Gate gate) {
    bool in1 = get_wire_value(gate.in1);
    bool in2 = get_wire_value(gate.in2);

    bool out;
    if (gate.op == 'A') {
        out = in1 && in2;
    } else if (gate.op == 'O') {
        out = in1 || in2;
    } else if (gate.op == 'X') {
        out = in1 ^ in2;
    } else {
        printf("ERROR: Invalid gate operation\n");
        exit(1);
    }

    set_wire_value(gate.out, out);
}

// Function to simulate the entire circuit for one cycle
void simulate_circuit() {
    for (int i = 0; i < num_gates; i++) {
        simulate_gate(gates[i]);
    }
}

int main() {
    // Initialize the wires and gates
    num_wires = 3;
    num_gates = 2;

    set_wire_value(0, true);
    set_wire_value(1, false);
    set_wire_value(2, false);

    gates[0].in1 = 0;
    gates[0].in2 = 1;
    gates[0].out = 2;
    gates[0].op = 'A';

    gates[1].in1 = 2;
    gates[1].in2 = -1;
    gates[1].out = 0;
    gates[1].op = 'X';

    // Simulate the circuit for one cycle
    simulate_circuit();

    // Print the output
    printf("%d %d %d\n", get_wire_value(0), get_wire_value(1), get_wire_value(2));

    return 0;
}