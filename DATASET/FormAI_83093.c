//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_COLOR 4
#define MAX_NODE 7

// Function to check if assigning the given color to the vertex is safe or not
bool isSafe(int graph[MAX_NODE][MAX_NODE], int color[MAX_NODE], int vertex, int selected_color)
{
    for (int i = 0; i < MAX_NODE; i++) {
        if (graph[vertex][i] && selected_color == color[i]) {
            return false;
        }
    }
    return true;
}

// Function to print the result
void printResult(int* color)
{
    printf("\nColor solution for the given graph: \n");
    for (int i = 0; i < MAX_NODE; i++) {
        printf("Node %d => %d\n", i + 1, color[i]);
    }
}

// Function to backtrack to the previous vertex if the current vertex is not colored
bool graphColoring(int graph[MAX_NODE][MAX_NODE], int color[MAX_NODE], int vertex)
{
    // When all vertices are colored
    if (vertex == MAX_NODE) {
        return true;
    }

    // Try different colors on the current vertex
    for (int i = 1; i <= MAX_COLOR; i++) {
        if (isSafe(graph, color, vertex, i)) {
            color[vertex] = i;

            // Check if the next vertex can be assigned with the color
            if (graphColoring(graph, color, vertex + 1) == true) {
                return true;
            }
            // if backtracked to the previous vertex, reset the color of the current vertex to 0
            color[vertex] = 0;
        }
    }
    return false;
}

int main()
{
    // Create the graph matrix
    int graph[MAX_NODE][MAX_NODE] = {
        {0, 1, 1, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {0, 1, 1, 0, 1, 1, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 1, 1, 0, 1},
        {0, 0, 0, 0, 1, 1, 0}
    };
    // Create the color array to hold the color of each vertex
    int color[MAX_NODE] = {0};

    // Call the graphColoring function to color the graph
    if (graphColoring(graph, color, 0) == true) {
        printResult(color);
    }
    else {
        printf("Solution does not exist.");
    }
    return 0;
}