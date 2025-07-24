//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: peaceful
#include <stdio.h>

// Node for storing values and connections
struct node {
  double value;
  int connections[10];
  int n_connections;
};

// Circuit Simulator function that takes in a node and recursively updates its value
void simulate(struct node *n, struct node *nodes) {
  int i;
  double new_value = 0;

  for (i = 0; i < n->n_connections; i++) {
    // Get the connected node and simulate its value first
    int connected_node_id = n->connections[i];
    simulate(&nodes[connected_node_id], nodes);

    // Add the value of the connected node to the overall value of this node
    new_value += nodes[connected_node_id].value;
  }

  // Update the value of this node
  n->value = new_value;
}

int main() {
  // Create an array of nodes
  struct node nodes[10];

  // Initialize each node with its connections
  nodes[0].connections[0] = 1;
  nodes[0].connections[1] = 2;
  nodes[0].n_connections = 2;

  nodes[1].connections[0] = 3;
  nodes[1].n_connections = 1;

  nodes[2].connections[0] = 3;
  nodes[2].n_connections = 1;

  nodes[3].n_connections = 0;

  // Simulate the circuit starting from the first node
  simulate(&nodes[0], nodes);

  // Print out the final values of each node
  int i;
  for (i = 0; i < 4; i++) {
    printf("Node %d: %f\n", i, nodes[i].value);
  }

  return 0;
}