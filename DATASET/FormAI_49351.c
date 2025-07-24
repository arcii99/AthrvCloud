//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_NODES 10
#define MAX_EDGES 15

// Node struct
typedef struct {
    int id;
    int links[MAX_EDGES];   // record of connected nodes
    int num_links;          // number of links
} Node;

// Function declarations
void generate_map(Node* nodes, int num_nodes, int num_edges);
void print_map(Node* nodes, int num_nodes);

// Main function
int main() {
    srand(time(NULL));  // seed random number generator
    
    // Initialize nodes and map
    Node nodes[MAX_NODES];
    int num_nodes = 5;
    int num_edges = 7;

    generate_map(nodes, num_nodes, num_edges);   // randomly generate map
    print_map(nodes, num_nodes);    // print map for debugging
    
    return 0;
}

// Function to randomly generate a network topology map
void generate_map(Node* nodes, int num_nodes, int num_edges) {
    // Initialize nodes
    for (int i = 0; i < num_nodes; i++) {
        nodes[i].id = i;
        nodes[i].num_links = 0;
    }
    
    // Initialize edges
    for (int i = 0; i < num_edges; i++) {
        int node1 = rand() % num_nodes;
        int node2 = rand() % num_nodes;
        
        // Make sure nodes aren't already connected
        for (int j = 0; j < nodes[node1].num_links; j++) {
            if (nodes[node1].links[j] == node2) {
                i--;
                break;
            }
        }
        
        // Add link between nodes
        nodes[node1].links[nodes[node1].num_links] = node2;
        nodes[node1].num_links++;
        nodes[node2].links[nodes[node2].num_links] = node1;
        nodes[node2].num_links++;
    }
}

// Function to print network topology map
void print_map(Node* nodes, int num_nodes) {
    printf("-------- Network Topology Map --------\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("%d -> ", nodes[i].id);
        for (int j = 0; j < nodes[i].num_links; j++) {
            printf("%d ", nodes[i].links[j]);
        }
        printf("\n");
    }
}