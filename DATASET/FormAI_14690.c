//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Cyberpunk
// Cyberpunk Style C Program for Graph Coloring Problem
#include<stdio.h>
#include<stdlib.h>

#define V 10 // Number of vertices

int graph[][V] = {     // Graph adjacency matrix
                    {0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
                    {1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
                    {1, 0, 0, 0, 1, 0, 1, 0, 0, 0},
                    {0, 0, 1, 1, 0, 1, 1, 0, 0, 0},
                    {0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
                    {0, 0, 0, 1, 1, 0, 0, 0, 0, 1},
                    {0, 1, 0, 0, 0, 1, 0, 0, 1, 0},
                    {0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
                    {0, 1, 0, 0, 0, 0, 1, 0, 1, 0}
                };
int colors[V];  // An array to store the color assigned to each vertex.

void printSolution()  // A function to print the color of each vertex
{
    printf("Vertex \t Color\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i+1, colors[i]);
}

int isSafe(int v, int c) // A boolean function to check if it is safe to assign color c to the vertex v
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == colors[i])
            return 0;
    return 1;
}

int graphColoring(int v) // A recursive function to assign colors to each vertex
{
    if (v == V) // If all vertices are assigned a color, then return 1
        return 1;

    for (int c = 1; c <= 4; c++) // Iterate through all possible colors
    {
        if (isSafe(v, c)) // Check if it is safe to assign color c to vertex v
        {
            colors[v] = c;
            if (graphColoring(v+1)) // Recursive call to assign color to the next vertex
                return 1;
            colors[v] = 0;
        }
    }
    return 0;
}

int main()
{
    printf("*** Welcome to Cyberpunk style Graph Coloring Problem ***\n\n");
    printf("The Cyberpunk city is divided into 10 districts. Each district is represented by a vertex in a graph.\n");
    printf("The goal is to color these 10 districts with 4 different colors, such that no two adjacent districts have the same color.\n\n");

    if (graphColoring(0))
        printSolution();
    else
        printf("Solution does not exist.");

    return 0;
}