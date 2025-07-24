//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define V 5

int graph[V][V] = {{0, 1, 1, 0, 0},
                  {1, 0, 1, 1, 0},
                  {1, 1, 0, 1, 1},
                  {0, 1, 1, 0, 1},
                  {0, 0, 1, 1, 0}};

void printSolution(int color[]){
    printf("Vertex\tColor\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i+1, color[i]);
}

bool isSafe(int vertex, int graph[V][V], int color[], int c){
    for (int i = 0; i < V; i++){
        if (graph[vertex][i] && c == color[i])
            return false;
    }
    return true;
}

bool graphColoringUtil(int graph[V][V], int m, int color[], int vertex){
    if (vertex == V){
        return true;
    }
    for (int i = 1; i <= m; i++){
        if (isSafe(vertex, graph, color, i)){
            color[vertex] = i;
            if (graphColoringUtil(graph, m, color, vertex+1) == true)
                return true;
            color[vertex] = 0;
        }
    }
    return false;
}

bool graphColoring(int graph[V][V], int m){
    int color[V];
    for (int i = 0; i < V; i++){
        color[i] = 0;
    }
    if (graphColoringUtil(graph, m, color, 0) == false){
        printf("Solution does not exist.\n");
        return false;
    }
    printSolution(color);
    return true;
}

int main(){
    int m = 3;
    graphColoring(graph, m);
    return 0;
}