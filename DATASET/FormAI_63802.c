//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100 // maximum number of nodes in the circuit

// Define a circuit node struct
typedef struct node {
    int index; // the index of the node 
    int value; // the value of the node (0 or 1)
    int input1; // the index of the first input node (if applicable)
    int input2; // the index of the second input node (if applicable)
    int output; // the index of the output node (if applicable)
} Node;

int numNodes; // number of nodes in the circuit
Node circuit[MAX_NODES]; // array that holds the circuit nodes

// Define a function that initializes the circuit with the given inputs and outputs
void initializeCircuit(int numInputs, int numOutputs) {

    numNodes = numInputs + numOutputs;

    // Initialize input nodes
    for (int i = 0; i < numInputs; i++) {
        circuit[i].index = i;
        circuit[i].value = 0; // input nodes are initially set to 0
    }

    // Initialize output nodes
    for (int i = numInputs; i < numNodes; i++) {
        circuit[i].index = i;
        circuit[i].value = -1; // output nodes are initially unknown
    }
}

// Define a function that sets the value of a given node
void setNodeValue(Node* node, int value) {

    node->value = value;
    
    // If this node is an input node, print a message to indicate the new value
    if (node->input1 == -1 && node->input2 == -1) {
        printf("Input Node %d changed to %d\n", node->index, node->value);
    }
}

// Define a function that evaluates the value of a given node based on its inputs
int getOutputValue(Node* node) {

    if (node->input1 != -1 && circuit[node->input1].value == -1) {
        return -1; // if the first input is unknown, return -1
    }

    if (node->input2 != -1 && circuit[node->input2].value == -1) {
        return -1; // if the second input is unknown, return -1
    }

    // evaluate the output based on the inputs and the node type
    switch(node->value) {

        case 0: // AND gate
            if (circuit[node->input1].value == 0 && circuit[node->input2].value == 0) {
                return 0;
            } else {
                return 1;
            }

        case 1: // OR gate
            if (circuit[node->input1].value == 1 || circuit[node->input2].value == 1) {
                return 1;
            } else {
                return 0;
            }

        case 2: // NOT gate
            if (circuit[node->input1].value == 0) {
                return 1;
            } else {
                return 0;
            }

        default: // unknown node type
            return -1;
    }
}

// Define a function that evaluates the output values for all output nodes in the circuit
void evaluateOutputs() {

    // Iterate over all output nodes in the circuit
    for (int i = numNodes - 1; i >= numNodes - 3; i--) {

        Node* node = &circuit[i];

        // If the output is already known, skip to the next output node
        if (node->value != -1) {
            continue;
        }

        // Evaluate the output value and set the node's value accordingly
        int outputValue = getOutputValue(node);
        setNodeValue(node, outputValue);

        // If the output node value changed, print a message to indicate the new value
        if (outputValue != -1) {
            printf("Output Node %d changed to %d\n", node->index, outputValue);
        }
    }
}

int main() {

    // Initialize the circuit with 2 inputs and 3 outputs
    initializeCircuit(2, 3);

    // Set the inputs to a given value
    setNodeValue(&circuit[0], 0);
    setNodeValue(&circuit[1], 1);

    // Evaluate the circuit and print the results
    evaluateOutputs();

    // Set a different input value and re-evaluate the circuit
    setNodeValue(&circuit[0], 1);
    evaluateOutputs();

    return 0;
}