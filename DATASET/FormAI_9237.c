//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: protected
#include <stdio.h>
#include <stdbool.h>

#define V 6 // number of nodes in the graph

void printSolution(int color[]); // function to print the color of each node
bool isSafe(int node, int graph[V][V], int color[], int c); // function to check if a color is safe for a node
bool graphColoringUtil(int graph[V][V], int m, int color[], int node); // recursive function to solve the graph coloring problem
bool graphColoring(int graph[V][V], int m); // function to solve the graph coloring problem

int main() {
    int graph[V][V] = {
        {0, 1, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 1},
        {1, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1},
        {0, 1, 1, 0, 1, 0}
    };

    int m = 3; // number of available colors
    if (graphColoring(graph, m)) {
        printf("Solution exists!\n");
    }
    else {
        printf("Solution does not exist.\n");
    }

    return 0;
}

void printSolution(int color[]) {
    printf("Node\tColor\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t", i);
        switch (color[i]) {
        case 1:
            printf("Red\n");
            break;
        case 2:
            printf("Green\n");
            break;
        case 3:
            printf("Blue\n");
            break;
        default:
            printf("None\n");
            break;
        }
    }
}

bool isSafe(int node, int graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[node][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(int graph[V][V], int m, int color[], int node) {
    if (node == V) {
        return true; // all nodes have been colored
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(node, graph, color, c)) {
            color[node] = c;

            if (graphColoringUtil(graph, m, color, node + 1)) {
                return true;
            }

            color[node] = 0;
        }
    }

    return false;
}

bool graphColoring(int graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++) {
        color[i] = 0; // no color assigned to any node
    }

    if (!graphColoringUtil(graph, m, color, 0)) {
        return false; // solution does not exist
    }

    printSolution(color);
    return true; // solution exists
}