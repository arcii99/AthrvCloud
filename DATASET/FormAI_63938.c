//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Function to check if the proposed coloring of the vertex is valid
int is_valid(int vertex, int color, int graph[][4], int coloring[])
{
    for (int i = 0; i < 4; i++)
    {
        if (graph[vertex][i] && coloring[i] == color)
        {
            return 0;
        }
    }
    return 1;
}

// Function to assign coloring to the vertices of the graph
int graph_coloring(int vertex, int graph[][4], int num_colors, int coloring[])
{
    if (vertex == 4)
    {
        // Base case: All vertices have been colored
        return 1;
    }

    for (int i = 1; i <= num_colors; i++)
    {
        if (is_valid(vertex, i, graph, coloring))
        {
            coloring[vertex] = i;
            if (graph_coloring(vertex + 1, graph, num_colors, coloring))
            {
                return 1;
            }
            coloring[vertex] = 0;
        }
    }
    return 0;
}

int main()
{
    printf("Welcome to the Graph Coloring Problem game!\n");
    printf("In this game, you will be given a graph with 4 vertices.\n");
    printf("You must assign a color to each vertex so that no two adjacent vertices have the same color.\n");
    printf("You may use up to 3 colors.\n");
    printf("Let's get started!\n\n");

    int graph[4][4] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int num_colors = 3;
    int coloring[4] = {0};

    if (graph_coloring(0, graph, num_colors, coloring))
    {
        printf("Congratulations, you have successfully colored the graph!\n");
        printf("The colors are as follows:\n");
        printf("Vertex 1: %d\n", coloring[0]);
        printf("Vertex 2: %d\n", coloring[1]);
        printf("Vertex 3: %d\n", coloring[2]);
        printf("Vertex 4: %d\n", coloring[3]);
    }
    else
    {
        printf("Oops, it looks like there is no valid coloring for this graph with the given number of colors.\n");
    }

    return 0;
}