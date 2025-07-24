//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: protected
#include <stdio.h>
#include <stdbool.h>

#define V 4

// Function to print the solution matrix 
void printSolution(int color[]) 
{ 
    printf("Solution Exists:"
           " Following are the assigned colors \n"); 
    for (int i = 0; i < V; i++) 
      printf(" %d ", color[i]); 
    printf("\n"); 
} 

// check if the adjacent vertices have the same color or not 
bool isSafe (int v,int graph[V][V],int color[],int c) 
{ 
    for (int i = 0; i < V; i++) 
        if (graph[v][i] && c == color[i]) 
            return false; 
    return true; 
} 

// backtrack for all possible combinations 
bool graphColoringUtil(int graph[V][V], int m, int color[], int v) 
{ 
    if (v == V) 
        return true; 

    //check for the adjacent vertices and try all possible combinations 
    for (int c = 1; c <= m; c++) 
    { 
        if (isSafe(v, graph, color, c)) 
        { 
           color[v] = c; 

           // backtrack for the next vertex 
           if (graphColoringUtil (graph, m, color, v+1) == true) 
             return true; 

           // if a solution is not found remove the color 
           color[v] = 0; 
        } 
    } 

    return false; 
} 

bool graphColoring(int graph[V][V], int m) 
{ 
    int color[V]; 
    for (int i = 0; i < V; i++) 
       color[i] = 0; 

    // check if the graph can be colored 
    if (graphColoringUtil(graph, m, color, 0) == false) 
      return false; 

    // print the solution matrix 
    printSolution(color); 
    return true; 
} 

int main() 
{ 
    int graph[V][V] = {{0, 1, 1, 1}, 
        {1, 0, 1, 0}, 
        {1, 1, 0, 1}, 
        {1, 0, 1, 0} 
    }; 
    int m = 3; // Number of colors 
    graphColoring(graph, m); 
    return 0; 
}