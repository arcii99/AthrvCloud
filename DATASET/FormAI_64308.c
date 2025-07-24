//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: relaxed
// Here is an example C program to map a network topology.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100   // Maximum number of nodes in the network topology.

// Structure to represent a node in the network topology.
typedef struct node {
    char name[20];          // Name of the node.
    int num_neighbors;      // Number of neighbors of the node.
    int neighbors[MAX_NODES]; // Indexes of the node's neighbors in the topology[] array.
} node_t;

int num_nodes = 0;  // Number of nodes in the network topology.
node_t topology[MAX_NODES]; // Array to store the nodes in the network topology.

// Function to add a new node to the network topology.
void add_node(char name[])
{
    topology[num_nodes].num_neighbors = 0;
    strcpy(topology[num_nodes].name, name);
    num_nodes++;
}

// Function to add a neighbor to a node in the network topology.
void add_neighbor(int node_index, int neighbor_index)
{
    topology[node_index].neighbors[topology[node_index].num_neighbors++] = neighbor_index;
}

// Function to print the network topology.
void print_topology()
{
    printf("Network Topology:\n");

    for (int i = 0; i < num_nodes; i++) {
        printf("%s: ", topology[i].name);
        for (int j = 0; j < topology[i].num_neighbors; j++) {
            printf("%s ", topology[topology[i].neighbors[j]].name);
        }
        printf("\n");
    }
}

int main()
{
    // Let's add some nodes to the network topology.
    add_node("Router1");
    add_node("Router2");
    add_node("Computer1");
    add_node("Computer2");
    add_node("Printer1");

    // Now let's connect the nodes.
    add_neighbor(0, 1);  // Router1 -> Router2
    add_neighbor(1, 0);  // Router2 -> Router1
    add_neighbor(1, 2);  // Router2 -> Computer1
    add_neighbor(1, 3);  // Router2 -> Computer2
    add_neighbor(2, 1);  // Computer1 -> Router2
    add_neighbor(3, 1);  // Computer2 -> Router2
    add_neighbor(3, 4);  // Computer2 -> Printer1
    add_neighbor(4, 3);  // Printer1 -> Computer2

    // Print the network topology.
    print_topology();

    return 0;
}