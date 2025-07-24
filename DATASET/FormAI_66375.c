//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NODES 100 // Maximum number of nodes in the network
#define INFINITY 9999 // Representation of infinity distance


/* STRUCTS */

// Struct for a router node
typedef struct router_node {
    int router_id; // ID of the router
    int num_neighbors; // Number of neighbors of the router
    int neighbor_ids[MAX_NODES]; // IDs of the neighbors of the router
    int distances[MAX_NODES]; // Distances to other nodes from this router
} router_node;

// Struct for a network of routers
typedef struct router_network {
    int num_nodes; // Number of nodes in the network
    router_node nodes[MAX_NODES]; // Array of router nodes in the network
} router_network;


/* FUNCTION DECLARATIONS */

// Function to initialize a router network 
void init_network(router_network*);

// Function to print the topology of the network
void print_topology(router_network*);

// Function to map the topology of the network using the Bellman-Ford algorithm
void map_topology(router_network*);


/* MAIN FUNCTION */

// Main function
int main() {
    // Initialize the router network
    router_network network;
    init_network(&network);
    
    // Map the topology of the network
    map_topology(&network);
    
    // Print the topology of the network
    print_topology(&network);
    
    return 0;
}


/* FUNCTION DEFINITIONS */

// Function to initialize a router network 
void init_network(router_network* network) {
    int i, j;
    
    // Set the number of nodes in the network
    network->num_nodes = 4;
    
    // Set the properties of each router node
    network->nodes[0].router_id = 0;
    network->nodes[0].num_neighbors = 2;
    network->nodes[0].neighbor_ids[0] = 1;
    network->nodes[0].neighbor_ids[1] = 2;
    network->nodes[0].distances[0] = 0;
    network->nodes[0].distances[1] = 10;
    network->nodes[0].distances[2] = 3;
    
    network->nodes[1].router_id = 1;
    network->nodes[1].num_neighbors = 2;
    network->nodes[1].neighbor_ids[0] = 0;
    network->nodes[1].neighbor_ids[1] = 3;
    network->nodes[1].distances[0] = 10;
    network->nodes[1].distances[1] = 0;
    network->nodes[1].distances[3] = 5;
    
    network->nodes[2].router_id = 2;
    network->nodes[2].num_neighbors = 2;
    network->nodes[2].neighbor_ids[0] = 0;
    network->nodes[2].neighbor_ids[1] = 3;
    network->nodes[2].distances[0] = 3;
    network->nodes[2].distances[2] = 0;
    network->nodes[2].distances[3] = 7;
    
    network->nodes[3].router_id = 3;
    network->nodes[3].num_neighbors = 2;
    network->nodes[3].neighbor_ids[0] = 1;
    network->nodes[3].neighbor_ids[1] = 2;
    network->nodes[3].distances[1] = 5;
    network->nodes[3].distances[2] = 7;
    network->nodes[3].distances[3] = 0;
    
    // Set all other distances to infinity
    for(i=0; i<network->num_nodes; i++) {
        for(j=0; j<network->num_nodes; j++) {
            if(i != j && network->nodes[i].distances[j] == 0) {
                network->nodes[i].distances[j] = INFINITY;
            }
        }
    }
}

// Function to print the topology of the network
void print_topology(router_network* network) {
    int i, j;
    
    printf("\nThe topology of the network:\n\n");
    
    // Iterate over each router node in the network
    for(i=0; i<network->num_nodes; i++) {
        printf("Router %d:\n", network->nodes[i].router_id);
        
        // Print the distances to all other nodes from this router
        printf("Distances:");
        for(j=0; j<network->num_nodes; j++) {
            printf(" <%d,%d>", network->nodes[j].router_id, network->nodes[i].distances[j]);
        }
        printf("\n\n");
    }
}

// Function to map the topology of the network using the Bellman-Ford algorithm
void map_topology(router_network* network) {
    int i, j, k, updated;
    
    // Iterate over each router node in the network, and perform the Bellman-Ford algorithm
    for(k=0; k<network->num_nodes; k++) {
        updated = 0;
        
        // Iterate over each router node in the network again
        for(i=0; i<network->num_nodes; i++) {
            // Iterate over the neighbors of the current router node
            for(j=0; j<network->nodes[i].num_neighbors; j++) {
                int neighbor_id = network->nodes[i].neighbor_ids[j];
                int new_distance = network->nodes[i].distances[k] + network->nodes[neighbor_id].distances[k];
                
                // If the new distance is less than the current distance, update the distance
                if(new_distance < network->nodes[i].distances[neighbor_id]) {
                    network->nodes[i].distances[neighbor_id] = new_distance;
                    updated = 1;
                }
            }
        }
        
        // If no updates were made in this iteration, break out of the loop
        if(!updated) break;
    }
}