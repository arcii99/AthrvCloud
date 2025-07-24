//FormAI DATASET v1.0 Category: Graph representation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct {
    int vertex[MAX];
    int adj_matrix[MAX][MAX];
    int num_vertices;
} Graph;

void init_graph(Graph* G) {
    G->num_vertices = 0;

    for(int i = 0; i < MAX; i++) {
        G->vertex[i] = 0;

        for(int j = 0; j < MAX; j++) {
            G->adj_matrix[i][j] = 0;
        }
    }
}

void add_vertex(Graph* G, int vertex) {
    if(G->num_vertices < MAX) {
        G->vertex[G->num_vertices++] = vertex;
    } else {
        printf("Graph is full!\n");
    }
}

void add_edge(Graph* G, int vertex1, int vertex2) {
    int index1 = -1, index2 = -1;

    for(int i = 0; i < G->num_vertices; i++) {
        if(G->vertex[i] == vertex1) {
            index1 = i;
        }

        if(G->vertex[i] == vertex2) {
            index2 = i;
        }
    }

    if(index1 == -1 || index2 == -1) {
        printf("Invalid vertex!\n");
    } else {
        G->adj_matrix[index1][index2] = 1;
        G->adj_matrix[index2][index1] = 1;
    }
}

void display(Graph G) {
    printf("Vertices:\n");

    for(int i = 0; i < G.num_vertices; i++) {
        printf("%d ", G.vertex[i]);
    }

    printf("\nAdjacency matrix:\n");

    for(int i = 0; i < G.num_vertices; i++) {
        for(int j = 0; j < G.num_vertices; j++) {
            printf("%d ", G.adj_matrix[i][j]);
        }

        printf("\n");
    }
}

int main() {
    Graph G;
    init_graph(&G);

    printf("Adding vertices...\n");
    add_vertex(&G, 1);
    add_vertex(&G, 2);
    add_vertex(&G, 3);
    add_vertex(&G, 4);
    add_vertex(&G, 5);

    printf("Adding edges...\n");
    add_edge(&G, 1, 2);
    add_edge(&G, 1, 3);
    add_edge(&G, 1, 4);
    add_edge(&G, 2, 5);
    add_edge(&G, 3, 5);

    printf("Displaying graph...\n");
    display(G);

    return 0;
}