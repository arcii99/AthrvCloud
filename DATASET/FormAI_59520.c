//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 5    //Number of vertices

void printSolution(int color[]);   //Function to print the solution

/*Function to check if the current color assignment is safe for the vertex*/
bool isSafe(int graph[V][V], int color[V], int vertex, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[vertex][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

/*Function to recursively solve the graph coloring problem*/
bool graphColoringUtil(int graph[V][V], int m, int color[V], int vertex) {
    /*Base case: If all vertices are assigned a color, return true*/
    if (vertex == V) {
        return true;
    }
    /*Try different colors on the vertex*/
    for (int c = 1; c <= m; c++) {
        /*Check if it is safe to assign the current color*/
        if (isSafe(graph, color, vertex, c)) {
            color[vertex] = c;
            /*Recursively assign colors to the remaining vertices*/
            if (graphColoringUtil(graph, m, color, vertex + 1)) {
                return true;
            }
            /*Backtracking: If the current color assignment doesn't work, try with a different color*/
            color[vertex] = 0;
        }
    }
    return false;
}

/*Function to solve the graph coloring problem*/
bool graphColoring(int graph[V][V], int m) {
    int color[V] = { 0 };
    /*Start with the first vertex*/
    if (graphColoringUtil(graph, m, color, 0) == false) {
        printf("Solution does not exist");
        return false;
    }
    printSolution(color);
    return true;
}

/*Function to print the solution*/
void printSolution(int color[]) {
    printf("Solution Exists: The assigned colors are:\n");
    for (int i = 0; i < V; i++) {
        printf("%d ", color[i]);
    }
}

/*Main function*/
int main() {
    /*Create a graph*/
    int graph[V][V] = {
        { 0, 1, 0, 1, 0 },
        { 1, 0, 1, 1, 1 },
        { 0, 1, 0, 1, 0 },
        { 1, 1, 1, 0, 1 },
        { 0, 1, 0, 1, 0 }
    };
    int m = 3;  //Number of colors
    graphColoring(graph, m);
    return 0;
}