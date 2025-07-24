//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Cryptic
#include<stdio.h>
#include<stdbool.h>

#define V 4 // number of vertices

void printSolution(int color[]); // print solution

bool isSafe(int v, bool graph[V][V], 
            int color[], int c) // check if color c can be assigned to vertex v
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool graphColoringUtil(bool graph[V][V], int m, 
                       int color[], int v) // recursive function that solves the problem
{
    if (v == V)
        return true;
  
    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, graph, color, c))
        {
            color[v] = c;
            
            if (graphColoringUtil(graph, m, 
                                  color, v+1) == true)
                return true;
            
            color[v] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[V][V], int m) // main function for graph coloring
{
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;
      
    if (graphColoringUtil(graph, m, color, 0) == false)
    {
        printf("Solution does not exist");
        return false;
    }
  
    printSolution(color);
    return true;
}

void printSolution(int color[]) // print solution
{
    printf("Solution exists. The colors assigned are:\n");
    for (int i = 0; i < V; i++)
      printf(" %d ", color[i]);
    printf("\n");
}

int main() // driver program
{
    bool graph[V][V] = {{0, 1, 1, 1},
                        {1, 0, 1, 0},
                        {1, 1, 0, 1},
                        {1, 0, 1, 0}};
    int m = 3; // number of colors available
    graphColoring(graph, m);
    return 0;
}