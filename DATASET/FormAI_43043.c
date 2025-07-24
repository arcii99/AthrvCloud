//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 100

struct node {
    int id;
    char name[20];
    struct node *next;
};

struct edges {
    int u, v;
    double weight;
};

struct graph {
    int nodes;
    int edges;
    struct node *adj_list[MAX_NODES];
};

void init_graph(struct graph *g) {
    g->nodes = 0;
    g->edges = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        g->adj_list[i] = NULL;
    }
}

void add_node(struct graph *g, int id, char name[]) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->id = id;
    strcpy(new_node->name, name);
    new_node->next = NULL;
    g->adj_list[id] = new_node;
    g->nodes++;
}

void add_edge(struct graph *g, int u, int v, double weight) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->id = v;
    new_node->next = g->adj_list[u];
    g->adj_list[u] = new_node;
    g->edges++;
}

void read_input(struct graph *g) {
    int m, u, v, id;
    double weight;
    char name[20];
    printf("Enter the number of nodes: ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        printf("Enter node id: ");
        scanf("%d", &id);
        printf("Enter node name: ");
        scanf("%s", name);
        add_node(g, id, name);
    }
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        printf("Enter edge endpoints and weight (u, v, w): ");
        scanf("%d%d%lf", &u, &v, &weight);
        add_edge(g, u, v, weight);
    }
}

void print_graph(struct graph *g) {
    printf("Nodes:\n");
    for (int i = 0; i < MAX_NODES; i++) {
        struct node *curr_node = g->adj_list[i];
        if (curr_node != NULL) {
            printf("%d - %s\n", curr_node->id, curr_node->name);
        }
    }
    printf("Edges:\n");
    for (int i = 0; i < MAX_NODES; i++) {
        struct node *curr_node = g->adj_list[i];
        while (curr_node != NULL) {
            printf("(%d, %d, %f)\n", i, curr_node->id, rand() % (10 - 1 + 1) + 1);
            curr_node = curr_node->next;
        }
    }
}

bool is_connected(struct graph *g, int u, int v) {
    struct node *curr_node = g->adj_list[u];
    while (curr_node != NULL) {
        if (curr_node->id == v) {
            return true;
        }
        curr_node = curr_node->next;
    }
    return false;
}

void generate_edges(struct graph *g, struct edges *e) {
    int k = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        struct node *curr_node = g->adj_list[i];
        while (curr_node != NULL) {
            int v = curr_node->id;
            if (i < v && !is_connected(g, v, i)) {
                e[k].u = i;
                e[k].v = v;
                e[k].weight = rand() % (10 - 1 + 1) + 1;
                k++;
            }
            curr_node = curr_node->next;
        }
    }
}

int cmpfunc(const void *a, const void *b) {
    struct edges *e1 = (struct edges*)a;
    struct edges *e2 = (struct edges*)b;
    return (int)(e1->weight - e2->weight);
}

int find(int parent[], int i) {
    if (parent[i] == i) {
        return i;
    }
    return find(parent, parent[i]);
}

void union_sets(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    if (rank[xroot] < rank[yroot]) {
        parent[xroot] = yroot;
    } else if (rank[yroot] < rank[xroot]) {
        parent[yroot] = xroot;
    } else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

void kruskal_mst(struct graph *g) {
    struct edges e[g->nodes];
    generate_edges(g, e);
    qsort(e, g->nodes, sizeof(struct edges), cmpfunc);
    int parent[MAX_NODES];
    int rank[MAX_NODES];
    for (int i = 0; i < MAX_NODES; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    struct edges result[g->nodes];
    int i = 0;
    int j = 0;
    while (i < g->nodes - 1 && j < g->nodes) {
        struct edges next_edge = e[j];
        j++;
        int uroot = find(parent, next_edge.u);
        int vroot = find(parent, next_edge.v);
        if (uroot != vroot) {
            result[i] = next_edge;
            i++;
            union_sets(parent, rank, uroot, vroot);
        }
    }
    printf("Minimum Spanning Tree:\n");
    double total_weight = 0;
    for (int i = 0; i < g->nodes - 1; i++) {
        struct edges curr_edge = result[i];
        printf("(%d, %d, %f)\n", curr_edge.u, curr_edge.v, curr_edge.weight);
        total_weight += curr_edge.weight;
    }
    printf("Total Weight: %f\n", total_weight);
}

int main() {
    struct graph g;
    init_graph(&g);
    read_input(&g);
    print_graph(&g);
    printf("\n");
    kruskal_mst(&g);
    return 0;
}