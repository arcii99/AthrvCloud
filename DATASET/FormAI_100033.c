//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define V 7 //number of vertices

bool isSafe(int vertex, int graph[V][V], int color[], int c)
{
    for(int i=0; i<V; i++)
    {
        if(graph[vertex][i] && c==color[i])
            return false;
    }
    return true;
}

bool graphColoring(int graph[V][V], int m, int color[], int vertex)
{
    if(vertex == V)
        return true;
    for(int c=1; c<=m; c++)
    {
        if(isSafe(vertex, graph, color, c))
        {
            color[vertex] = c;
            if(graphColoring(graph, m, color, vertex+1))
                return true;
            color[vertex] = 0;
        }
    }
    return false;
}

int main()
{
    int graph[V][V] = {{0, 1, 0, 1, 0, 0, 0}, //irregular adjacency matrix
                       {1, 0, 1, 1, 0, 0, 0}, 
                       {0, 1, 0, 0, 1, 0, 1}, 
                       {1, 1, 0, 0, 1, 1, 0}, 
                       {0, 0, 1, 1, 0, 1, 0}, 
                       {0, 0, 0, 1, 1, 0, 1}, 
                       {0, 0, 1, 0, 0, 1, 0}}; 
    int m = 3; //number of colors
    int color[V];
    for(int i=0; i<V; i++)
        color[i] = 0;
    if(graphColoring(graph, m, color, 0))
    {
        printf("The vertex colors are: \n");
        for(int i=0; i<V; i++)
            printf("%d ", color[i]);
    }
    else
        printf("No solution exists");
    return 0;
}