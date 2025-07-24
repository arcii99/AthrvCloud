//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>

// function to check if assigning a color to vertex v is safe or not
int isSafe(int graph[5][5], int color[5], int v, int e, int c)
{
    for(int i=0; i<e; i++)
    {
        if(graph[v][i] && c == color[i])
            return 0;
    }
    return 1;
}

// function to print the colored graph
void printColor(int color[5], int e)
{
    printf("Vertex Colors: \n");
    for(int i=0; i<e; i++)
    {
        printf("Vertex %d --> Color %d\n", i, color[i]);
    }
}

// function to solve the graph coloring problem recursively
int graphColor(int graph[5][5], int color[5], int v, int e, int colors)
{
    if(v == e)              // base case: all vertices are assigned a color
        return 1;
    
    for(int c=1; c<=colors; c++)
    {
        if(isSafe(graph, color, v, e, c))    // check if assigning color c to vertex v is safe
        {
            color[v] = c;           // assign color c to vertex v
            
            // recur for all vertices
            if(graphColor(graph, color, v+1, e, colors))
                return 1;
                
            color[v] = 0;           // backtrack step: undo the assigned color if it didn't work out
        }
    }
    return 0;       // no color can be assigned to this vertex
}

// main function
int main()
{
    int graph[5][5] = {   {0, 1, 1, 0, 1},
                          {1, 0, 1, 1, 0},
                          {1, 1, 0, 1, 1},
                          {0, 1, 1, 0, 1},
                          {1, 0, 1, 1, 0} };
    
    int color[5] = {0};     // array to store colors assigned to each vertex
    
    int e = 5;          // number of vertices
    int colors = 3;     // number of colors
    
    if(graphColor(graph, color, 0, e, colors))
    {
        printf("Solution Exists...\n");
        printColor(color, e);
    }
    else
    {
        printf("Solution Does Not Exist....\n");
    }
    return 0;
}