//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define V 5

int graph[V][V] = {
    {0, 1, 1, 1, 0},
    {1, 0, 1, 0, 1},
    {1, 1, 0, 1, 0},
    {1, 0, 1, 0, 1},
    {0, 1, 0, 1, 0}
};

void printSolution(int color[]) {
    printf("Vertex \tColor\n");
    for(int i = 0; i < V; i++) {
        printf(" %d \t %d\n", i, color[i]);
    }
}

int isSafe(int v, int color[], int c) {
    for(int i = 0; i < V; i++) {
        if(graph[v][i] && c == color[i]) {
            return 0;
        }
    }
    return 1;
}

int graphColoringUtil(int m, int color[], int v) {
    if(v == V) {
        return 1;
    }

    for(int i = 1; i <= m; i++) {
        if(isSafe(v, color, i)) {
            color[v] = i;
            if(graphColoringUtil(m, color, v + 1)) {
                return 1;
            }
            color[v] = 0;
        }
    }

    return 0;
}

void graphColoring(int m) {
    int color[V];
    for(int i = 0; i < V; i++) {
        color[i] = 0;
    }

    if(graphColoringUtil(m, color, 0) == 0) {
        printf("Solution does not exist\n");
        return;
    }

    printSolution(color);
}

int main() {
    int m = 3;
    graphColoring(m);
    return 0;
}