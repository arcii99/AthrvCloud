//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: cheerful
#include<stdio.h>
int main()
{
    // This is a cheerful C Graph Coloring Problem Example Program
    printf("Welcome to the cheerful C Graph Coloring Problem Example Program!\n");

    // Let's define the graph using an adjacency matrix
    int graph[5][5] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0},
        {1, 1, 1, 0, 1},
        {0, 0, 0, 1, 0}
    };

    // Let's initialize the color array to 0
    int color[5] = {0};

    // Let's start coloring the graph
    for(int i = 0; i < 5; i++)
    {
        // Let's find the available colors for vertex i
        int available[5] = {1, 1, 1, 1, 1};
        for(int j = 0; j < 5; j++)
        {
            if(graph[i][j] && color[j] != 0)
            {
                available[color[j] - 1] = 0;
            }
        }

        // Let's assign the minimum available color to vertex i
        for(int j = 0; j < 5; j++)
        {
            if(available[j])
            {
                color[i] = j + 1;
                break;
            }
        }
    }

    // Let's print the colors of the vertices
    printf("The colors of the vertices are:\n");
    for(int i = 0; i < 5; i++)
    {
        printf("Vertex %d: Color %d\n", i + 1, color[i]);
    }

    return 0;
}