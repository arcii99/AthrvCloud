//FormAI DATASET v1.0 Category: Graph representation ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

// Graph Structure
struct Graph {
    int vertex_number;
    int **adj_matrix;
};

// Create Graph Function
struct Graph createGraph(int v) {
    struct Graph G;
    G.vertex_number = v;
    G.adj_matrix = (int **)malloc(v * sizeof(int *));
    for(int i=0;i<v;i++)
        G.adj_matrix[i] = (int *)calloc(v , sizeof(int));
    return G;
}

// Add Edge Function
void addEdge(struct Graph G , int start_vertex , int end_vertex) {
    G.adj_matrix[start_vertex][end_vertex] = 1;
    G.adj_matrix[end_vertex][start_vertex] = 1;
}

// Display Graph Function
void displayGraph(struct Graph G) {
    for(int i=0;i<G.vertex_number;i++) {
        for(int j=0;j<G.vertex_number;j++)
            printf("%d ", G.adj_matrix[i][j]);
        printf("\n");
    }
}

// Main Function
int main() {
    struct Graph G = createGraph(5);
    addEdge(G , 0 , 1);
    addEdge(G , 0 , 2);
    addEdge(G , 1 , 2);
    addEdge(G , 1 , 3);
    addEdge(G , 2 , 3);
    addEdge(G , 3 , 4);
    printf("Graph Matrix Representation: \n");
    displayGraph(G);
    return 0;
}