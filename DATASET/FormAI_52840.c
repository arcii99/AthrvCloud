//FormAI DATASET v1.0 Category: Graph representation ; Style: intelligent
// Intelligent C Graph representation example program
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of vertices and edges
#define MAX_VERTICES 10
#define MAX_EDGES 20

// Define the adjacency matrix
int adj_matrix[MAX_VERTICES][MAX_VERTICES];

// Function to initialize the adjacency matrix
void init_adj_matrix()
{
    int i, j;
    for (i = 0; i < MAX_VERTICES; i++)
    {
        for (j = 0; j < MAX_VERTICES; j++)
        {
            adj_matrix[i][j] = 0;
        }
    }
}

// Function to add an edge to the adjacency matrix
void add_edge(int u, int v)
{
    adj_matrix[u][v] = 1;
    adj_matrix[v][u] = 1;
}

// Function to print the adjacency matrix
void print_adj_matrix()
{
    int i, j;
    for (i = 0; i < MAX_VERTICES; i++)
    {
        for (j = 0; j < MAX_VERTICES; j++)
        {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // Initialize the adjacency matrix
    init_adj_matrix();

    // Add some edges to the graph
    add_edge(0, 1);
    add_edge(1, 2);
    add_edge(2, 3);
    add_edge(3, 4);
    add_edge(4, 0);

    // Print the adjacency matrix
    printf("Adjacency Matrix:\n");
    print_adj_matrix();

    return 0;
}