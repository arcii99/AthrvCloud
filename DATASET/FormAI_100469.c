//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 4 //Number of vertices

/*Function to print the solution*/
void printSolution(int color[]) {
    printf("The assigned colors are:\n");
    for (int i = 0; i < V; i++)
        printf("%d ", color[i]);
    printf("\n");
}

/*Function to check if it is safe to assign the color to the vertex*/
bool isSafe(int v, bool graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i])
            return false;
    }
    return true;
}

/*Function to assign colors recursively*/
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v) {
    /*Base condition: If all the vertices are assigned the colors, return true*/
    if (v == V)
        return true;

    /*Iterate through all the colors*/
    for (int c = 1; c <= m; c++) {
        /*Check if it is safe to assign the color c to the vertex*/
        if (isSafe(v, graph, color, c)) {
            color[v] = c;

            /*Recursively assign colors to the remaining vertices*/
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;

            /*Backtrack step: If assigning color c doesn't lead to a solution, undo the assignment*/
            color[v] = 0;
        }
    }
    return false;
}

/*Function to solve the graph coloring problem*/
bool graphColoring(bool graph[V][V], int m) {
    int color[V];

    /*Initialize all the colors as 0*/
    for (int i = 0; i < V; i++)
        color[i] = 0;

    /*Try assigning colors recursively*/
    if (!graphColoringUtil(graph, m, color, 0)) {
        printf("No solution exists.\n");
        return false;
    }

    /*Print the solution*/
    printSolution(color);
    return true;
}

/*Driver function*/
int main() {
    bool graph[V][V] = {{0, 1, 1, 1},
                        {1, 0, 1, 0},
                        {1, 1, 0, 1},
                        {1, 0, 1, 0}};

    int m = 3; //Number of colors
    graphColoring(graph, m);
    return 0;
}