//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: automated
#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100 // Maximum number of vertices a graph can have

int graph[MAX_VERTICES][MAX_VERTICES]; // Graph matrix
int vertices; // Total number of vertices in the graph
int colors[MAX_VERTICES]; // Color array to store the color of each vertex
int num_colors = 3; // Number of colors assumed to be 3

// Function to check if it is safe to color a vertex with a certain color
bool is_safe(int vertex, int color)
{
    for (int i = 0; i < vertices; i++)
    {
        if (graph[vertex][i] && color == colors[i])
        {
            return false;
        }
    }

    return true;
}

// Function to recursively color the graph
bool color_graph_util(int vertex)
{
    // Base case: All vertices have been colored
    if (vertex == vertices)
    {
        return true;
    }

    // Try different colors for this vertex
    for (int i = 1; i <= num_colors; i++)
    {
        // Check if it is safe to color the vertex with this color
        if (is_safe(vertex, i))
        {
            // Assign the color to the vertex
            colors[vertex] = i;

            // Recursively color the rest of the graph
            if (color_graph_util(vertex + 1))
            {
                return true;
            }

            // If the recursive call fails, backtrack and try a different color
            colors[vertex] = 0;
        }
    }

    return false;
}

// Function to color the graph using the minimum number of colors
void color_graph()
{
    if (color_graph_util(0))
    {
        // Print the color of each vertex
        printf("The graph has been colored with the following colors:\n");
        for (int i = 0; i < vertices; i++)
        {
            printf("Vertex %d: Color %d\n", i, colors[i]);
        }
    }
    else
    {
        printf("Unable to color the graph with %d colors.\n", num_colors);
    }
}

int main()
{
    // Initialize the graph with 0s
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        for (int j = 0; j < MAX_VERTICES; j++)
        {
            graph[i][j] = 0;
        }

        colors[i] = 0;
    }

    // Example graph
    vertices = 5;
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][0] = 1;
    graph[1][2] = 1;
    graph[1][3] = 1;
    graph[2][0] = 1;
    graph[2][1] = 1;
    graph[2][3] = 1;
    graph[2][4] = 1;
    graph[3][1] = 1;
    graph[3][2] = 1;
    graph[3][4] = 1;
    graph[4][2] = 1;
    graph[4][3] = 1;

    // Color the graph
    color_graph();

    return 0;
}