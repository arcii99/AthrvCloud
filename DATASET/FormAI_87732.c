//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: standalone
/* This is a simple classical circuit simulator for a single-qubit gate.
   This program simulates a Hadamard gate and applies it to a qubit in the |0⟩ state.
   The resulting state after the application of the Hadamard gate will be calculated and printed.
   The state of the qubit is represented using a 2 x 1 complex matrix. */

#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

int main() {
    double complex zero_state[2] = {1.0, 0.0};
    double complex hadamard_gate[2][2] = {{1.0/sqrt(2.0), 1.0/sqrt(2.0)}, {1.0/sqrt(2.0), -1.0/sqrt(2.0)}};

    // Apply the Hadamard gate to the qubit in the |0⟩ state
    double complex* result_state = malloc(2 * sizeof(double complex));
    for (int i=0; i<2; i++) {
        result_state[i] = 0.0 + 0.0*I;
        for (int j=0; j<2; j++) {
            result_state[i] += hadamard_gate[i][j] * zero_state[j];
        }
    }

    // Print the resulting state of the qubit
    printf("|0⟩ state after Hadamard gate:\n");
    printf("|0⟩: %.3f + %.3fi\n", creal(result_state[0]), cimag(result_state[0]));
    printf("|1⟩: %.3f + %.3fi\n", creal(result_state[1]), cimag(result_state[1]));

    free(result_state);
    return 0;
}