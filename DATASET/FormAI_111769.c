//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NODE_COUNT 5

int graph[NODE_COUNT][NODE_COUNT] = {
    {0, 1, 1, 0, 1},
    {1, 0, 1, 0, 1},
    {1, 1, 0, 1, 1},
    {0, 0, 1, 0, 1},
    {1, 1, 1, 1, 0}
};

int colors[NODE_COUNT];

bool isSafe(int v, int c)
{
    for (int i = 0; i < NODE_COUNT; i++)
    {
        if (graph[v][i] && c == colors[i])
            return false;
    }
    return true;
}

bool graphColoring(int v)
{
    if (v == NODE_COUNT)
        return true;

    for (int c = 1; c <= 3; c++)
    {
        if (isSafe(v, c))
        {
            colors[v] = c;
            if (graphColoring(v + 1))
                return true;

            colors[v] = 0;
        }
    }

    return false;
}

void printSolution()
{
    printf("Solution:\n");
    for (int i = 0; i < NODE_COUNT; i++)
    {
        printf("Node %d: Color %d\n", i, colors[i]);
    }
}

int main()
{
    if (graphColoring(0))
        printSolution();
    else
        printf("No solution exists.\n");

    return 0;
}