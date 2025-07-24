//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 20

// Node structure
typedef struct node {
    char name;
    float value;
}Node;

Node nodes[MAX_NODES];

int num_nodes = 0;

// Function to add a node to the circuit
void add_node(char name, float value) {
    if(num_nodes < MAX_NODES) {
        nodes[num_nodes].name = name;
        nodes[num_nodes].value = value;
        num_nodes++;
    }
    else {
        printf("Error: Maximum number of nodes reached\n");
    }
}

// Function to simulate the circuit
void simulate_circuit() {
    // TODO: Code to simulate circuit goes here
}

int main() {
    printf("Adding nodes to circuit...\n");
    add_node('A', 5.0);
    add_node('B', 10.0);
    add_node('C', 2.5);
    add_node('D', 7.8);

    printf("Simulating circuit...\n");
    simulate_circuit();

    return 0;
}