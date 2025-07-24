//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NODES 10

struct node {
    int id;
    int num_neighbors;
    int neighbors[MAX_NODES];
};

void map_topology(struct node nodes[], int num_nodes);
bool is_neighbor(struct node current_node, int node_id);

int main()
{
    int num_nodes, i, j;
    struct node nodes[MAX_NODES];

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    // Initialize the nodes
    for (i = 0; i < num_nodes; i++) {
        nodes[i].id = i + 1;
        nodes[i].num_neighbors = 0;
    }

    // Get the neighbor information for each node
    for (i = 0; i < num_nodes; i++) {
        printf("Enter the neighbors for node %d (-1 to stop):\n", i + 1);
        j = 0;
        while (true) {
            int neighbor_id;
            scanf("%d", &neighbor_id);
            if (neighbor_id == -1) {
                break;
            }
            if (is_neighbor(nodes[i], neighbor_id)) {
                printf("Node %d is already a neighbor of node %d.\n", neighbor_id, i + 1);
            } else {
                nodes[i].neighbors[j] = neighbor_id;
                nodes[i].num_neighbors++;
                j++;
            }
        }
    }

    // Map the topology
    map_topology(nodes, num_nodes);

    return 0;
}

void map_topology(struct node nodes[], int num_nodes)
{
    int i, j;
    bool is_mapped[num_nodes][num_nodes];

    // Initialize the is_mapped array
    for (i = 0; i < num_nodes; i++) {
        for (j = 0; j < num_nodes; j++) {
            is_mapped[i][j] = false;
        }
    }

    // Map the topology
    for (i = 0; i < num_nodes; i++) {
        printf("Node %d has neighbors: ", nodes[i].id);
        for (j = 0; j < nodes[i].num_neighbors; j++) {
            int neighbor_id = nodes[i].neighbors[j];
            if (!is_mapped[i][neighbor_id - 1]) {
                printf("%d ", neighbor_id);
                is_mapped[i][neighbor_id - 1] = true;
                is_mapped[neighbor_id - 1][i] = true;
            }
        }
        printf("\n");
    }
}

bool is_neighbor(struct node current_node, int node_id)
{
    int i;
    for (i = 0; i < current_node.num_neighbors; i++) {
        if (current_node.neighbors[i] == node_id) {
            return true;
        }
    }
    return false;
}