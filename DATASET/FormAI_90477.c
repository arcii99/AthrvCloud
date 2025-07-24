//FormAI DATASET v1.0 Category: Graph representation ; Style: accurate
#include <stdio.h>
#define MAXV 100

// Definition of the graph structure
typedef struct {
    int y;                  // Adjacency info
    int weight;             // Edge weight, if any
    struct edgenode *next;  // Next edge in the list
} edgenode;

typedef struct {
    edgenode *edges[MAXV+1]; // Adjacency info
    int degree[MAXV+1];      // Outdegree of each vertex
    int nvertices;           // Number of vertices in the graph
    int nedges;              // Number of edges in the graph
    int directed;            // Is the graph directed?
} graph;

// Initialize the graph
void initialize_graph(graph *g, int directed) {
    int i;
    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;
    for (i=1; i<=MAXV; i++) {
        g->degree[i] = 0;
        g->edges[i] = NULL;
    }
}

// Add an edge to the graph
void insert_edge(graph *g, int x, int y, int weight) {
    edgenode *p;                              
    p = (edgenode*)malloc(sizeof(edgenode)); 
    p->weight = weight;
    p->y = y;
    p->next = g->edges[x];                     
    g->edges[x] = p;                           
    g->degree[x] ++;

    if (g->directed == 0) {                     
        insert_edge(g,y,x,weight);
    } else {
        g->nedges ++;
    }
}

// Read the graph from input
void read_graph(graph *g, int directed) {
    int i, m, x, y, weight;
    initialize_graph(g, directed);
    scanf("%d %d", &(g->nvertices), &m);
    for (i=1; i<=m; i++) {
        scanf("%d %d %d", &x, &y, &weight);
        insert_edge(g,x,y,weight);
    }
}

// Print the graph
void print_graph(graph *g) {
    int i;
    edgenode *p;
    for (i=1; i<=g->nvertices; i++) {
        printf("%d: ",i);
        p = g->edges[i];
        while (p != NULL) {
            printf(" %d(%d)", p->y, p->weight);
            p = p->next;
        }
        printf("\n");
    }
}

// Example usage
int main() {
    graph g;
    read_graph(&g,0);
    print_graph(&g);
    return 0;
}