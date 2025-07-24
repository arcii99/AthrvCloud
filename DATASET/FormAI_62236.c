//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_GATE_TYPES 3   // maximum types of gates in the circuit
#define MAX_QUBITS 30      // maximum number of qubits in the circuit

// define different gate types
#define GATE_TYPE_NOT 0
#define GATE_TYPE_CNOT 1
#define GATE_TYPE_SWAP 2

// define circuit gate structure
typedef struct {
    int type;
    int target;
    int control;
} CircuitGate;

// declare global variables
CircuitGate circuit[MAX_QUBITS]; // array to store circuit gates
int circuitSize = 0;             // size of the circuit
bool qubits[MAX_QUBITS] = { 0 }; // array to store qubit state (0 or 1)

// function to initialize the circuit with gates
void initCircuit() {
    CircuitGate gate1 = { GATE_TYPE_NOT, 2, 0 };
    CircuitGate gate2 = { GATE_TYPE_CNOT, 1, 0 };
    CircuitGate gate3 = { GATE_TYPE_SWAP, 0, 1 };
    
    circuit[0] = gate1;
    circuit[1] = gate2;
    circuit[2] = gate3;

    circuitSize = 3;
}

// function to apply a single qubit gate
void applySingleGate(int target) {
    qubits[target] = !qubits[target];
}

// function to apply a CNOT gate
void applyCNOTGate(int target, int control) {
    if (qubits[control] == 1) {
        qubits[target] = !qubits[target];
    }
}

// function to apply a SWAP gate
void applySWAPGate(int target, int control) {
    bool temp = qubits[target];
    qubits[target] = qubits[control];
    qubits[control] = temp;
}

// function to apply all gates in the circuit
void applyCircuit() {
    for (int i = 0; i < circuitSize; i++) {
        CircuitGate gate = circuit[i];
        int target = gate.target;
        int control = gate.control;

        switch (gate.type) {
            case GATE_TYPE_NOT:
                applySingleGate(target);
                break;
            case GATE_TYPE_CNOT:
                applyCNOTGate(target, control);
                break;
            case GATE_TYPE_SWAP:
                applySWAPGate(target, control);
                break;
        }
    }
}

// function to print the state of qubits after applying the circuit
void printQubitState() {
    for (int i = 0; i < MAX_QUBITS; i++) {
        printf("Qubit %d: %d\n", i, qubits[i]);
    }
}

// main function
int main() {
    // initialize the circuit
    initCircuit();

    // apply the circuit
    applyCircuit();

    // print the state of qubits
    printQubitState();

    return 0;
}