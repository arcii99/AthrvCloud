//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: careful
#include<stdio.h>

// Function to check if the color chosen for the current vertex is safe or not
int isSafe(int v, int graph[7][7], int color[], int c) {
    for(int i = 0; i < 7; i++) {
        if(graph[v][i] && c == color[i])
            return 0;
    }
    return 1;
}

// Function to solve the Graph Coloring Problem using Backtracking
int graphColoringUtil(int graph[7][7], int m, int color[], int v) {
    if(v == 7)
        return 1;
    for(int c = 1; c <= m; c++) {
        if(isSafe(v, graph, color, c)) {
            color[v] = c;
            if(graphColoringUtil(graph, m, color, v+1))
                return 1;
        }
        color[v] = 0;
    }
    return 0;
}

// Function to print the solution
void printSolution(int color[]) {
    printf("\nVertex   Color\n");
    for(int i = 0; i < 7; i++)
        printf("%d         %d\n", i, color[i]);
}

// Function to solve the Graph Coloring Problem
void graphColoring(int graph[7][7], int m) {
    int color[7] = {0};
    if(graphColoringUtil(graph, m, color, 0) == 0)
        printf("\nSolution does not exist.");
    else 
        printSolution(color);
}

// Main function, where we define the graph
int main() {
    int graph[7][7] = {{0, 1, 1, 0, 0, 0, 0},
                       {1, 0, 1, 1, 0, 0, 0},
                       {1, 1, 0, 1, 1, 0, 1},
                       {0, 1, 1, 0, 1, 1, 0},
                       {0, 0, 1, 1, 0, 1, 1},
                       {0, 0, 0, 1, 1, 0, 1},
                       {0, 0, 1, 0, 1, 1, 0}
                      };
    int m = 3; // Number of colors
    graphColoring(graph, m);
    return 0;
}