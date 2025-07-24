//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#define V 5

void printSolution(int color[]);

//function to check if color can be assigned to vertex
int isSafe(int v, int graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return 0;
    return 1;
}

//recursive program for graph coloring
int graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    if (v == V)
        return 1;

    //iterating through all colors
    for (int c = 1; c <= m; c++) {
        //checking if color can be assigned to vertex
        if (isSafe(v, graph, color, c)) {
            color[v] = c;

            //recursively coloring remaining vertices
            if (graphColoringUtil(graph, m, color, v + 1) == 1)
                return 1;
            color[v] = 0;
        }
    }
    return 0;
}

//main function for graph coloring
void graphColoring(int graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    //calling recursive function
    if (graphColoringUtil(graph, m, color, 0) == 0) {
        printf("Solution does not exist");
        return;
    }

    //printing solution
    printSolution(color);
}

//function to print solution
void printSolution(int color[]) {
    printf("Solution Exists:"
           " Following are the assigned colors \n");
    for (int i = 0; i < V; i++)
        printf(" %d ", color[i]);
    printf("\n");
}

//driver function
int main() {
    int graph[V][V] = {
            {0, 1, 1, 1, 0},
            {1, 0, 1, 0, 1},
            {1, 1, 0, 1, 0},
            {1, 0, 1, 0, 1},
            {0, 1, 0, 1, 0}
    };
    int m = 3; //number of colors
    graphColoring(graph, m);
    return 0;
}