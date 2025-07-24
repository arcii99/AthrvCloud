//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int id;
    char name[50];
    int degree;
    struct Node** neighbors;
};

struct Graph {
    int num_nodes;
    struct Node** nodes;
};

void add_edge(struct Graph* g, int id1, int id2) {
    struct Node* n1 = g->nodes[id1];
    struct Node* n2 = g->nodes[id2];

    n1->degree++;
    n1->neighbors = realloc(n1->neighbors, n1->degree * sizeof(struct Node*));
    n1->neighbors[n1->degree - 1] = n2;

    n2->degree++;
    n2->neighbors = realloc(n2->neighbors, n2->degree * sizeof(struct Node*));
    n2->neighbors[n2->degree - 1] = n1;
}

void print_neighbors(struct Node* n) {
    printf("Node %d (%s) is connected to: ", n->id, n->name);
    for (int i = 0; i < n->degree; i++) {
        printf("%s, ", n->neighbors[i]->name);
    }
    printf("\n");
}

void print_graph(struct Graph* g) {
    printf("Graph with %d nodes\n", g->num_nodes);
    for(int i = 0; i < g->num_nodes; i++) {
        print_neighbors(g->nodes[i]);
    }
}

int main() {
    struct Graph* g = malloc(sizeof(struct Graph));
    g->num_nodes = 5;
    g->nodes = malloc(g->num_nodes * sizeof(struct Node*));

    for(int i = 0; i < g->num_nodes; i++) {
        g->nodes[i] = malloc(sizeof(struct Node));
        g->nodes[i]->id = i;
        sprintf(g->nodes[i]->name, "Node %d", i);
        g->nodes[i]->degree = 0;
        g->nodes[i]->neighbors = malloc(0);
    }

    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 3);
    add_edge(g, 2, 4);
    add_edge(g, 3, 4);

    print_graph(g);

    return 0;
}