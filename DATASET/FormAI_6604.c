//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: complete
#include<stdio.h>
#include<stdlib.h>

#define V 4

/* This function checks if the color c
   can be assigned to vertix v in graph
   colored[] is the color array */
int isSafe(int v, int graph[V][V], int colored[], int c)
{
    int i;
    for (i = 0; i < V; i++)
        if (graph[v][i] && c == colored[i])
            return 0;
    return 1;
}

/* The recursive function to solve graph coloring problem */
int graphColoringUtil(int graph[V][V], int m, int colored[], int v)
{
    int c;
    if (v == V)
        return 1;
    for (c = 1; c <= m; c++)
    {
        if (isSafe(v, graph, colored, c))
        {
           colored[v] = c;
           if (graphColoringUtil(graph, m, colored, v+1) == 1)
             return 1;
           colored[v] = 0;
        }
    }
    return 0;
}

/* This function prints the assigned colors */
void printSolution(int colored[])
{
    int i;
    printf("Vertex\tColor\n");
    for (i = 0; i < V; i++)
        printf("%d\t%d\n", i+1, colored[i]);
}

/* This function solves the color problem using Backtracking */
void graphColoring(int graph[V][V], int m)
{
    int colored[V];
    int i;
    for (i = 0; i < V; i++)
        colored[i] = 0;
    if (graphColoringUtil(graph, m, colored, 0) == 0)
    {
        printf("Solution does not exist");
        return;
    }
    // Print the solution
    printSolution(colored);
}

int main()
{
    int graph[V][V] = {{0, 1, 1, 1},
                       {1, 0, 1, 0},
                       {1, 1, 0, 1},
                       {1, 0, 1, 0},};
    int m = 3; // Number of colors
    graphColoring(graph, m);
    return 0;
}