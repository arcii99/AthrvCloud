//FormAI DATASET v1.0 Category: Graph representation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VERTICES 5 // number of vertices
#define EDGES 8 // number of edges

int main()
{
    int graph[VERTICES][VERTICES] = {0}; //initialize empty graph
    int i, j, count = 0; //loop counters and edge count

    //randomly generate edges between vertices
    srand(time(NULL));
    while (count < EDGES)
    {
        int start = rand() % VERTICES;
        int end = rand() % VERTICES;

        //check if edge already exists or if vertices are the same
        if (graph[start][end] != 1 && start != end)
        {
            graph[start][end] = 1;
            graph[end][start] = 1; //graph is undirected
            count++;
        }
    }

    //print graph representation
    printf("Graph Representation:\n");

    //print column headers
    printf("\n   ");
    for (i = 0; i < VERTICES; i++)
    {
        printf("%d ", i);
    }
    printf("\n");

    //print rows
    for (i = 0; i < VERTICES; i++)
    {
        printf("%d: ", i);
        for (j = 0; j < VERTICES; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}