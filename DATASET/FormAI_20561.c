//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: puzzling
#include <stdio.h>
#define N 5  // Number of vertices in the graph

int graph[N][N] = { // Adjacency matrix representation of the graph
                     {0, 1, 1, 0, 1},
                     {1, 0, 1, 1, 1},
                     {1, 1, 0, 1, 0},
                     {0, 1, 1, 0, 1},
                     {1, 1, 0, 1, 0}
                  };
                  
int color[N];  // To store the color of each vertex

// Function to check if the given color is safe for the vertex v
int isSafe(int v, int c) {
    for (int i = 0; i < N; i++) {
        if (graph[v][i] && c == color[i]) {
            return 0;
        }
    }
    return 1;
}

// Function to print the solution
void printSolution() {
    printf("The assigned colors are:\n");
    for (int i = 0; i < N; i++) {
        printf("Vertex %d -> Color %d\n", i, color[i]);
    }
}

// Recursive function to solve the graph coloring problem
int graphColoring(int v) {
    if (v == N) {  // All vertices have been colored
        printSolution();
        return 1;
    }
    for (int c = 1; c <= N; c++) {
        if (isSafe(v, c)) {  // Check if the given color c is safe for vertex v
            color[v] = c;
            if (graphColoring(v+1)) {  // Recur for the next vertex
                return 1;
            }
            color[v] = 0;  // Backtrack
        }
    }
    return 0; // Cannot assign any color to this vertex
}

int main() {
    printf("Welcome to the Graph Coloring Problem Puzzler!\n");
    printf("You are given a graph and your task is to assign colors to each vertex so that no two adjacent vertices have the same color.\n");
    printf("Here is your graph:\n");
    for (int i = 0; i < N; i++) {
        printf("Vertex %d -> ", i);
        for (int j = 0; j < N; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("Press ENTER to start solving...\n");
    getchar();
    if (graphColoring(0) == 0) {
        printf("Sorry, it is not possible to color the given graph with %d colors.\n", N);
    }
    return 0;
}