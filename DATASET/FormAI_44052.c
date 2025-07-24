//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_NODES 20
#define MAX_EDGES 50

typedef struct {
    int src;
    int dest;
} Edge;

typedef struct {
    int node_id;
    int num_edges;
    Edge edges[MAX_EDGES];
} Node;

Node nodes[MAX_NODES];
int num_nodes = 0;
int num_edges = 0;
pthread_mutex_t lock;

void add_edge(int src, int dest) {
    pthread_mutex_lock(&lock);
    if (num_edges < MAX_EDGES) {
        Edge new_edge = {src, dest};
        nodes[src].edges[nodes[src].num_edges] = new_edge;
        nodes[src].num_edges++;
        num_edges++;
    }
    pthread_mutex_unlock(&lock);
}

void add_node(int node_id, int num_edges, Edge edges[]) {
    pthread_mutex_lock(&lock);
    if (num_nodes < MAX_NODES) {
        Node new_node = {node_id, num_edges};
        memcpy(new_node.edges, edges, num_edges * sizeof(Edge));
        nodes[node_id] = new_node;
        num_nodes++;
    }
    pthread_mutex_unlock(&lock);
}

void print_topology() {
    printf("Network Topology:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: ", nodes[i].node_id);
        for (int j = 0; j < nodes[i].num_edges; j++) {
            printf("%d ", nodes[i].edges[j].dest);
        }
        printf("\n");
    }
}

int main() {
    pthread_mutex_init(&lock, NULL);

    Edge edges1[] = {{0, 1}, {0, 2}};
    add_node(0, 2, edges1);
    Edge edges2[] = {{1, 0}, {1, 4}};
    add_node(1, 2, edges2);
    Edge edges3[] = {{2, 0}, {2, 6}};
    add_node(2, 2, edges3);
    Edge edges4[] = {{3, 5}, {3, 8}};
    add_node(3, 2, edges4);
    Edge edges5[] = {{4, 1}, {4, 7}};
    add_node(4, 2, edges5);
    Edge edges6[] = {{5, 3}, {5, 9}};
    add_node(5, 2, edges6);
    Edge edges7[] = {{6, 2}, {6, 10}};
    add_node(6, 2, edges7);
    Edge edges8[] = {{7, 4}, {7, 11}};
    add_node(7, 2, edges8);
    Edge edges9[] = {{8, 3}, {8, 12}};
    add_node(8, 2, edges9);
    Edge edges10[] = {{9, 5}, {9, 13}};
    add_node(9, 2, edges10);
    Edge edges11[] = {{10, 6}, {10, 14}};
    add_node(10, 2, edges11);
    Edge edges12[] = {{11, 7}, {11, 15}};
    add_node(11, 2, edges12);
    Edge edges13[] = {{12, 8}, {12, 16}};
    add_node(12, 2, edges13);
    Edge edges14[] = {{13, 9}, {13, 17}};
    add_node(13, 2, edges14);
    Edge edges15[] = {{14, 10}, {14, 18}};
    add_node(14, 2, edges15);
    Edge edges16[] = {{15, 11}, {15, 19}};
    add_node(15, 2, edges16);

    print_topology();
    pthread_mutex_destroy(&lock);
    return 0;
}