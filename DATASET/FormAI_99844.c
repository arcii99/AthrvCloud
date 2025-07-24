//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100 // maximum number of nodes in the network
#define MAX_NEIGHBORS 10 // maximum number of neighbors for each node

struct Node {
    int id;
    char hostname[20];
    int num_neighbors;
    int neighbors[MAX_NEIGHBORS];
};

int num_nodes;
struct Node nodes[MAX_NODES];

int add_node(int id, char* hostname) {
    if (num_nodes >= MAX_NODES) {
        return -1; // unable to add more nodes
    }
    nodes[num_nodes].id = id;
    strcpy(nodes[num_nodes].hostname, hostname);
    nodes[num_nodes].num_neighbors = 0;
    num_nodes++;
    return 0;
}

int add_neighbor(int node_id, int neighbor_id) {
    if (node_id < 0 || node_id >= num_nodes) {
        return -1; // invalid node id
    }
    if (neighbor_id < 0 || neighbor_id >= num_nodes) {
        return -2; // invalid neighbor id
    }
    if (nodes[node_id].num_neighbors >= MAX_NEIGHBORS) {
        return -3; // too many neighbors for this node
    }
    nodes[node_id].neighbors[nodes[node_id].num_neighbors] = neighbor_id;
    nodes[node_id].num_neighbors++;
    return 0;
}

void print_topology() {
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d (%s):\n", nodes[i].id, nodes[i].hostname);
        for (int j = 0; j < nodes[i].num_neighbors; j++) {
            printf("  -> Node %d (%s)\n", nodes[nodes[i].neighbors[j]].id, nodes[nodes[i].neighbors[j]].hostname);
        }
    }
}

int main() {
    // add nodes
    add_node(0, "node0");
    add_node(1, "node1");
    add_node(2, "node2");
    add_node(3, "node3");

    // add neighbors
    add_neighbor(0, 1);
    add_neighbor(0, 2);
    add_neighbor(1, 0);
    add_neighbor(1, 2);
    add_neighbor(1, 3);
    add_neighbor(2, 0);
    add_neighbor(2, 1);
    add_neighbor(2, 3);
    add_neighbor(3, 1);
    add_neighbor(3, 2);

    // print topology
    print_topology();

    return 0;
}