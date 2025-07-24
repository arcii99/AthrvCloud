//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: automated
#include <stdio.h>

// Maximum number of vertices in the graph
#define V 4

void printSolution(int color[]);

// check if it is safe to color the vertex with c color
int isSafe(int v, int graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i]) {
            return 0;
        }
    }
    return 1;
}

/* A recursive utility function to solve m coloring
   problem */
int graphColorUtil(int graph[V][V], int m, int color[], int v) {
    // base case: all vertices are colored
    if (v == V) {
        return 1;
    }

    // try different colors for this vertex
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            // assign color and recur for the next vertex
            color[v] = c;
            if (graphColorUtil(graph, m, color, v + 1)) {
                return 1;
            }
            // backtrack
            color[v] = 0;
        }
    }

    return 0;
}

/* This function solves the m Coloring problem using
   Backtracking. It mainly uses graphColorUtil() to
   solve the problem. It returns false if the m colors
   cannot be assigned, otherwise, it returns true and
   prints the solution.
   Please note that there may be more than one solutions,
   this function prints one of the feasible solutions. */
void graphColoring(int graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++) {
        color[i] = 0;
    }

    if (graphColorUtil(graph, m, color, 0) == 0) {
        printf("Solution does not exist");
        return;
    }

    // print the solution
    printSolution(color);

    return;
}

void printSolution(int color[]) {
    printf("Solution Exists:"
           " Following are the assigned colors \n");
    for (int i = 0; i < V; i++) {
        printf(" %d ", color[i]);
    }
    printf("\n");
}

int main() {
    int graph[V][V] = {{0, 1, 1, 1},
                       {1, 0, 1, 0},
                       {1, 1, 0, 1},
                       {1, 0, 1, 0}
                     };
    int m = 3; // Number of colors

    graphColoring(graph, m);

    return 0;
}