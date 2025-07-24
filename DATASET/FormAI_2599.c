//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define V 10 // Total number of vertices

int graph[V][V]; // Graph adjacency matrix

// Function to check if a vertex can be assigned a certain color 'c'
bool canColor(int vertex, int color, int colorArr[])
{
    for(int i = 0; i < V; i++)
        if(graph[vertex][i] && colorArr[i] == color)
            return false; // If any adjacent vertex is already colored with the same color, return false
    
    return true;
}

// Function to recursively explore all possible coloring combinations of the vertices
bool colorizeGraph(int vertex, int colorArr[], int m)
{
    // Base case: if all vertices are colored, return true
    if(vertex == V)
        return true;
    
    // Try all m colors on the current vertex
    for(int i = 1; i <= m; i++)
    {
        // Check if current color is valid for the current vertex
        if(canColor(vertex, i, colorArr))
        {
            // Assign the color and recursively call the function for the next vertex
            colorArr[vertex] = i;
            
            if(colorizeGraph(vertex + 1, colorArr, m))
                return true;
            
            // Backtrack and try a different color
            colorArr[vertex] = 0;
        }
    }
    
    // If no color can be assigned to the current vertex, return false
    return false;
}

int main()
{
    // Initialize the graph adjacency matrix
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            graph[i][j] = 0;
    
    // Add some edges to the graph
    graph[0][1] = graph[0][4] = graph[1][0] = graph[1][4] = graph[1][2] = graph[1][3] = graph[2][1] = graph[2][3] = graph[3][1] = graph[3][2] = graph[3][4] = graph[4][0] = graph[4][1] = graph[4][3] = graph[4][5] = graph[4][6] = graph[5][4] = graph[5][6] = graph[6][4] = graph[6][5] = graph[7][8] = graph[7][9] = graph[8][7] = graph[8][9] = graph[9][7] = graph[9][8] = 1;
    
    
    int m = 3; // Total number of colors available
    
    int colorArr[V]; // An array to store the colors assigned to each vertex
    
    // Initialize all colors to 0, indicating no color assigned yet
    for(int i = 0; i < V; i++)
        colorArr[i] = 0;
    
    // Call the function to colorize the graph starting from vertex 0
    if(colorizeGraph(0, colorArr, m))
    {
        printf("Graph can be colored with %d colors as shown below:\n", m);
        
        // Print the final color assignment for each vertex
        for(int i = 0; i < V; i++)
            printf("Vertex %d => Color %d\n", i, colorArr[i]);
    }
    else
        printf("Graph cannot be colored with %d colors.\n", m);
    
    return 0;
}