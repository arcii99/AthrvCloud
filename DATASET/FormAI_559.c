//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>

#define V 7

int color[V];

int isSafe(int v, int graph[V][V], int c, int color[]){
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return 0;
    return 1;
}

int graphColoringUtil(int graph[V][V], int m, int vertex){
    if (vertex == V)
        return 1;

    for (int c = 1; c <= m; c++){
        if (isSafe(vertex, graph, c, color)){
            color[vertex] = c;
            if (graphColoringUtil(graph, m, vertex + 1) == 1)
                return 1;
            color[vertex] = 0;
        }
    }
    return 0;
}

void printSolution(){
    printf("Solution Exists:"
           " Following are the assigned colors \n");
    for (int i = 0; i < V; i++)
      printf(" %d ", color[i]);
    printf("\n");
}

void graphColoring(int graph[V][V], int m){
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (graphColoringUtil(graph, m, 0) == 0){
        printf("Solution does not exist");
        return;
    }

    printSolution();
}

int main(){
    int graph[V][V] = {{0, 1, 0, 1, 1, 0, 0},
                       {1, 0, 1, 1, 0, 1, 0},
                       {0, 1, 0, 1, 0, 0, 1},
                       {1, 1, 1, 0, 1, 0, 0},
                       {1, 0, 0, 1, 0, 0, 0},
                       {0, 1, 0, 0, 0, 0, 1},
                       {0, 0, 1, 0, 0, 1, 0}};
    int m = 3;
    graphColoring(graph, m);
    return 0;
}