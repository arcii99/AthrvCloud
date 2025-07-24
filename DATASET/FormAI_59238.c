//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAX_NODES 50    // maximum number of nodes in our network
#define MAX_NEIGHBORS 5 // maximum number of neighbors each node can have

// Node struct for each device
typedef struct Node {
    char* name;                  // Node name
    char* ip_address;            // Node IP address
    int number_of_neighbors;     // How many neighbors does this node have
    struct Node* neighbors[MAX_NEIGHBORS];   // Pointers to each neighbor
} Node;

// Global node array
Node network[MAX_NODES];

// Function declaration
void map_topology();

// Main function
int main() {
    map_topology();    // Generate the network topology map
    return 0;
}

// Function to map the network topology
void map_topology() {
    int node_count = 0;         // Keep track of the number of nodes in the network
    int neighbor_count = 0;     // Keep track of the number of neighbors each node has

    // Read in network data from a text file
    FILE* fp = fopen("network.txt", "r");
    if (fp == NULL) {
        printf("Couldn't open the network file\n");
        return;
    }

    // Start mapping the topology of the network
    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        // Get node's name and ip address
        char* name = strtok(line, " ");
        char* ip_address = strtok(NULL, " ");
        if (name == NULL || ip_address == NULL) {
            break;
        }

        // Create a new node
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->name = strdup(name);
        new_node->ip_address = strdup(ip_address);
        new_node->number_of_neighbors = 0;

        // Add the new node to the network
        network[node_count++] = *new_node;
        
        // Get the number of neighbors for this node
        char* neighbor_count_str = strtok(NULL, " ");
        if (neighbor_count_str != NULL) {
            neighbor_count = atoi(neighbor_count_str);
        } else {
            printf("Invalid input format for node \"%s\"\n", name);
            break;
        }

        // Add each of the node's neighbors to the network
        int i;
        for (i = 0; i < neighbor_count; i++) {
            char* neighbor_name = strtok(NULL, " ");
            if (neighbor_name == NULL) {
                printf("Invalid input format for node \"%s\"\n", name);
                break;
            }

            // Find the neighbor's node in the network list
            Node* neighbor_node = NULL;
            int j;
            for (j = 0; j < node_count; j++) {
                if (strcmp(network[j].name, neighbor_name) == 0) {
                    neighbor_node = &network[j];
                    break;
                }
            }

            // If the neighbor's node doesn't exist, create a new one
            if (neighbor_node == NULL) {
                neighbor_node = (Node*)malloc(sizeof(Node));
                neighbor_node->name = strdup(neighbor_name);
                neighbor_node->ip_address = NULL;
                neighbor_node->number_of_neighbors = 0;
                network[node_count++] = *neighbor_node;
            }

            // Add a neighbor pointer to both nodes
            new_node->neighbors[i] = neighbor_node;
            neighbor_node->neighbors[neighbor_node->number_of_neighbors++] = new_node;
        }
    }

    // Done reading in file!
    fclose(fp);

    // Print out the network topology map
    printf("*** NETWORK TOPOLOGY MAP ***\n");
    printf("------------------------------\n");
    int i;
    for (i = 0; i < node_count; i++) {
        printf("Node: %s (IP: %s)\n", network[i].name, network[i].ip_address);
        printf("Neighbors:\n");
        int j;
        for (j = 0; j < network[i].number_of_neighbors; j++) {
            printf("- %s\n", network[i].neighbors[j]->name);
        }
        printf("------------------------------\n");
    }
}