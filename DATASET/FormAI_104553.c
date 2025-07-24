//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

// Function to check if a color is valid for a vertex
int is_valid_color(int graph[MAX_VERTICES][MAX_VERTICES], int colors[MAX_VERTICES], int vertex, int color)
{
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        if (graph[vertex][i] && colors[i] == color) // Check if the adjacent vertex has the same color
        {
            return 0;
        }
    }
    return 1;
}

// Recursive function to assign colors to the vertices
int assign_colors(int graph[MAX_VERTICES][MAX_VERTICES], int colors[MAX_VERTICES], int num_vertices, int num_colors, int vertex)
{
    if (vertex == num_vertices) // Base case: all vertices are colored
    {
        return 1;
    }

    for (int i = 1; i <= num_colors; i++)
    {
        if (is_valid_color(graph, colors, vertex, i)) // Check if the color is valid for the vertex
        {
            colors[vertex] = i; // Assign the color to the vertex
            if (assign_colors(graph, colors, num_vertices, num_colors, vertex + 1)) // Recursively color the next vertex
            {
                return 1; // If all vertices are successfully colored, return 1
            }
            colors[vertex] = 0; // Backtrack: remove the color from the vertex
        }
    }

    return 0; // If no color works for the vertex, return 0
}

int main()
{
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 0, 1}, // Adjacency matrix of a sample graph with 4 vertices
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int colors[MAX_VERTICES] = {0}; // Array to store the colors of the vertices
    int num_vertices = 4; // Number of vertices in the graph
    int num_colors = 2; // Maximum number of colors to be used

    if (assign_colors(graph, colors, num_vertices, num_colors, 0))
    {
        printf("Colors: ");
        for (int i = 0; i < num_vertices; i++)
        {
            printf("%d ", colors[i]);
        }
        printf("\n");
    }
    else
    {
        printf("No valid coloring!\n");
    }

    return 0;
}