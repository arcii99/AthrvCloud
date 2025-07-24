//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

// Structure to represent an edge of the network
struct Edge {
  int source, target;
  double weight;
};

// Structure to represent a node of the network
struct Node {
  int id;
  char name[50];
  int num_edges;
  struct Edge edges[MAX_EDGES];
};

// Structure to represent the network
struct Network {
  int num_nodes;
  struct Node nodes[MAX_NODES];
};

// Function to add an edge to a node
void add_edge(struct Node* node, int target, double weight) {
  int num_edges = node->num_edges;
  if (num_edges == MAX_EDGES) {
    printf("Error: node has maximum number of edges already\n");
    return;
  }
  node->edges[num_edges].source = node->id;
  node->edges[num_edges].target = target;
  node->edges[num_edges].weight = weight;
  node->num_edges++;
}

// Function to add a node to the network
void add_node(struct Network* network, char* name) {
  int num_nodes = network->num_nodes;
  if (num_nodes == MAX_NODES) {
    printf("Error: network has maximum number of nodes already\n");
    return;
  }
  network->nodes[num_nodes].id = num_nodes;
  strncpy(network->nodes[num_nodes].name, name, 50);
  network->nodes[num_nodes].num_edges = 0;
  network->num_nodes++;
}

// Function to print the network
void print_network(struct Network* network) {
  printf("Network:\n");
  for (int i = 0; i < network->num_nodes; i++) {
    printf("Node %d (%s):\n", network->nodes[i].id, network->nodes[i].name);
    for (int j = 0; j < network->nodes[i].num_edges; j++) {
      printf("  %s --(%f)--> %s\n", network->nodes[i].name, network->nodes[i].edges[j].weight, network->nodes[network->nodes[i].edges[j].target].name);
    }
  }
}

int main() {
  struct Network network;
  network.num_nodes = 0;

  // Add some nodes to the network
  add_node(&network, "A");
  add_node(&network, "B");
  add_node(&network, "C");
  add_node(&network, "D");

  // Add some edges to the nodes
  add_edge(&network.nodes[0], 1, 1.0);
  add_edge(&network.nodes[0], 2, 2.0);
  add_edge(&network.nodes[1], 2, 3.0);
  add_edge(&network.nodes[2], 3, 4.0);

  // Print the network
  print_network(&network);

  return 0;
}