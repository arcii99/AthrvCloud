//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Defining the maximum number of vertices and colors
#define MAX_VERTEX 1000
#define MAX_COLOR 100

int main(){

    // Initializing the arrays for adjacency matrix and vertex colors
    int adj[MAX_VERTEX][MAX_VERTEX], colors[MAX_VERTEX];

    // Initializing the variables for number of vertices and edges
    int n, m;

    // Taking input for number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    // Taking input for edges
    for(int i=0; i<m; i++){
        int u, v;
        printf("Enter edge %d: ", i+1);
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }

    // Initializing all vertex colors to 0
    for(int i=0; i<n; i++){
        colors[i] = 0;
    }

    // Function to check if the given color is valid for the given vertex
    bool is_valid(int vertex, int color){
        for(int i=0; i<n; i++){
            if(adj[vertex][i] && colors[i] == color){
                return false;
            }
        }
        return true;
    }

    // Function to recursively assign colors to the vertices
    void graph_color(int vertex){
        if(vertex == n){
            // If all vertices have been assigned colors, print the solution
            for(int i=0; i<n; i++){
                printf("%d ", colors[i]);
            }
            exit(0);
        }
        // Iterate through all colors for the current vertex
        for(int i=1; i<=MAX_COLOR; i++){
            // Check if the color is valid for the current vertex
            if(is_valid(vertex, i)){
                colors[vertex] = i;
                graph_color(vertex+1);
                // Backtrack if no colors are valid for the current vertex
                colors[vertex] = 0;
            }
        }
    }

    printf("The solution is: ");
    graph_color(0);

    return 0;
}