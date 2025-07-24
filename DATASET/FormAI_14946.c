//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Claude Shannon
#include <stdio.h>

#define V 5 // number of vertices

void printSolution(int color[]);

// function to check if it is safe to assign color c to vertex v
int isSafe(int v, int graph[V][V], int color[], int c)
{
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i]) {
            return 0;
        }
    }
    return 1;
}

// recursive function to assign colors to all vertices
int graphColoring(int graph[V][V], int color[], int v)
{
    if (v == V) {
        printSolution(color);
        return 1;
    }

    for (int c = 1; c <= V; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoring(graph, color, v + 1)) {
                return 1;
            }
            color[v] = 0;
        }
    }
    return 0;
}

// function to print the colors assigned to all vertices
void printSolution(int color[])
{
    printf("Vertex colors:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d: Color %d\n", i, color[i]);
    }
    printf("\n");
}

// main function to test the program
int main()
{
    int graph[V][V] = {{0, 1, 1, 1, 0},
                       {1, 0, 1, 0, 1},
                       {1, 1, 0, 1, 0},
                       {1, 0, 1, 0, 1},
                       {0, 1, 0, 1, 0}}; // adjacency matrix

    int color[V] = {0}; // array to store colors assigned to vertices

    if (!graphColoring(graph, color, 0)) {
        printf("Solution does not exist\n");
    }

    return 0;
}