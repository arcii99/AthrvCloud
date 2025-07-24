//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: cheerful
// Hello there! Welcome to our Classical Circuit Simulator!
// This program allows you to simulate electrical circuits and see the results in real time.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Defining the maximum number of nodes and components
#define MAX_NODES 20
#define MAX_COMPONENTS 50

// Defining the maximum value of resistors
#define MAX_RESISTOR_VALUE 10000

// Defining the maximum value of voltage and current sources
#define MAX_VOLTAGE_VALUE 1000
#define MAX_CURRENT_VALUE 10

// Defining the value of pi in radians
#define PI 3.14159265359

// Defining the node structure
typedef struct Node {
    int nodeNumber;
    double voltage;
} Node;

// Defining the component structure
typedef struct Component {
    int componentNumber;
    int nodeA;
    int nodeB;
    double value;
    char type;
} Component;

// Defining the array of nodes and components
Node nodes[MAX_NODES];
Component components[MAX_COMPONENTS];

// Defining the number of nodes and components present in the circuit
int numNodes = 0;
int numComponents = 0;

// Function to add a node to the circuit
void addNode() {
    nodes[numNodes].nodeNumber = numNodes;
    nodes[numNodes].voltage = 0;
    numNodes++;
}

// Function to add a component to the circuit
void addComponent(char type, int nodeA, int nodeB, double value) {
    components[numComponents].componentNumber = numComponents;
    components[numComponents].type = type;
    components[numComponents].nodeA = nodeA;
    components[numComponents].nodeB = nodeB;
    components[numComponents].value = value;
    numComponents++;
}

// Function to calculate the voltage of each node
void calculateVoltages() {
    int i, j, k;
    double current, jacobian[MAX_NODES][MAX_NODES], guess[MAX_NODES], error[MAX_NODES], tolerance = 0.0001, maxError, sum;
    for (i = 0; i < numNodes; i++) {
        guess[i] = nodes[i].voltage;
    }
    do {
        for (i = 0; i < numNodes; i++) {
            error[i] = 0;
            for (j = 0; j < numNodes; j++) {
                jacobian[i][j] = 0;
            }
        }
        for (k = 0; k < numComponents; k++) {
            if (components[k].type == 'R') {
                current = (nodes[components[k].nodeA].voltage - nodes[components[k].nodeB].voltage) / components[k].value;
                jacobian[components[k].nodeA][components[k].nodeA] += 1 / components[k].value;
                jacobian[components[k].nodeB][components[k].nodeB] += 1 / components[k].value;
                jacobian[components[k].nodeA][components[k].nodeB] -= 1 / components[k].value;
                jacobian[components[k].nodeB][components[k].nodeA] -= 1 / components[k].value;
                error[components[k].nodeA] -= current;
                error[components[k].nodeB] += current;
            }
            else if (components[k].type == 'V') {
                current = components[k].value;
                jacobian[components[k].nodeA][numNodes] += 1;
                jacobian[components[k].nodeB][numNodes] -= 1;
                error[components[k].nodeA] -= nodes[numNodes].voltage;
                error[components[k].nodeB] += nodes[numNodes].voltage;
            }
            else if (components[k].type == 'I') {
                current = components[k].value;
                error[components[k].nodeA] -= current;
                error[components[k].nodeB] += current;
            }
            else if (components[k].type == 'C') {
                current = (nodes[components[k].nodeA].voltage - nodes[components[k].nodeB].voltage) / (components[k].value * 0.000001);
                jacobian[components[k].nodeA][components[k].nodeA] += 1 * pow(10, -12) / (components[k].value * pow(nodes[components[k].nodeA].voltage - nodes[components[k].nodeB].voltage, 2));
                jacobian[components[k].nodeB][components[k].nodeB] += 1 * pow(10, -12) / (components[k].value * pow(nodes[components[k].nodeA].voltage - nodes[components[k].nodeB].voltage, 2));
                jacobian[components[k].nodeA][components[k].nodeB] -= 1 * pow(10, -12) / (components[k].value * pow(nodes[components[k].nodeA].voltage - nodes[components[k].nodeB].voltage, 2));
                jacobian[components[k].nodeB][components[k].nodeA] -= 1 * pow(10, -12) / (components[k].value * pow(nodes[components[k].nodeA].voltage - nodes[components[k].nodeB].voltage, 2));
                error[components[k].nodeA] -= current;
                error[components[k].nodeB] += current;
            }
            else if (components[k].type == 'L') {
                current = (nodes[components[k].nodeA].voltage - nodes[components[k].nodeB].voltage) * (components[k].value * 0.001) / 0.01;
                jacobian[components[k].nodeA][components[k].nodeA] += 1 * pow(10, 3) / (components[k].value * pow(nodes[components[k].nodeA].voltage - nodes[components[k].nodeB].voltage, 2));
                jacobian[components[k].nodeB][components[k].nodeB] += 1 * pow(10, 3) / (components[k].value * pow(nodes[components[k].nodeA].voltage - nodes[components[k].nodeB].voltage, 2));
                jacobian[components[k].nodeA][components[k].nodeB] -= 1 * pow(10, 3) / (components[k].value * pow(nodes[components[k].nodeA].voltage - nodes[components[k].nodeB].voltage, 2));
                jacobian[components[k].nodeB][components[k].nodeA] -= 1 * pow(10, 3) / (components[k].value * pow(nodes[components[k].nodeA].voltage - nodes[components[k].nodeB].voltage, 2));
                error[components[k].nodeA] -= current;
                error[components[k].nodeB] += current;
            }
            else if (components[k].type == 'S') {
                nodes[components[k].nodeA].voltage = sin(components[k].value * 2 * PI * numNodes * 0.001);
                nodes[components[k].nodeB].voltage = sin(components[k].value * 2 * PI * numNodes * 0.001 - PI);
            }
        }
        for (i = 0; i < numNodes; i++) {
            jacobian[numNodes][i] = 0;
            jacobian[i][numNodes] = 0;
            error[numNodes] = 0;
        }
        jacobian[numNodes][numNodes] = 1;
        maxError = 0;
        for (i = 0; i < numNodes + 1; i++) {
            sum = 0;
            for (j = 0; j < numNodes + 1; j++) {
                sum += jacobian[i][j] * guess[j];
            }
            error[i] = sum - error[i];
            if (fabs(error[i]) > maxError) {
                maxError = fabs(error[i]);
            }
        }
        for (i = 0; i < numNodes; i++) {
            guess[i] -= tolerance * error[i] / jacobian[i][i];
        }
    } while (maxError > tolerance);
    for (i = 0; i < numNodes; i++) {
        nodes[i].voltage = guess[i];
    }
}

int main() {
    printf("Welcome to our Classical Circuit Simulator!\n");
    printf("Adding nodes to the circuit...\n");
    addNode();
    addNode();
    addNode();
    addNode();
    printf("Nodes added successfully!\n");
    printf("Adding components to the circuit...\n");
    addComponent('V', 0, 1, 5);
    addComponent('R', 1, 2, 100);
    addComponent('R', 2, 3, 100);
    addComponent('R', 3, 0, 100);
    printf("Components added successfully!\n");
    printf("Simulating the circuit...\n");
    int i, j;
    for (i = 0; i < 10; i++) {
        calculateVoltages();
        printf("Iteration %d:\n", i + 1);
        for (j = 0; j < numNodes; j++) {
            printf("Node %d voltage: %fV\n", j, nodes[j].voltage);
        }
    }
    printf("Simulation successful!\n");
    return 0;
}