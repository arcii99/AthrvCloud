//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000

typedef struct {
    int from;
    int to;
} edge_t;

typedef struct {
    int node_count;
    int edge_count;
    int adj_matrix[MAX_NODES][MAX_NODES];
    edge_t edges[MAX_EDGES];
} topology_t;

void init_topology(topology_t* topology) {
    topology->node_count = 0;
    topology->edge_count = 0;
    memset(topology->adj_matrix, 0, sizeof(topology->adj_matrix));
    memset(topology->edges, 0, sizeof(topology->edges));
}

void add_node(topology_t* topology) {
    if (topology->node_count >= MAX_NODES) {
        fprintf(stderr, "error: maximum node count reached\n");
        exit(EXIT_FAILURE);
    }
    topology->node_count++;
}

void add_edge(topology_t* topology, int from, int to) {
    if (topology->edge_count >= MAX_EDGES) {
        fprintf(stderr, "error: maximum edge count reached\n");
        exit(EXIT_FAILURE);
    }
    if (from < 0 || from >= topology->node_count || to < 0 || to >= topology->node_count) {
        fprintf(stderr, "error: invalid edge\n");
        exit(EXIT_FAILURE);
    }
    topology->edges[topology->edge_count].from = from;
    topology->edges[topology->edge_count].to = to;
    topology->adj_matrix[from][to] = 1;
    topology->adj_matrix[to][from] = 1;
    topology->edge_count++;
}

void find_path(topology_t* topology, int from, int to, int* visited, int* path, int* count) {
    visited[from] = 1;
    path[(*count)++] = from;
    if (from == to) {
        printf("path: ");
        for (int i = 0; i < *count; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
    } else {
        for (int i = 0; i < topology->node_count; i++) {
            if (topology->adj_matrix[from][i] == 1 && visited[i] == 0) {
                find_path(topology, i, to, visited, path, count);
            }
        }
    }
    (*count)--;
    visited[from] = 0;
}

int main() {
    topology_t topology;
    init_topology(&topology);
    add_node(&topology);
    add_node(&topology);
    add_node(&topology);
    add_node(&topology);
    add_edge(&topology, 0, 1);
    add_edge(&topology, 0, 2);
    add_edge(&topology, 1, 3);
    add_edge(&topology, 2, 3);
    int visited[MAX_NODES] = {0};
    int path[MAX_NODES] = {0};
    int count = 0;
    find_path(&topology, 0, 3, visited, path, &count);
    return 0;
}