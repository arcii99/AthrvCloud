//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_EDGES 500

typedef struct {
    int nodes[MAX_NODES];
    int num_nodes;
} network;

typedef struct {
    int start;
    int end;
} edge;

int main() {

    network n = {.num_nodes = 5, .nodes = {1, 2, 3, 4, 5}};

    edge e1 = {.start = 1, .end = 2};
    edge e2 = {.start = 2, .end = 3};
    edge e3 = {.start = 3, .end = 4};
    edge e4 = {.start = 4, .end = 5};
    edge e5 = {.start = 5, .end = 1};

    edge edges[MAX_EDGES] = {e1, e2, e3, e4, e5};

    for (int i = 0; i < n.num_nodes; i++) {
        printf("Node %d is connected to: ", n.nodes[i]);
        for (int j = 0; j < MAX_EDGES; j++) {
            if (edges[j].start == n.nodes[i]) {
                printf("%d ", edges[j].end);
            } else if (edges[j].end == n.nodes[i]) {
                printf("%d ", edges[j].start);
            }
        }
        printf("\n");
    }

    return 0;
}