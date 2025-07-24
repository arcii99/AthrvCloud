//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: high level of detail
#include <stdio.h>
#include <stdbool.h>

#define V 4 // Define the number of vertices in the graph

// Function to check if it is safe to color the vertex with certain color
bool isSafe(int graph[V][V], int vertex, int color, int colorArr[])
{
    for (int i = 0; i < V; i++)
    {
        if (graph[vertex][i] && colorArr[i] == color) // Checking the adjacent vertices of the vertex
        {
            return false; // If an adjacent vertex is already colored with the same color, then it becomes unsafe
        }
    }

    return true; // If the vertex can be safely colored with the given color, return true
}

// Recursive function to assign colors to all vertices of the graph
bool graphColoringUtil(int graph[V][V], int m, int colorArr[], int vertex)
{
    // If all vertices are assigned a color, then return true
    if (vertex == V)
    {
        return true;
    }

    // Try different colors for the current vertex
    for (int color = 1; color <= m; color++)
    {
        // Check if it is safe to assign this color to this vertex
        if (isSafe(graph, vertex, color, colorArr))
        {
            colorArr[vertex] = color;

            // Recursively assign colors to rest of the vertices
            if (graphColoringUtil(graph, m, colorArr, vertex + 1))
            {
                return true;
            }

            colorArr[vertex] = 0; // Reset the color if no color can be assigned to the vertex
        }
    }

    return false; // Return false if no color can be assigned to this vertex
}

// Function to print the color assignment of each vertex
void printColors(int colorArr[])
{
    printf("Vertex Colors:\n");

    for (int i = 0; i < V; i++)
    {
        printf("Vertex %d: Color %d\n", i, colorArr[i]);
    }
}

// Main function to execute the graph coloring program
int main()
{
    int graph[V][V] = {{0, 1, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 1}, {1, 0, 1, 0}};

    int m = 3; // Maximum number of colors that can be used

    int colorArr[V] = {0}; // Array to store the color assignment of each vertex

    if (graphColoringUtil(graph, m, colorArr, 0))
    {
        printf("Graph can be colored with %d colors.\n", m);
        printColors(colorArr);
    }
    else
    {
        printf("Graph cannot be colored with %d colors.\n", m);
    }

    return 0;
}