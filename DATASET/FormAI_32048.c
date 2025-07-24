//FormAI DATASET v1.0 Category: Graph representation ; Style: accurate
#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 100

typedef struct edge {
    int source;
    int destination;
    int weight;
} Edge;

typedef struct graph {
    Edge edges[MAX_VERTICES];
    int degree[MAX_VERTICES];
    int num_vertices;
    int num_edges;
} Graph;

void init_graph(Graph *g) {
    g->num_vertices = 0;
    g->num_edges = 0;
    int i;
    for(i = 0; i < MAX_VERTICES; i++) {
        g->degree[i] = 0;
    }
}

void insert_edge(Graph *g, int u, int v, int w) {
    if(g->degree[u] == MAX_VERTICES) {
        printf("Graph is too large\n");
        exit(1);
    }
    g->edges[g->num_edges].source = u;
    g->edges[g->num_edges].destination = v;
    g->edges[g->num_edges].weight = w;
    g->degree[u]++;
    g->num_edges++;
}

void read_graph(Graph *g) {
    printf("Enter the number of vertices: ");
    scanf("%d", &g->num_vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &g->num_edges);
    int i, u, v, w;
    for(i = 0; i < g->num_edges; i++) {
        printf("Enter edge %d (u v w): ", i+1);
        scanf("%d %d %d", &u, &v, &w);
        insert_edge(g, u, v, w);
    }
}

void print_graph(Graph *g) {
    int i, j;
    for(i = 0; i < g->num_vertices; i++) {
        printf("%d: ", i);
        for(j = 0; j < g->degree[i]; j++) {
            printf("(%d,%d,%d) ", g->edges[j].source,
                                 g->edges[j].destination, 
                                 g->edges[j].weight);
        }
        printf("\n");
    }
}

int main() {
    Graph g;
    init_graph(&g);
    read_graph(&g);
    print_graph(&g);
    return 0;
}