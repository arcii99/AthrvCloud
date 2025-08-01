//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: real-life
#include <stdio.h>
#include <stdbool.h>

#define V 4

// Function to print the solution matrix
void printSolution(int color[])
{
    printf("Solution Exists:"
           " Following are the assigned colors \n");
    for (int i = 0; i < V; i++)
        printf(" %d ", color[i]);
    printf("\n");
}

// Function to check if the current color assignment
// is safe for vertex v
bool isSafe(int v, bool graph[V][V], int color[], int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

// Function to assign colors recursively
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v)
{
    // if all vertices are colored return true
    if (v == V)
        return true;

    // assigning colors to vertex v
    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, graph, color, c))
        {
            color[v] = c;
            // recursive call
            if (graphColoringUtil(graph, m, color, v + 1) == true)
                return true;
            // backtracking
            color[v] = 0;
        }
    }
    return false;
}

// Main function to call graphColoringUtil
// and print the solution
bool graphColoring(bool graph[V][V], int m)
{
    // initialize all colors as 0
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    // call graphColoringUtil for vertex 0
    if (graphColoringUtil(graph, m, color, 0) == false)
    {
        printf("Solution does not exist");
        return false;
    }

    // print the solution
    printSolution(color);
    return true;
}

// Driver code
int main()
{
    // Create a sample graph
    bool graph[V][V] = {{0, 1, 1, 1},
                        {1, 0, 1, 0},
                        {1, 1, 0, 1},
                        {1, 0, 1, 0}};
    int m = 3; // Number of colors

    graphColoring(graph, m);
    return 0;
}