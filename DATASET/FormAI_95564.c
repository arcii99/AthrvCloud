//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 50

typedef struct node {
    int id;
    int type;
    int input1;
    int input2;
    int output;
} Node;

typedef struct circuit {
    Node nodeList[MAX_NODES];
    int size;
} Circuit;

void addNode(Circuit* circuit, int id, int type, int input1, int input2, int output) {
    Node newNode = {id, type, input1, input2, output};
    circuit->nodeList[circuit->size++] = newNode;
}

void simulate(Circuit* circuit) {
    for (int i = 0; i < circuit->size; i++) {
        Node node = circuit->nodeList[i];
        switch(node.type) {
            case 1: // AND gate
                circuit->nodeList[node.output].input1 = circuit->nodeList[node.input1].output;
                circuit->nodeList[node.output].input2 = circuit->nodeList[node.input2].output;
                circuit->nodeList[node.output].output = circuit->nodeList[node.input1].output && circuit->nodeList[node.input2].output;
                break;
            case 2: // OR gate
                circuit->nodeList[node.output].input1 = circuit->nodeList[node.input1].output;
                circuit->nodeList[node.output].input2 = circuit->nodeList[node.input2].output;
                circuit->nodeList[node.output].output = circuit->nodeList[node.input1].output || circuit->nodeList[node.input2].output;
                break;
            case 3: // NOT gate
                circuit->nodeList[node.output].input1 = circuit->nodeList[node.input1].output;
                circuit->nodeList[node.output].output = !circuit->nodeList[node.input1].output;
                break;
            case 4: // Input node
                // Do nothing as inputs are given during circuit setup
                break;
            default:
                printf("Invalid node type %d\n", node.type);
                exit(-1);
        }
    }
}

void printResults(Circuit* circuit) {
    printf("Circuit simulation results:\n");
    for (int i = 0; i < circuit->size; i++) {
        Node node = circuit->nodeList[i];
        printf("Node id: %d\tInput1: %d\tInput2: %d\tOutput: %d\n", node.id, node.input1, node.input2, node.output);
    }
}

int main() {
    // Create the circuit
    Circuit circuit;
    circuit.size = 0;

    // Add input nodes
    addNode(&circuit, 0, 4, -1, -1, 0); // input 1
    addNode(&circuit, 1, 4, -1, -1, 0); // input 2

    // Add gates
    addNode(&circuit, 2, 1, 0, 1, 3); // AND gate
    addNode(&circuit, 3, 2, 0, 1, 4); // OR gate
    addNode(&circuit, 4, 3, 3, -1, 5); // NOT gate

    // Run simulation
    simulate(&circuit);

    // Print results
    printResults(&circuit);

    return 0;
}