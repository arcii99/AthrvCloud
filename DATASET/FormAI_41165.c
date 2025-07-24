//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NODES 50
#define MAX_EDGES 100

// Structure to hold network node information
struct Node {
    char name[20];
    int connections[MAX_NODES];
    int num_connections;
};

// Function to randomly generate network topology
void generate_topology(struct Node nodes[], int num_nodes, int max_edges) {
    srand(time(NULL));
    int num_edges = rand() % max_edges + num_nodes;

    for (int i = 0; i < num_edges; i++) {
        int node1 = rand() % num_nodes;
        int node2 = rand() % num_nodes;
        if (node1 != node2) {
            nodes[node1].connections[nodes[node1].num_connections] = node2;
            nodes[node1].num_connections++;
            nodes[node2].connections[nodes[node2].num_connections] = node1;
            nodes[node2].num_connections++;
        }
    }
}

// Function to print network topology
void print_topology(struct Node nodes[], int num_nodes) {
    printf("   |");
    for (int i = 0; i < num_nodes; i++) {
        printf("%2d|", i);
    }
    printf("\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("%2d |", i);
        for (int j = 0; j < num_nodes; j++) {
            int connected = 0;
            for (int k = 0; k < nodes[i].num_connections; k++) {
                if (nodes[i].connections[k] == j) {
                    connected = 1;
                    break;
                }
            }
            if (connected) {
                printf("O |");
            } else {
                printf("  |");
            }
        }
        printf("\n");
    }
}

int main() {
    struct Node nodes[MAX_NODES];
    int num_nodes = 10;
    int max_edges = 20;
    
    // Initialize nodes
    for (int i = 0; i < num_nodes; i++) {
        sprintf(nodes[i].name, "Node%d", i);
        nodes[i].num_connections = 0;
    }
    
    // Generate random network topology
    generate_topology(nodes, num_nodes, max_edges);
    
    // Print network topology
    printf("--- Cyberpunk Network Topology ---\n");
    print_topology(nodes, num_nodes);
    
    return 0;
}