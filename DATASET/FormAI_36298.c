//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Defines the maximum number of nodes (should be a power of 2)
#define MAX_NODES 16

// Defines the structure of a node
typedef struct {
    int bit;
    float amplitude;
    float phase;
} qubit;

// Defines the structure of a gate
typedef struct {
    int control;
    int target;
    float theta;
} gate;

// Initializes the node values
void initialize(qubit *n) {
    for(int i=0; i<MAX_NODES; i++) {
        n[i].bit = 0;
        n[i].amplitude = 0;
        n[i].phase = 0;
    }
    n[0].amplitude = 1;
}

// Generates a quantum state based on the node values
void generateState(qubit *n, char *state) {
    for(int i=0; i<MAX_NODES; i++) {
        state[i] = '0' + n[i].bit;
    }
    state[MAX_NODES] = '\0';
}

// Applies the Hadamard gate to a node
void hadamard(qubit *n, int target) {
    float sqrt2 = sqrt(2);
    qubit temp[MAX_NODES];

    for(int i=0; i<MAX_NODES; i++) {
        temp[i] = n[i];
    }

    for(int i=0; i<MAX_NODES; i++) {
        float coef1 = (float)pow(-1, (i & target) >> target) / sqrt2;
        float coef2 = (float)pow(-1, 1 - ((i & target) >> target)) / sqrt2;

        n[i].amplitude = coef1 * temp[i].amplitude + coef2 * temp[i ^ target].amplitude;
        n[i].phase = temp[i].phase + temp[i ^ target].phase;
        n[i].bit = temp[i].bit;
    }
}

// Applies the CNOT gate to a node
void cnot(qubit *n, int control, int target) {
    float sqrt2 = sqrt(2);
    qubit temp[MAX_NODES];

    for(int i=0; i<MAX_NODES; i++) {
        temp[i] = n[i];
    }

    for(int i=0; i<MAX_NODES; i++) {
        if(((i & control) >> control) == 1) {
            float coef1 = (float)pow(-1, (i & target) >> target) / sqrt2;
            float coef2 = (float)pow(-1, 1 - ((i & target) >> target)) / sqrt2;

            n[i].amplitude = coef1 * temp[i ^ target].amplitude + coef2 * temp[i].amplitude;
            n[i].phase = temp[i ^ target].phase + temp[i].phase;
            n[i].bit = temp[i].bit;
        }
        else {
            n[i] = temp[i];
        }
    }
}

// Applies the phase shift gate to a node
void phaseShift(qubit *n, int target, float theta) {
    for(int i=0; i<MAX_NODES; i++) {
        if(((i & target) >> target) == 1) {
            n[i].phase += theta;
        }
    }
}

int main() {
    qubit nodes[MAX_NODES];
    char state[MAX_NODES + 1] = {'\0'};
    gate gates[] = {{0,1,M_PI/4}, {0,2,M_PI/4}, {1,2,M_PI/4}};
    int numGates = sizeof(gates)/sizeof(gate);

    initialize(nodes);
    generateState(nodes, state);
    printf("Initial state: %s\n", state);

    for(int i=0; i<numGates; i++) {
        switch(gates[i].control) {
            case 0:
                switch(gates[i].target) {
                    case 1:
                        hadamard(nodes, 0);
                        phaseShift(nodes, 1, gates[i].theta);
                        hadamard(nodes, 0);
                        break;
                    case 2:
                        hadamard(nodes, 0);
                        cnot(nodes, 0, 1);
                        phaseShift(nodes, 2, gates[i].theta);
                        cnot(nodes, 0, 1);
                        hadamard(nodes, 0);
                        break;
                }
                break;
            case 1:
                switch(gates[i].target) {
                    case 2:
                        cnot(nodes, 1, 2);
                        phaseShift(nodes, 2, gates[i].theta);
                        cnot(nodes, 1, 2);
                        break;
                }
                break;
        }
        generateState(nodes, state);
        printf("State after gate %d: %s\n", i+1, state);
    }

    return 0;
}