//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: interoperable
#include<stdio.h>

#define V 4     //Number of vertices in the graph

/* This function assigns colors to all the vertices in a graph such that no two adjacent vertices have the same color using Backtracking approach. */
void graphColoring(int graph[V][V], int m, int color[], int v)
{
    /* If all vertices are assigned a color then return true */
    if (v == V)
    {
        /* Printing the solution */
        printf("Graph Coloring: ");
        for (int i = 0; i < V; i++)
        {
            printf("%d ", color[i]);
        }
        printf("\n");
        return;
    }

    /* Consider this vertex v and try different colors */
    for (int c = 1; c <= m; c++)
    {
        /* Check if assignment of color c to v is valid */
        int isValid = 1;
        for (int i = 0; i < V; i++)
        {
            if (graph[v][i] && color[i] == c)
            {
                isValid = 0;
            }
        }

        /* If assignment of color c to v is valid */
        if (isValid)
        {
            /* Assign color c to v */
            color[v] = c;

            /* Recur to assign colors to rest of the vertices */
            graphColoring(graph, m, color, v+1);

            /* If the rest of the vertices can not be assigned colors, then remove this color and try another one */
            color[v] = 0;
        }
    }
}

int main()
{
    /* Create a graph with adjacency matrix */
    int graph[V][V] = {{0, 1, 1, 1},
                       {1, 0, 1, 0},
                       {1, 1, 0, 1},
                       {1, 0, 1, 0}};

    /* Number of colors */
    int m = 3;

    /* Initialize all vertex colors as 0 */
    int color[V] = {0};

    /* Call graph coloring function */
    graphColoring(graph, m, color, 0);

    return 0;
}