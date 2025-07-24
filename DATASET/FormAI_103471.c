//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 1000
#define MAX_EDGES 2000

int nodes_count, edges_count, source_node;
int edges[MAX_EDGES][3], distance[MAX_NODES];

void Bellman_Ford() {
    for (int i = 1; i <= nodes_count; i++) {
        distance[i] = 999999;
    }
    distance[source_node] = 0;

    for (int i = 1; i < nodes_count; i++) {
        for (int j = 0; j < edges_count; j++) {
            int u = edges[j][0], v = edges[j][1], w = edges[j][2];
            if (distance[u] != 999999 && distance[v] > distance[u] + w) {
                distance[v] = distance[u] + w;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    nodes_count = rand()%MAX_NODES + 1;
    edges_count = nodes_count*(nodes_count - 1)/2;
    source_node = rand()%nodes_count + 1;
    printf("Number of Nodes: %d, Number of Edges: %d, Source Node: %d\n", nodes_count, edges_count, source_node);

    for (int i = 0; i < edges_count; i++) {
        int u, v, w;
        do {
            u = rand()%nodes_count + 1;
            v = rand()%nodes_count + 1;
        } while (u == v);

        if (u > v) {
            int temp = u;
            u = v;
            v = temp;
        }

        w = rand()%500 - 250;
        edges[i][0] = u;
        edges[i][1] = v;
        edges[i][2] = w;
    }

    Bellman_Ford();

    printf("Distances from the Source Node:\n");
    for (int i = 1; i <= nodes_count; i++) {
        printf("%d -> %d: %d\n", source_node, i, distance[i]);
    }

    return 0;
}