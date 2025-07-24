//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: genious
#include <stdio.h>

#define V 4 // vertices of the graph

void printSolution(int color[]);

/* A utility function to check if the current
coloring is safe for vertex v */
int isSafe(int v, int graph[V][V],
           int color[], int c)
{
    for (int i = 0; i < V; i++)
    {
        if (graph[v][i] && c == color[i])
            return 0;
    }
    return 1;
}

/* A recursive utility function to solve
the m-coloring problem */
int graphColoringUtil(int graph[V][V], int m,
                      int color[V], int v)
{
    if (v == V)
        return 1;

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, graph, color, c))
        {
            color[v] = c;

            if (graphColoringUtil(graph, m, color, v + 1) == 1)
                return 1;

            color[v] = 0;
        }
    }

    return 0;
}

/* This function solves the m-coloring problem using
Backtracking. It mainly uses graphColoringUtil() to
solve the problem. It returns false if the m colors
cannot be assigned, otherwise, returns true and prints
assignments of colors to all vertices. */
void graphColoring(int graph[V][V], int m)
{
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (graphColoringUtil(graph, m, color, 0) == 0)
    {
        printf("Solution does not exist");
        return;
    }

    // Print the solution
    printf("Solution exists and the coloring of graph is: \n");
    printSolution(color);
}

/* A utility function to print solution */
void printSolution(int color[])
{
    for (int i = 0; i < V; i++)
        printf("%d ", color[i]);
}

// Driver program to test above function
int main()
{
    // Test case 1
    int graph1[V][V] = {{0, 1, 1, 1},
                        {1, 0, 1, 0},
                        {1, 1, 0, 1},
                        {1, 0, 1, 0}};
    int m1 = 3;
    graphColoring(graph1, m1);

    // Test case 2
    int graph2[V][V] = {{0, 1, 1, 1},
                        {1, 0, 1, 1},
                        {1, 1, 0, 1},
                        {1, 1, 1, 0}};
    int m2 = 3;
    graphColoring(graph2, m2);

    return 0;
}