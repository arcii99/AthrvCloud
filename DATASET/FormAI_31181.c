//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: high level of detail
#include <stdio.h>
#include <stdbool.h>

// Maximum number of vertices
#define MAX_VERTICES 100

// Function to check if it is safe to assign color to a vertex
bool isSafe(int vertex, int graph[MAX_VERTICES][MAX_VERTICES], int colors[], int num_of_colors)
{
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        if (graph[vertex][i] && colors[i] == num_of_colors)
            return false;
    }
    return true;
}

// Function for graph coloring
bool graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int num_of_colors, int colors[], int vertex)
{
    // If all vertices are colored, return true
    if (vertex == MAX_VERTICES)
        return true;

    // Consider this vertex and try different colors
    for (int color = 1; color <= num_of_colors; color++)
    {
        // Check if it is safe to assign this color to this vertex
        if (isSafe(vertex, graph, colors, color))
        {
            colors[vertex] = color;

            // Recur for the next vertices
            if (graphColoringUtil(graph, num_of_colors, colors, vertex + 1))
                return true;

            // If assigning this color does not lead to a solution, remove it
            colors[vertex] = 0;
        }
    }

    // If no color can be assigned to this vertex, return false
    return false;
}

// Function to print the colored graph
void printColors(int colors[])
{
    printf("Vertex Colors:\n");
    for (int i = 0; i < MAX_VERTICES; i++)
        printf("Vertex %d : Color %d\n", i, colors[i]);
}

// Main function
int main()
{
    // Taking a sample graph inputs (4 vertices)
    int graph[MAX_VERTICES][MAX_VERTICES] = {{0, 1, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 1}, {1, 0, 1, 0}};

    // Number of colors to be used in the graph
    int num_of_colors = 3;

    // Initializing all vertices as uncolored
    int colors[MAX_VERTICES] = {0};

    // Calling graphColoringUtil to color the graph
    if (graphColoringUtil(graph, num_of_colors, colors, 0))
        printColors(colors);
    else
        printf("Solution does not exist for this graph");

    return 0;
}