//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_GATE_SIZE 1024
#define MAX_CIRCUIT_SIZE 4

typedef struct Gate {
    int idx;
    char type;
    int qubits[2];
    double theta, phi, lambda;
} Gate;

typedef struct Circuit {
    int size;
    Gate gates[MAX_GATE_SIZE];
} Circuit;

int main() {
    Circuit circuit;
    circuit.size = 0;

    Gate gate1 = {0, 'H', {0}, 0, 0, 0};
    Gate gate2 = {1, 'X', {1}, 0, 0, 0};
    Gate gate3 = {2, 'C', {0, 1}, 0, M_PI, 0};

    circuit.gates[0] = gate1;
    circuit.gates[1] = gate2;
    circuit.gates[2] = gate3;

    circuit.size = 3;

    printf("Circuit simulation starting...\n");

    int qubit_states[MAX_CIRCUIT_SIZE] = {0, 0, 0, 0};
    qubit_states[0] = 1;

    for (int i = 0; i < circuit.size; i++) {
        Gate gate = circuit.gates[i];

        printf("Applying gate %c on qubits ", gate.type);

        for (int j = 0; j < 2; j++) {
            int qubit = gate.qubits[j];
            printf("%d ", qubit);

            if (gate.type == 'H') {
                // Hadamard gate
                double coef = 1 / sqrt(2);
                qubit_states[qubit] = coef * (qubit_states[qubit] + pow(-1, qubit_states[qubit+1]));
                qubit_states[qubit+1] = coef * (qubit_states[qubit+1] + pow(-1, qubit_states[qubit]));
            } else if (gate.type == 'X') {
                // Pauli X gate
                qubit_states[qubit] = !qubit_states[qubit];
            } else if (gate.type == 'C') {
                // Controlled phase gate
                int ctrl = gate.qubits[0];
                int target = gate.qubits[1];
                if (qubit_states[ctrl] && qubit_states[target]) {
                    qubit_states[target] = -qubit_states[target];
                }
            }
        }

        printf("\n");
    }

    printf("Final qubit states:");

    for (int i = 0; i < MAX_CIRCUIT_SIZE; i++) {
        printf(" %d", qubit_states[i]);
    }

    printf("\n");

    return 0;
}