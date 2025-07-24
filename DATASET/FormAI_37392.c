//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Cyberpunk
#include<stdio.h> 
  
//define the maximum number of vertices
#define MAX_VERTICES 20
  
//Function to check whether it is safe to color the vertex with given color 
int isSafe(int graph[MAX_VERTICES][MAX_VERTICES], int color[], int v, int c) 
{ 
    for (int i = 0; i < MAX_VERTICES; i++) 
        if (graph[v][i] && c == color[i]) 
            return 0; 
    return 1; 
} 
  
//function to assign colors recursively
int graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int m, int color[], int v) 
{ 
    if (v == MAX_VERTICES) 
        return 1; 
  
    for (int c = 1; c <= m; c++) 
    { 
        if (isSafe(graph, color, v, c)) 
        { 
           color[v] = c;
           if (graphColoringUtil(graph, m, color, v+1) == 1) 
             return 1; 
  
           color[v] = 0; 
        } 
    } 
    return 0; 
} 
  
//function to print the colors assigned to the vertices 
void printSolution(int color[]) 
{ 
    printf("Vertex Colors: \n"); 
    for (int i = 0; i < MAX_VERTICES; i++) 
        printf("%d ", color[i]); 
    printf("\n"); 
} 
  
//function to solve the Graph Coloring Problem
void graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int m) 
{ 
    int color[MAX_VERTICES];
    for (int i = 0; i < MAX_VERTICES; i++) 
        color[i] = 0; 
    
    if (graphColoringUtil(graph, m, color, 0) == 0) 
        printf("Solution does not exist"); 
    else
        printSolution(color); 
} 
  
int main() 
{ 
    int graph[MAX_VERTICES][MAX_VERTICES] = {{0, 1, 1, 1, 0}, 
                    {1, 0, 1, 0, 1}, 
                    {1, 1, 0, 1, 0}, 
                    {1, 0, 1, 0, 1},
                    {0, 1, 0, 1, 0}}; 
    int m = 3; //number of colors available 
    graphColoring(graph, m); 
    return 0; 
}