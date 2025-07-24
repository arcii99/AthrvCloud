//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: irregular
#include <stdio.h>

// function to check if a vertex is coloring safe
int isSafe(int vertex, int color, int graph[][5], int colors[])
{   
    for (int i = 0; i < 5; i++)
        if (graph[vertex][i] && color == colors[i])
            return 0;
    
    return 1;
}

// function to find vertex coloring
int graphColoring(int vertex, int graph[][5], int numColors, int colors[])
{
    if (vertex == 5)
        return 1;
    
    for (int i = 1; i <= numColors; i++)
    {
        if (isSafe(vertex, i, graph, colors))
        {
            colors[vertex] = i;
            if (graphColoring(vertex + 1, graph, numColors, colors))
                return 1;
            colors[vertex] = 0;
        }
    }
    
    return 0;
}

int main()
{
    int graph[5][5] = {{0, 1, 1, 0, 1}, {1, 0, 1, 0, 0}, {1, 1, 0, 1, 0}, {0, 0, 1, 0, 1}, {1, 0, 0, 1, 0}};
    int numColors = 3;
    int colors[5] = {0};
    
    if (graphColoring(0, graph, numColors, colors)) {
        printf("A valid coloring based on %d colors is: \n", numColors);
        for (int i = 0; i < 5; i++)
            printf("Vertex %d is colored with %d\n", i+1, colors[i]);
    }
    else {
        printf("No valid coloring based on %d colors found!\n", numColors);
    }
    
    return 0;
}