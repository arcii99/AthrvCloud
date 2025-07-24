//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 50

struct Component {
    char name[10];
    double value;
    int fromNode, toNode;
};

struct Node {
    int num, visited;
};

int numNodes = 0;
int numComponents = 0;
struct Component components[MAX_NODES];
struct Node nodes[MAX_NODES];

void simulateCircuit(double values[]) {
    double nodeVoltages[MAX_NODES] = {0.0};
    for(int i = 0; i < numComponents; i++) {
        switch(components[i].name[0]) {
            case 'R': {
                double resistance = components[i].value;
                int fromNode = components[i].fromNode;
                int toNode = components[i].toNode;
                nodeVoltages[fromNode] += (values[fromNode] - values[toNode]) / resistance;
                nodeVoltages[toNode] += (values[toNode] - values[fromNode]) / resistance;
                break;
            }
            case 'V': {
                double voltage = components[i].value;
                int fromNode = components[i].fromNode;
                int toNode = components[i].toNode;
                nodeVoltages[fromNode] += voltage;
                nodeVoltages[toNode] -= voltage;
                break;
            }
            case 'I': {
                double current = components[i].value;
                int fromNode = components[i].fromNode;
                int toNode = components[i].toNode;
                nodeVoltages[fromNode] -= current;
                nodeVoltages[toNode] += current;
                break;
            }
            default: {
                printf("Error: Invalid component name %s\n", components[i].name);
                return;
            }
        }
    }
    for(int i = 1; i <= numNodes; i++) {
        printf("Node %d voltage: %lf\n", i, nodeVoltages[i]);
    }
}

int main() {
    // Initialize nodes
    for(int i = 0; i < MAX_NODES; i++) {
        nodes[i].num = i;
        nodes[i].visited = 0;
    }

    // Add components to circuit
    components[0].name[0] = 'R';
    components[0].value = 1000.0;
    components[0].fromNode = 1;
    components[0].toNode = 2;
    numComponents++;

    components[1].name[0] = 'V';
    components[1].value = 5.0;
    components[1].fromNode = 2;
    components[1].toNode = 0;
    numComponents++;

    components[2].name[0] = 'I';
    components[2].value = 0.001;
    components[2].fromNode = 0;
    components[2].toNode = 1;
    numComponents++;

    // Calculate number of nodes
    for(int i = 0; i < numComponents; i++) {
        if(components[i].fromNode > numNodes) {
            numNodes = components[i].fromNode;
        }
        if(components[i].toNode > numNodes) {
            numNodes = components[i].toNode;
        }
    }

    // Simulate circuit for different input values
    double values[] = {0.0, 0.0, 0.0};
    simulateCircuit(values);

    values[0] = 10.0;
    simulateCircuit(values);

    values[1] = 12.0;
    simulateCircuit(values);

    return 0;
}