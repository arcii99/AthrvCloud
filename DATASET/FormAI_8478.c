//FormAI DATASET v1.0 Category: Graph representation ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>

#define MAX_EDGES 50
#define MAX_VERTICES 20

struct edge {
    int n1;
    int n2;
};

struct graph {
    int vertices[MAX_VERTICES];
    struct edge edges[MAX_EDGES];
    int num_vertices;
    int num_edges;
};

void init_graph(struct graph*);
void add_vertex(struct graph*, int);
void add_edge(struct graph*, int, int);
void print_graph(struct graph*);

int main() {
    struct graph G;
    init_graph(&G);
    
    add_vertex(&G, 1);
    add_vertex(&G, 2);
    add_vertex(&G, 3);
    
    add_edge(&G, 1, 2);
    add_edge(&G, 1, 3);
    add_edge(&G, 2, 3);
    
    print_graph(&G);
    
    return 0;
}

void init_graph(struct graph* G) {
    G->num_vertices = 0;
    G->num_edges = 0;
}

void add_vertex(struct graph* G, int v) {
    if(G->num_vertices == MAX_VERTICES) {
        printf("Error: Max number of vertices reached\n");
        exit(EXIT_FAILURE);
    }
    G->vertices[G->num_vertices] = v;
    G->num_vertices++;
}

void add_edge(struct graph* G, int n1, int n2) {
    if(G->num_edges == MAX_EDGES) {
        printf("Error: Max number of edges reached\n");
        exit(EXIT_FAILURE);
    }
    G->edges[G->num_edges].n1 = n1;
    G->edges[G->num_edges].n2 = n2;
    G->num_edges++;
}

void print_graph(struct graph* G) {
    int i;
    printf("Vertices: ");
    
    for(i=0; i<G->num_vertices; i++) {
        printf("%d ", G->vertices[i]);
    }
    
    printf("\nEdges: ");
    
    for(i=0; i<G->num_edges; i++) {
        printf("(%d,%d) ", G->edges[i].n1, G->edges[i].n2);
    }
    
    printf("\n");
}