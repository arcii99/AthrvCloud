//FormAI DATASET v1.0 Category: Graph representation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 10

int graph[MAX_NODES][MAX_NODES];
int nodes = 0;

void add_edge(int source, int destination)
{
    graph[source][destination] = 1;
    graph[destination][source] = 1;
}

void remove_edge(int source, int destination)
{
    graph[source][destination] = 0;
    graph[destination][source] = 0;
}

void print_graph()
{
    int i, j;
    printf("\nGraph Representation:\n\n");
    printf("\t");
    for(i = 0; i < nodes; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for(i = 0; i < nodes; i++)
    {
        printf("%d\t", i);
        for(j = 0; j < nodes; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void build_graph(int num_nodes, float edge_density)
{
    int i, j;
    nodes = num_nodes;
    srand(time(NULL));
    for(i = 0; i < nodes; i++)
    {
        for(j = i+1; j < nodes; j++)
        {
            if((float)rand()/(float)(RAND_MAX/1.0) <= edge_density)
            {
                add_edge(i, j);
            }
        }
    }
}

int main()
{
    build_graph(5, 0.5);
    print_graph();
    remove_edge(2, 4);
    print_graph();
    return 0;
}