//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

#define SIZE 100

// A simple class to represent a resistor.
typedef struct Resistor {
    double resistance;
    double voltage;
    double current;
} Resistor;

// A simple class to represent a voltage source.
typedef struct VoltageSource {
    double voltage;
} VoltageSource;

// A class to represent a node in a circuit.
typedef struct Node {
    int nodeNumber;
    enum {RESISTOR, VOLTAGE_SOURCE} nodeType;
    union {
        Resistor resistor;
        VoltageSource voltageSource;
    } component;
    struct Node *next;
} Node;

// A class to represent a circuit.
typedef struct Circuit {
    int numNodes;
    Node *head;
    double complex **A;
    double complex *b;
} Circuit;

// Function to create a new node with a resistor component.
Node *newResistorNode(int nodeNumber, double resistance) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->nodeNumber = nodeNumber;
    node->nodeType = RESISTOR;
    node->component.resistor.resistance = resistance;
    node->component.resistor.voltage = 0.0;
    node->component.resistor.current = 0.0;
    node->next = NULL;
    return node;
}

// Function to create a new node with a voltage source component.
Node *newVoltageNode(int nodeNumber, double voltage) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->nodeNumber = nodeNumber;
    node->nodeType = VOLTAGE_SOURCE;
    node->component.voltageSource.voltage = voltage;
    node->next = NULL;
    return node;
}

// Function to add a node to a circuit.
void addNode(Circuit *circuit, Node *node) {
    if (circuit->head == NULL) {
        circuit->head = node;
    } else {
        Node *current = circuit->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
    circuit->numNodes++;
}

// Function to find a node in a circuit by node number.
Node *findNode(Circuit *circuit, int nodeNumber) {
    Node *current = circuit->head;
    while (current != NULL) {
        if (current->nodeNumber == nodeNumber) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to free memory allocated by a circuit.
void cleanup(Circuit *circuit) {
    Node *current = circuit->head;
    Node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    for (int i = 0; i < circuit->numNodes; i++) {
        free(circuit->A[i]);
    }
    free(circuit->A);
    free(circuit->b);
    free(circuit);
}

// Function to print the result of a circuit simulation.
void printResult(Circuit *circuit) {
    Node *current = circuit->head;
    while (current != NULL) {
        printf("Node %d: ", current->nodeNumber);
        if (current->nodeType == RESISTOR) {
            printf("Resistor with resistance %f ohms, voltage difference of %f volts, and current of %f amps.\n", current->component.resistor.resistance, current->component.resistor.voltage, current->component.resistor.current);
        } else {
            printf("Voltage source with voltage of %f volts.\n", current->component.voltageSource.voltage);
        }
        current = current->next;
    }
}

int main() {
    // Create a new circuit.
    Circuit *circuit = (Circuit *) malloc(sizeof(Circuit));
    circuit->numNodes = 0;
    circuit->head = NULL;
    circuit->A = (double complex **) malloc(SIZE * sizeof(double complex *));
    for (int i = 0; i < SIZE; i++) {
        circuit->A[i] = (double complex *) calloc(SIZE, sizeof(double complex));
    }
    circuit->b = (double complex *) calloc(SIZE, sizeof(double complex));
    
    // Add nodes to the circuit.
    Node *node1 = newVoltageNode(1, 5.0);
    Node *node2 = newResistorNode(2, 10.0);
    Node *node3 = newResistorNode(3, 20.0);
    addNode(circuit, node1);
    addNode(circuit, node2);
    addNode(circuit, node3);
    
    // Find nodes by node number.
    Node *nodeA = findNode(circuit, 1);
    Node *nodeB = findNode(circuit, 2);
    Node *nodeC = findNode(circuit, 3);
    
    // Set up circuit equations.
    circuit->A[0][0] = 1.0;
    circuit->A[1][0] = -1.0;
    circuit->A[0][1] = -1.0;
    circuit->A[1][1] = 1.0 + (nodeB->component.resistor.resistance / nodeC->component.resistor.resistance);
    circuit->A[1][2] = -(nodeB->component.resistor.resistance / nodeC->component.resistor.resistance);
    circuit->A[2][1] = (nodeB->component.resistor.resistance / nodeC->component.resistor.resistance);
    circuit->A[2][2] = 1.0 + (nodeB->component.resistor.resistance / nodeA->component.voltageSource.voltage);
    circuit->b[0] = nodeA->component.voltageSource.voltage;
    circuit->b[1] = 0.0;
    circuit->b[2] = 0.0;
    
    // Solve circuit equations.
    for (int k = 0; k < SIZE-1; k++) {
        for (int i = k+1; i < SIZE; i++) {
            double complex factor = circuit->A[i][k] / circuit->A[k][k];
            for (int j = k+1; j < SIZE; j++) {
                circuit->A[i][j] -= factor * circuit->A[k][j];
            }
            circuit->b[i] -= factor * circuit->b[k];
        }
    }
    for (int k = SIZE-1; k >= 0; k--) {
        circuit->b[k] /= circuit->A[k][k];
        for (int i = k-1; i >= 0; i--) {
            circuit->b[i] -= circuit->A[i][k] * circuit->b[k];
        }
    }
    
    // Set node voltages and currents.
    nodeA->component.voltageSource.voltage = circuit->b[0];
    nodeB->component.resistor.voltage = circuit->b[1];
    nodeC->component.resistor.voltage = circuit->b[2];
    nodeB->component.resistor.current = nodeB->component.resistor.voltage / nodeB->component.resistor.resistance;
    nodeC->component.resistor.current = nodeC->component.resistor.voltage / nodeC->component.resistor.resistance;
    
    // Print result.
    printResult(circuit);
    
    // Clean up memory.
    cleanup(circuit);
    
    return 0;
}