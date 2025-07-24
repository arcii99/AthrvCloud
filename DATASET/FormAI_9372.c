//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Define the maximum number of vertices and colors
#define MAX_VERTICES 10
#define MAX_COLORS 3

// Define the adjacency matrix
int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];

// Define the vertex colors
int vertex_colors[MAX_VERTICES];

// Define the number of vertices
int num_vertices;

// Define the functions
void generate_graph();
void print_graph();
int is_colorable(int vertex, int color);
int color_graph(int vertex);

int main()
{
    // Initialize the random seed
    srand(time(NULL));

    // Generate the graph
    generate_graph();

    // Print the graph
    printf("Generated Graph:\n");
    print_graph();

    // Color the graph
    color_graph(0);

    // Print the colored graph
    printf("\nColored Graph:\n");
    print_graph();

    return 0;
}

// Function to generate the graph
void generate_graph()
{
    int i, j;

    // Generate a square adjacency matrix with random 0s and 1s
    for(i=0; i<MAX_VERTICES; i++)
    {
        for(j=0; j<MAX_VERTICES; j++)
        {
            if(i == j)
                adjacency_matrix[i][j] = 0; // No self-loops
            else
                adjacency_matrix[i][j] = rand() % 2; // Random 0 or 1
        }
    }

    // Randomly choose the number of vertices to use
    num_vertices = rand() % MAX_VERTICES + 1;

    // Set the rest of the vertices to 0
    for(i=num_vertices; i<MAX_VERTICES; i++)
    {
        for(j=0; j<MAX_VERTICES; j++)
        {
            adjacency_matrix[i][j] = 0;
            adjacency_matrix[j][i] = 0;
        }
    }
}

// Function to print the graph
void print_graph()
{
    int i, j;

    // Print the adjacency matrix
    for(i=0; i<num_vertices; i++)
    {
        for(j=0; j<num_vertices; j++)
        {
            printf("%d ", adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a vertex can be colored a certain color
int is_colorable(int vertex, int color)
{
    int i;

    // Check if any adjacent vertices have the same color
    for(i=0; i<num_vertices; i++)
    {
        if(adjacency_matrix[vertex][i] && vertex_colors[i] == color)
            return 0;
    }

    return 1;
}

// Function to color the graph
int color_graph(int vertex)
{
    int i, j;
    int color;

    // Check if all vertices have been colored
    if(vertex == num_vertices)
        return 1;

    // Try all possible colors for this vertex
    for(color=1; color<=MAX_COLORS; color++)
    {
        if(is_colorable(vertex, color))
        {
            vertex_colors[vertex] = color;

            // Recursively color the rest of the graph
            if(color_graph(vertex+1))
                return 1;

            vertex_colors[vertex] = 0;
        }
    }

    return 0;
}