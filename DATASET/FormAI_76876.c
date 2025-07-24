//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_NODES 100 // Maximum number of circuit nodes
#define MAX_NAME 20 // Maximum character length of a node name

pthread_mutex_t circuit_mutex; // Mutex for accessing shared circuit data

typedef struct {
    char name[MAX_NAME];
    int value;
} Node;

Node circuit[MAX_NODES]; // The circuit represented as an array of nodes
int num_nodes = 0; // Current number of nodes in the circuit

void* simulate(void* args) {
    char* name = (char*) args;
    int index = -1; // Find the index of the node with the given name
    for (int i = 0; i < num_nodes; i++) {
        if (strcmp(circuit[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Node '%s' not found in circuit.\n", name);
        pthread_exit(NULL);
    }
    int input_value = circuit[index].value;
    for (;;) { // Loop forever
        pthread_mutex_lock(&circuit_mutex);
        int output_value = simulate_node(&circuit[index], input_value); // Update the node's value
        input_value = output_value; // Pass the output value to the next node
        pthread_mutex_unlock(&circuit_mutex);
        usleep(1000); // Sleep for 1ms to slow down the simulation
    }
    pthread_exit(NULL);
}

int simulate_node(Node* node, int input_value) {
    if (strcmp(node->name, "AND") == 0) {
        return input_value & node->value;
    } else if (strcmp(node->name, "OR") == 0) {
        return input_value | node->value;
    } else if (strcmp(node->name, "NOT") == 0) {
        return !input_value;
    } else {
        printf("Invalid node type: '%s'\n", node->name);
        exit(EXIT_FAILURE);
    }
}

int main() {
    // Add nodes to the circuit
    Node n1 = {"AND", 1};
    circuit[num_nodes++] = n1;
    Node n2 = {"NOT", 0};
    circuit[num_nodes++] = n2;
    Node n3 = {"OR", 0};
    circuit[num_nodes++] = n3;

    // Create threads to simulate each node
    pthread_t threads[num_nodes];
    char* node_names[num_nodes];
    for (int i = 0; i < num_nodes; i++) {
        node_names[i] = circuit[i].name;
        pthread_create(&threads[i], NULL, simulate, (void*) node_names[i]);
    }

    // Wait for all threads to exit
    for (int i = 0; i < num_nodes; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}