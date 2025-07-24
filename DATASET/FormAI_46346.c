//FormAI DATASET v1.0 Category: Graph representation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_vertices, i, j;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &num_vertices);
    int** graph;
    graph = (int**) malloc(num_vertices * sizeof(int*)); // Dynamic allocation
    for(i=0; i<num_vertices; i++)
        graph[i] = (int*) malloc(num_vertices * sizeof(int));

    printf("\nEnter the adjacency matrix of the graph:\n");
    for(i=0; i<num_vertices; i++)
        for(j=0; j<num_vertices; j++)
            scanf("%d", &graph[i][j]);

    printf("\nThe graph representation in C is:\n");
    printf("int graph[%d][%d] = {", num_vertices, num_vertices);

    for(i=0; i<num_vertices; i++)
    {
        printf("{");
        for(j=0; j<num_vertices; j++)
        {
            printf("%d", graph[i][j]);
            if(j!=num_vertices-1)
                printf(",");
        }
        printf("}");
        if(i!=num_vertices-1)
            printf(",");
    }
    printf("};\n");

    // Free the memory
    for(i=0; i<num_vertices; i++)
        free(graph[i]);
    free(graph);

    return 0;
}