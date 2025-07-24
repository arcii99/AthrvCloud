//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100 // maximum number of vertices
#define MAX_EDGES 100     // maximum number of edges

// Function to color vertices
void colorVertices(int graph[][MAX_VERTICES], int colors[], int vertexCount, int chromaticNumber)
{
    if(chromaticNumber > vertexCount) // Check if chromatic number is greater than total vertices
        printf("\nInvalid chromatic number for given vertices.\n");
    else
    {
        for(int i = 0; i < vertexCount; i++) // For each vertex, assign color
            colors[i] = 0;

        for(int i = 0; i < vertexCount; i++)
        {
            int j;
            for(j = 0; j < vertexCount; j++)
                if(graph[i][j] && colors[j] != 0) // If a vertex is adjacent to current vertex and already colored
                    break;

            if(j == vertexCount) // If no adjacent vertex has same color, assign current color
                colors[i] = 1;
            else
            {
                int available[MAX_VERTICES] = {0}; // Store colors available for current vertex

                for(int j = 0; j < vertexCount; j++)
                    if(graph[i][j] && colors[j] != 0) // If adjacent vertices are already colored, mark their colors as unavailable
                        available[colors[j] - 1] = 1; // Subtract 1 since array indexing starts from 0

                int k;
                for(k = 0; k < chromaticNumber; k++)
                    if(available[k] == 0) // Assign first available color to current vertex
                        break;

                if(k < chromaticNumber)
                    colors[i] = k + 1; // Add 1 since array indexing starts from 0
                else
                {
                    printf("\nInvalid chromatic number for given graph.\n"); // If no color is available for current vertex, chromatic number is not sufficient
                    return;
                }
            }
        }

        printf("\nColors assigned to vertices:\n");
        for(int i = 0; i < vertexCount; i++)
            printf("Vertex %d -> Color %d\n", i+1, colors[i]);
    }
}

// Function to add edge to graph
void addEdge(int graph[][MAX_VERTICES], int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;
}

int main()
{
    int graph[MAX_VERTICES][MAX_VERTICES] = {0}; // Initialize all values of graph matrix to 0
    int colors[MAX_VERTICES]; // Array to store colors assigned to vertices

    int vertexCount, edgeCount, chromaticNumber;

    printf("Enter number of vertices in graph: ");
    scanf("%d", &vertexCount);

    printf("Enter number of edges in graph: ");
    scanf("%d", &edgeCount);

    for(int i = 0; i < edgeCount; i++) // Add edges to graph
    {
        printf("Enter edge %d (u v): ", i+1);
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u-1, v-1); // Subtract 1 from vertices to adjust for array indexing starting from 0
    }

    printf("Enter chromatic number of graph: ");
    scanf("%d", &chromaticNumber);

    printf("\nGraph:\n");
    for(int i = 0; i < vertexCount; i++) // Display the graph
    {
        for(int j = 0; j < vertexCount; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }

    colorVertices(graph, colors, vertexCount, chromaticNumber); // Color vertices in graph

    return 0;
}