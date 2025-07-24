//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: active
#include <stdio.h>

// Recursive function for graph coloring
void graphColoring(int node, int n, int graph[n][n], int color[n], int m, int *possible) {
    // If all nodes are colored, print the result
    if (node == n) {
        printf("Solution found:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", color[i]);
        }
        printf("\n");
        *possible = 1; // Set possible to true
        return;
    }
    // Try all possible colors for the current node
    for (int c = 1; c <= m; c++) {
        int conflict = 0;
        // Check if color c conflicts with any of the neighbors
        for (int i = 0; i < n; i++) {
            if (graph[node][i] && color[i] == c) {
                conflict = 1;
                break;
            }
        }
        if (!conflict) {
            color[node] = c;  // Assign the color to the current node
            graphColoring(node+1, n, graph, color, m, possible); // Recurse on the next node
            color[node] = 0; // Reset the color for backtracking
        }
    }
}

int main() {
    int n = 5; // Number of nodes
    int m = 3; // Number of colors
    int graph[5][5] = {{0, 1, 1, 0, 0},
                       {1, 0, 1, 1, 0},
                       {1, 1, 0, 1, 1},
                       {0, 1, 1, 0, 1},
                       {0, 0, 1, 1, 0}}; // Adjacency matrix for the graph
    int color[5] = {0}; // Initialize all colors to 0
    int possible = 0; // Initialize possible to false
    graphColoring(0, n, graph, color, m, &possible);
    if (!possible) {
        printf("No solution found!\n");
    }
    return 0;
}