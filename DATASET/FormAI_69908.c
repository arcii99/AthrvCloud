//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

struct Edge {
    int src;
    int dest;
};

struct Graph {
    int vertices;
    int edges;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
};

void init_graph(struct Graph* graph, int vertices, int edges, struct Edge edge_list[]) {
    graph->vertices = vertices;
    graph->edges = edges;
    for(int i=0; i<graph->vertices; i++) {
        for(int j=0; j<graph->vertices; j++) {
            graph->adj_matrix[i][j] = 0;
        }
    }
    for(int i=0; i<graph->edges; i++) {
        graph->adj_matrix[edge_list[i].src][edge_list[i].dest] = 1;
        graph->adj_matrix[edge_list[i].dest][edge_list[i].src] = 1;
    }
}

void print_graph(struct Graph* graph) {
    printf("Adjacency Matrix:\n");
    for(int i=0; i<graph->vertices; i++) {
        for(int j=0; j<graph->vertices; j++) {
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int is_safe_color(struct Graph* graph, int vert, int color[], int c) {
    for(int i=0; i<graph->vertices; i++) {
        if(graph->adj_matrix[vert][i] && c==color[i]) {
            return 0;
        }
    }
    return 1;
}

void graph_coloring(struct Graph* graph, int colors[], int m, int vert, int* soln) {
    if(vert == graph->vertices) {
        *soln = 1;
        printf("Solution:\nVertex Colors: ");
        for(int i=0; i<graph->vertices; i++) {
            printf("%d ", colors[i]);
        }
        printf("\n");
        return;
    }
    for(int c=1; c<=m; c++) {
        if(is_safe_color(graph, vert, colors, c)) {
            colors[vert] = c;
            graph_coloring(graph, colors, m, vert+1, soln);
            if(*soln) {
                return;
            }
            colors[vert] = 0;
        }
    }
}

int main() {
    int vertices = 7;
    int edges = 9;
    struct Edge edge_list[MAX_EDGES] = {{0,1},{0,2},{1,3},{2,3},{2,4},{3,4},{3,5},{4,5},{5,6}};
    struct Graph graph;
    init_graph(&graph, vertices, edges, edge_list);
    printf("Graph created with %d vertices and %d edges\n", vertices, edges);
    print_graph(&graph);
    
    int colors[MAX_VERTICES] = {0};
    int m = 3;
    int soln = 0;
    graph_coloring(&graph, colors, m, 0, &soln);
    
    if(!soln) {
        printf("No solution found with %d colors\n", m);
    }
    
    return 0;
}