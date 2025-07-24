//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define V 5 // maximum number of vertices in the graph

// Function to check if it is safe to assign the color to vertex v
bool isSafe(int vertex, int graph[V][V], int color[],
           int c)
{
    for (int i = 0; i < V; i++)
        if (graph[vertex][i] && c == color[i])
            return false;
    return true;
}
 
// Function to assign colors to all vertices
bool graphColoringUtil(int graph[V][V], int m, int color[],
                    int vertex)
{
    if (vertex == V)
        return true;
 
    for (int c = 1; c <= m; c++)
    {
        if (isSafe(vertex, graph, color, c))
        {
           color[vertex] = c;
 
           if (graphColoringUtil(graph, m, color, vertex + 1))
             return true;
 
           color[vertex] = 0;
        }
    }
 
    return false;
}
 
// Wrapper function for graphColoringUtil()
bool graphColoring(int graph[V][V], int m)
{
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;
 
    if (!graphColoringUtil(graph, m, color, 0))
        return false;
 
    // Printing the assigned colors
    printf("The assigned colors are as follows:\n");
    for (int i = 0; i < V; i++)
      printf("Vertex %d: Color %d\n", i, color[i]);
 
    return true;
}
 
// Main function
int main()
{
    int graph[V][V];
    for(int i = 0;i < V;i++){
        for(int j = 0;j < V;j++){
            graph[i][j] = 0;
        }
    }

    // Creating a sample graph
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

    int m = 3; // Number of colors
    
    if (graphColoring(graph, m))
        printf("The graph can be colored using %d colors", m);
    else
        printf("The graph cannot be colored using %d colors", m);
 
    return 0;
}