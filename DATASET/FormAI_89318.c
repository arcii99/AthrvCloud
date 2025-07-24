//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 500

struct Node {
    int id;
    int x;
    int y;
};

struct Edge {
    int node1_id;
    int node2_id;
    int distance;
};

struct Network {
    int num_nodes;
    int num_edges;
    struct Node nodes[MAX_NODES];
    struct Edge edges[MAX_EDGES];
};

void generate_random_network(struct Network *network) {
    int i, j;
    int num_nodes = rand() % MAX_NODES + 1;
    network->num_nodes = num_nodes;
    for (i = 0; i < num_nodes; i++) {
        network->nodes[i].id = i;
        network->nodes[i].x = rand() % 1000;
        network->nodes[i].y = rand() % 1000;
    }
    int num_edges = rand() % MAX_EDGES + 1;
    network->num_edges = num_edges;
    for (i = 0; i < num_edges; i++) {
        int node1_id = rand() % num_nodes;
        int node2_id = rand() % num_nodes;
        while (node1_id == node2_id) {
            node2_id = rand() % num_nodes;
        }
        int distance = (int)(sqrt(pow(network->nodes[node1_id].x - network->nodes[node2_id].x, 2) + pow(network->nodes[node1_id].y - network->nodes[node2_id].y, 2)) + 0.5);
        network->edges[i].node1_id = node1_id;
        network->edges[i].node2_id = node2_id;
        network->edges[i].distance = distance;
    }
}

void print_network(struct Network *network) {
    int i;
    printf("Nodes:\n");
    for (i = 0; i < network->num_nodes; i++) {
        printf("Node %d: (%d, %d)\n", network->nodes[i].id, network->nodes[i].x, network->nodes[i].y);
    }
    printf("Edges:\n");
    for (i = 0; i < network->num_edges; i++) {
        int node1_id = network->edges[i].node1_id;
        int node2_id = network->edges[i].node2_id;
        int distance = network->edges[i].distance;
        printf("Edge %d: Node %d -- Node %d, Distance %d\n", i, node1_id, node2_id, distance);
    }
}

int main() {
    srand(time(NULL));
    struct Network network;
    generate_random_network(&network);
    print_network(&network);
    return 0;
}