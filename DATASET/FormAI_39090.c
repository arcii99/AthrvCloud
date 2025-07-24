//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: romantic
#include<stdio.h>
#include<stdlib.h>

#define V 4

int graph[V][V] = { {0, 1, 1, 1},
		    {1, 0, 1, 0},
		    {1, 1, 0, 1},
		    {1, 0, 1, 0},
		  };

void printSolution(int color[])
{
    printf("Vertex \t Color\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i+1, color[i]);

}

int isValid(int v, int color[], int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return 0;
    return 1;
}

int graphColoringUtil(int m, int color[], int v)
{
    if (v == V)
        return 1;

    for (int c = 1; c <= m; c++)
    {
        if (isValid(v, color, c))
        {
           color[v] = c;

           if (graphColoringUtil(m, color, v+1) == 1)
             return 1;

           color[v] = 0;
        }
    }
    return 0;
}

int graphColoring(int m)
{
    int color[V];
    for (int i = 0; i < V; i++)
       color[i] = 0;

    if (graphColoringUtil(m, color, 0) == 0)
    {
        printf("Solution does not exist");
        return 0;
    }

    printSolution(color);
    return 1;
}

int main()
{
    int m = 3;

    printf("The Graph Coloring Problem Solution is:\n");
    graphColoring(m);

    return 0;
}