//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of nodes in the network
#define MAX_NODES 10

// Define the maximum number of connections for each node
#define MAX_CONNECTIONS 5

// Define the structure for each node in the network
typedef struct Node {
    int id;                     // Unique id for this node
    char name[20];              // Name of the node
    char connections[MAX_CONNECTIONS][20]; // Names of nodes that are connected to this node
    int num_connections;        // Number of nodes connected to this node
} Node;

// Define an array of nodes to represent the network
Node network[MAX_NODES];

// Function to add a new node to the network
void addNode(int id, char* name) {
    // Check if we have already reached the maximum number of nodes
    if (id >= MAX_NODES) {
        printf("Unable to add node: maximum number of nodes reached.\n");
        return;
    }

    // Initialize the node's id and name
    network[id].id = id;
    strcpy(network[id].name, name);

    // Initialize the number of connections to 0
    network[id].num_connections = 0;
}

// Function to add a connection between two nodes
void addConnection(int node1, int node2) {
    // Check if either of the nodes are invalid
    if (node1 < 0 || node1 >= MAX_NODES || node2 < 0 || node2 >= MAX_NODES) {
        printf("Unable to add connection: invalid nodes.\n");
        return;
    }

    // Check if either of the nodes are already at maximum connection capacity
    if (network[node1].num_connections >= MAX_CONNECTIONS || network[node2].num_connections >= MAX_CONNECTIONS) {
        printf("Unable to add connection: maximum number of connections reached.\n");
        return;
    }

    // Add the connection from node1 to node2
    strcpy(network[node1].connections[network[node1].num_connections], network[node2].name);
    network[node1].num_connections++;

    // Add the connection from node2 to node1
    strcpy(network[node2].connections[network[node2].num_connections], network[node1].name);
    network[node2].num_connections++;
}

// Function to display the network topology
void displayTopology() {
    int i, j;

    printf("Network Topology:\n");
    printf("------------------\n");

    // Iterate through each node in the network
    for (i = 0; i < MAX_NODES; i++) {
        // Check if the node is valid (i.e. has been added to the network)
        if (strlen(network[i].name) > 0) {
            printf("%d: %s\n", network[i].id, network[i].name);
            printf("  Connected to:");

            // Iterate through each connected node
            for (j = 0; j < network[i].num_connections; j++) {
                printf(" %s", network[i].connections[j]);
            }

            printf("\n\n");
        }
    }
}

// Main function
int main() {
    // Add some nodes to the network
    addNode(0, "Node 0");
    addNode(1, "Node 1");
    addNode(2, "Node 2");
    addNode(3, "Node 3");

    // Add some connections between the nodes
    addConnection(0, 1);
    addConnection(1, 2);
    addConnection(2, 3);
    addConnection(3, 0);

    // Display the network topology
    displayTopology();

    return 0;
}