//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: synchronous
#include <stdio.h>
#define V 4

// Function to check if it is safe to color the given
// vertex v with color c
int isSafe(int v, int graph[V][V], int color[], int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return 0;
    return 1;
}

// A recursive utility function to solve graph coloring
void graphColorUtil(int graph[V][V], int m, int color[V], int v)
{
    // If all vertices are assigned a color then return
    if (v == V)
    {
        printf("Solution found!\n");
        for (int i = 0; i < V; i++)
            printf("Vertex %d --> Color %d\n", i, color[i]);
        return;
    }

    // Consider this vertex v and try different colors
    for (int c = 1; c <= m; c++)
    {
        // Check if assignment of color c to v is safe
        if (isSafe(v, graph, color, c))
        {
            color[v] = c;
            // Recur to assign colors to rest of the vertices
            graphColorUtil(graph, m, color, v + 1);
            // If the recursion is unable to find a solution, backtrack and try a different color
            color[v] = 0;
        }
    }
}

// Main function to solve graph coloring problem
void graphColoring(int graph[V][V], int m)
{
    // Initialize all colors as 0
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    // Call the utility function to solve graph coloring problem
    graphColorUtil(graph, m, color, 0);
}

// Driver program to test above functions
int main()
{
    int graph[V][V] = {{0, 1, 1, 1},
                       {1, 0, 1, 0},
                       {1, 1, 0, 1},
                       {1, 0, 1, 0}};
    int m = 3; // Number of colors
    graphColoring(graph, m);
    return 0;
}