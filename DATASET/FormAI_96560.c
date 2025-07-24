//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Donald Knuth
// C Network Topology Mapper - Donald Knuth Style

#include <stdio.h>

// Define the maximum supported network size
#define MAX_NETWORK_SIZE 100

// Define the maximum number of links that can be supported between nodes
#define MAX_LINKS_PER_NODE 10

// Define a structure to represent a node in the network
struct Node {
    int id; // The unique identifier of the node
    int links[MAX_LINKS_PER_NODE]; // The identifiers of the nodes that are directly connected to this node
    int num_links; // The number of directly connected nodes
};

// Define a structure to represent the network as a whole
struct Network {
    struct Node nodes[MAX_NETWORK_SIZE]; // The nodes that make up the network
    int num_nodes; // The number of nodes in the network
};

// Initialize a network with a given number of nodes and randomly assign links between them
void initialize_network(struct Network *network, int num_nodes) {
    // Initialize the network with the given number of nodes
    network->num_nodes = num_nodes;
    for (int i = 0; i < num_nodes; i++) {
        network->nodes[i].id = i;
        network->nodes[i].num_links = 0;
    }

    // Randomly assign links between the nodes
    for (int i = 0; i < num_nodes; i++) {
        for (int j = i + 1; j < num_nodes; j++) {
            if (rand() % 2 == 0) {
                network->nodes[i].links[network->nodes[i].num_links++] = j;
                network->nodes[j].links[network->nodes[j].num_links++] = i;
            }
        }
    }
}

// Print the topology of a network
void print_topology(struct Network *network) {
    printf("Network Topology:\n");
    for (int i = 0; i < network->num_nodes; i++) {
        printf("Node %d: ", network->nodes[i].id);
        for (int j = 0; j < network->nodes[i].num_links; j++) {
            printf("%d ", network->nodes[i].links[j]);
        }
        printf("\n");
    }
}

int main() {
    // Set the random seed so that the network is initialized randomly each time the program is run
    srand(time(NULL));

    // Initialize a network with 10 nodes
    struct Network network;
    initialize_network(&network, 10);

    // Print the topology of the network
    print_topology(&network);

    return 0;
}