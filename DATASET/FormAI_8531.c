//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NODES 10
// Define maximum number of colors
#define COLORS 4

void printSolution(int color[]);
int isSafe(int node, int graph[][NODES], int color[], int c);
int graphColoringUtil(int graph[][NODES], int m, int color[], int node);

int main()
{
    // Set random seed
    srand(time(0));
    // Define graph as a 2D array
    int graph[NODES][NODES];
    // Initialize graph with random values
    for (int i = 0; i < NODES; i++) {
        for (int j = 0; j < NODES; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = graph[j][i] = rand() % 2;
            }
        }
    }
    // Print graph
    printf("Generated Graph:\n");
    for (int i = 0; i < NODES; i++) {
        for (int j = 0; j < NODES; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    // Initialize color array
    int color[NODES];
    // Initialize colors to 0
    for (int i = 0; i < NODES; i++) {
        color[i] = 0;
    }
    // Graph coloring using backtrack
    if (graphColoringUtil(graph, COLORS, color, 0) == 0) {
        printf("Solution does not exist");
        return 0;
    }
    // Print solution
    printf("Solution Exists: ");
    printSolution(color);
    return 0;
}

/* A utility function to print solution */
void printSolution(int color[])
{
    printf("Assigned Colors:\n");
    for (int i = 0; i < NODES; i++) {
        printf("Node %d: Color %d\n", i, color[i]);
    }
}

/* A utility function to check if the current color assignment is safe for node v */
int isSafe(int node, int graph[][NODES], int color[], int c)
{
    for (int i = 0; i < NODES; i++) {
        if (graph[node][i] && c == color[i]) {
            return 0;
        }
    }
    return 1;
}

/* A recursive utility function to solve graph coloring problem */
int graphColoringUtil(int graph[][NODES], int m, int color[], int node)
{
    // If all nodes are assigned a color
    if (node == NODES) {
        return 1;
    }
    // Consider this node for all colors from 1 to m
    for (int i = 1; i <= m; i++) {
        // Check if assignment of color i to node v is valid
        if (isSafe(node, graph, color, i)) {
            color[node] = i;
            // Recur to assign colors to rest of the nodes
            if (graphColoringUtil(graph, m, color, node + 1) == 1) {
                return 1;
            }
            // If assigning color i doesn't lead to a solution then remove it
            color[node] = 0;
        }
    }
    // If no color can be assigned to this node then return 0
    return 0;
}