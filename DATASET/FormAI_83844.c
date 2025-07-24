//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 50

/* Graph Data Structure */
struct Graph {
    int V;
    int E;
    int adj[MAX_VERTICES][MAX_VERTICES];
};

/* Function to initialize Graph */
void initGraph(struct Graph* g) {
    int i, j;
    g->V = 0;
    g->E = 0;
    for(i=0; i<MAX_VERTICES; i++) {
        for(j=0; j<MAX_VERTICES; j++) {
            g->adj[i][j] = 0;
        }
    }
}

/* Function to add edge to Graph */
void addEdge(struct Graph* g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
    g->E++;
}

/* Function to print Graph */
void printGraph(struct Graph* g) {
    int i, j;
    printf("Vertices: %d, Edges: %d\n", g->V, g->E);
    for(i=0; i<g->V; i++) {
        printf("[%d]: ", i);
        for(j=0; j<g->V; j++) {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

/* Function to check if Graph is valid */
bool isValidGraph(struct Graph* g, int colors[]) {
    int i, j;
    for(i=0; i<g->V; i++) {
        for(j=i+1; j<g->V; j++) {
            if(g->adj[i][j] && colors[i] == colors[j]) {
                return false;
            }
        }
    }
    return true;
}

/* Function to solve Graph Coloring Problem using Backtracking */
bool solveGraphColoring(struct Graph* g, int m, int colors[], int v) {
    if(v == g->V) {
        if(isValidGraph(g, colors)) {
            return true;
        } else {
            return false;
        }
    }
    int i, j;
    for(i=1; i<=m; i++) {
        colors[v] = i;
        if(solveGraphColoring(g, m, colors, v+1)) {
            return true;
        }
        colors[v] = 0;
    }
    return false;
}

/* Main function */
int main() {
    struct Graph g;
    initGraph(&g);
    g.V = 5;
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 2, 4);
    int colors[MAX_VERTICES] = {0};
    int m = 3;
    if(solveGraphColoring(&g, m, colors, 0)) {
        printf("Colors: ");
        int i;
        for(i=0; i<g.V; i++) {
            printf("%d ", colors[i]);
        }
        printf("\n");
    } else {
        printf("Solution does not exist.\n");
    }
    return 0;
}