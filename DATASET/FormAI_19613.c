//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 1000

int adjacency_matrix[MAX_NODES][MAX_NODES];
int num_nodes = 0;
char node_names[MAX_NODES][20];

void initialize_matrix() {
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            adjacency_matrix[i][j] = 0;
        }
    }
}

void add_node(char* node_name) {
    bool node_exists = false;
    for (int i = 0; i < num_nodes; i++) {
        if (strcmp(node_names[i], node_name) == 0) {
            node_exists = true;
            break;
        }
    }
    if (!node_exists) {
        strncpy(node_names[num_nodes], node_name, 20);
        num_nodes++;
    }
}

int get_node_index(char* node_name) {
    for (int i = 0; i < num_nodes; i++) {
        if (strcmp(node_names[i], node_name) == 0) {
            return i;
        }
    }
    return -1;
}

void add_edge(char* node1_name, char* node2_name) {
    int node1_index = get_node_index(node1_name);
    int node2_index = get_node_index(node2_name);
    if (node1_index != -1 && node2_index != -1) {
        adjacency_matrix[node1_index][node2_index] = 1;
        adjacency_matrix[node2_index][node1_index] = 1;
    }
}

void print_topology() {
    printf("Network Topology:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("%s connected to: ", node_names[i]);
        for (int j = 0; j < num_nodes; j++) {
            if (adjacency_matrix[i][j] == 1) {
                printf("%s ", node_names[j]);
            }
        }
        printf("\n");
    }
}

int main() {
    initialize_matrix();
    add_node("Router1");
    add_node("Switch1");
    add_node("Server1");
    add_edge("Router1", "Switch1");
    add_edge("Switch1", "Server1");
    print_topology();
    return 0;
}