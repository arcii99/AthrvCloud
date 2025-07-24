//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: distributed
#include<stdio.h>  
#include<stdlib.h>  
#define V 5  // The number of vertices in the graph  

int graph[V][V] = {{0, 1, 0, 1, 0}, // A adjacency matrix as input
                   {1, 0, 1, 1, 1},  
                   {0, 1, 0, 1, 0},  
                   {1, 1, 1, 0, 1},  
                   {0, 1, 0, 1, 0}};  

void printSolution(int color[]) {  // function to print the color assignment of each vertex
    printf("Vertex \t Color\n");  
    for (int i = 0; i < V; i++)  
        printf(" %d \t\t %d\n", i, color[i]);  
}  

int isSafe(int v, int color[], int c) {  // function to check if the color c is safe for the vertex v or not
    for (int i = 0; i < V; i++)  
        if (graph[v][i] && c == color[i])  
            return 0;  
    return 1;  
}  

int graphColoring(int m, int color[], int v) {  // function to assign colors recursively to each vertex
    if (v == V)  // if all vertices are assigned colors, return true
        return 1;  
    for (int c = 1; c <= m; c++) {  
        if (isSafe(v, color, c)) {  // check if color c is safe for vertex v
            color[v] = c;  // assign color c to vertex v
            if (graphColoring(m, color, v+1) == 1)  // recur for the next vertex
                return 1;  
            color[v] = 0;  // backtracking
        }  
    }  
    return 0;  
}  

int main() {  
    int m = 3; // The number of colors to be used  
    int color[V]; // Assign initial colors as 0  
    for (int i = 0; i < V; i++)  
        color[i] = 0;  
    if (graphColoring(m, color, 0) == 0) {  // print the solution if possible, else print error message
        printf("Solution does not exist");  
    } else {
        printf("Solution Exists: Following are the assigned colors:");  
        printSolution(color);  
    }  
    return 0;  
}