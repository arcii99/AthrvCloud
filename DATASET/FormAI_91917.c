//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 10 // Maximum number of nodes in the network topology diagram
#define MAX_NEIGHBORS 5 // Maximum number of neighbors per node

struct Node {
    int id;
    char name[30];
    int neighbors[MAX_NEIGHBORS];
    int num_neighbors;
};

struct Network {
    struct Node nodes[MAX_NODES];
    int num_nodes;
};

void add_node(struct Network* net, int id, char name[]) {
    if (net->num_nodes >= MAX_NODES) {
        printf("Maximum number of nodes reached. Cannot add more nodes.\n");
        return;
    }
    struct Node* node = &(net->nodes[net->num_nodes]);
    node->id = id;
    strcpy(node->name, name);
    node->num_neighbors = 0;
    net->num_nodes++;
}

void add_edge(struct Network* net, int node1_id, int node2_id) {
    struct Node* node1 = NULL;
    struct Node* node2 = NULL;
    int i;
    for (i = 0; i < net->num_nodes; i++) {
        if (net->nodes[i].id == node1_id) {
            node1 = &(net->nodes[i]);
        }
        if (net->nodes[i].id == node2_id) {
            node2 = &(net->nodes[i]);
        }
    }
    if (node1 == NULL || node2 == NULL) {
        printf("One of the nodes does not exist.\n");
        return;
    }
    if (node1->num_neighbors >= MAX_NEIGHBORS || node2->num_neighbors >= MAX_NEIGHBORS) {
        printf("Maximum number of neighbors reached for one of the nodes. Cannot add more edges.\n");
        return;
    }
    node1->neighbors[node1->num_neighbors] = node2_id;
    node1->num_neighbors++;
    node2->neighbors[node2->num_neighbors] = node1_id;
    node2->num_neighbors++;
}

void print_network(struct Network* net) {
    int i, j;
    printf("Network Topology Diagram\n");
    for (i = 0; i < net->num_nodes; i++) {
        struct Node node = net->nodes[i];
        printf("Node %d: %s\n", node.id, node.name);
        printf("Neighbors:");
        for (j = 0; j < node.num_neighbors; j++) {
            printf(" %d", node.neighbors[j]);
        }
        printf("\n");
    }
}

int main() {
    struct Network my_network;
    my_network.num_nodes = 0;

    add_node(&my_network, 1, "Node 1");
    add_node(&my_network, 2, "Node 2");
    add_node(&my_network, 3, "Node 3");
    add_node(&my_network, 4, "Node 4");

    add_edge(&my_network, 1, 2);
    add_edge(&my_network, 2, 3);
    add_edge(&my_network, 3, 4);
    add_edge(&my_network, 1, 4);

    print_network(&my_network);

    return 0;
}