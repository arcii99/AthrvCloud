//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: recursive
#include <stdio.h>
#include <stdbool.h>

// Number of vertices in the graph
#define V 4

/* This function checks if the current color assignment
   is valid for the vertex v i.e, it checks if the edge 
   exists to a vertex with the same color */
bool isSafe(int graph[V][V], int color[V], int v, int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

/* A recursive utility function to solve m coloring problem */
bool graphColoringUtil(int graph[V][V], int m, int color[V], int v)
{
    // base case: If all vertices are colored
    if (v == V)
        return true;

    // Try different colors for vertex v
    for (int c = 1; c <= m; c++)
    {
        // Check if assignment of color c to v is possible
        if (isSafe(graph, color, v, c))
        {
            color[v] = c;

            // recur to assign colors to the remaining vertices
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;

            // If assigning color c doesn't lead to a solution
            color[v] = 0;
        }
    }

    // If no color can be assigned to this vertex, return false
    return false;
}


/* A function to print solution */
void printSolution(int color[V])
{
    printf("Following are the assigned colors: ");
    for (int i = 0; i < V; i++)
        printf(" %d ", color[i]);
    printf("\n");
}

/* Function to solve the graph coloring problem */
bool graphColoring(int graph[V][V], int m)
{
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    // Call the recursive function to solve the problem
    if (!graphColoringUtil(graph, m, color, 0))
    {
        printf("Solution does not exist");
        return false;
    }

    // Print the colored vertices
    printSolution(color);
    return true;
}

int main()
{
    int graph[V][V] = {{0, 1, 1, 0},
                       {1, 0, 1, 1},
                       {1, 1, 0, 1},
                       {0, 1, 1, 0}};
    int m = 3; // Number of colors

    graphColoring(graph, m);

    return 0;
}