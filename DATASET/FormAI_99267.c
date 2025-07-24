//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100   // maximum number of vertices
#define MAX_COLORS 10      // maximum number of colors

int graph[MAX_VERTICES][MAX_VERTICES];   // adjacency matrix representation of the graph
int V;   // number of vertices

// function to check if a given color c is safe for vertex v
bool is_safe(int v, int color, int* color_assignment) {
    // check for all adjacent vertices
    for(int i=0; i<V; i++) {
        if(graph[v][i] && color_assignment[i] == color) {
            return false;
        }
    }
    // if color is safe, return true
    return true;
}

// function to solve graph coloring problem using backtracking algorithm
bool graph_coloring_util(int* color_assignment, int vertex_index, int num_colors) {
    // if all vertices are assigned a color, return true
    if(vertex_index == V) {
        return true;
    }
    // try different colors for the current vertex
    for(int i=1; i<=num_colors; i++) {
        // check if color is safe
        if(is_safe(vertex_index, i, color_assignment)) {
            // assign the color and move to next vertex
            color_assignment[vertex_index] = i;
            if(graph_coloring_util(color_assignment, vertex_index+1, num_colors)) {
                return true;
            }
            // if color assignment does not lead to solution, backtrack and try different color
            color_assignment[vertex_index] = 0;
        }
    }
    // if all colors are tried and none of them are safe, return false
    return false;
}

// function to solve graph coloring problem using backtracking algorithm
void graph_coloring(int num_colors) {
    int color_assignment[MAX_VERTICES] = {0};   // array to store assigned colors for each vertex
    if(graph_coloring_util(color_assignment, 0, num_colors)) {
        // if solution exists, print the vertex-color pairs
        printf("Vertex-Color Assignments:\n");
        for(int i=0; i<V; i++) {
            printf("Vertex %d: Color %d\n", i, color_assignment[i]);
        }
    } else {
        printf("Solution does not exist with given number of colors.\n");
    }
}

int main() {
    // initialize the graph
    printf("Initializing the graph...\n");
    for(int i=0; i<MAX_VERTICES; i++) {
        for(int j=0; j<MAX_VERTICES; j++) {
            graph[i][j] = 0;
        }
    }
    // add edges to the graph
    printf("Adding edges to the graph...\n");
    V = 7;
    graph[0][1] = 1;
    graph[1][0] = 1;
    graph[0][2] = 1;
    graph[2][0] = 1;
    graph[1][2] = 1;
    graph[2][1] = 1;
    graph[1][3] = 1;
    graph[3][1] = 1;
    graph[2][4] = 1;
    graph[4][2] = 1;
    graph[3][4] = 1;
    graph[4][3] = 1;
    graph[5][6] = 1;
    graph[6][5] = 1;
    // solve the graph coloring problem
    printf("Solving the graph coloring problem...\n");
    graph_coloring(3);
    // exit the program
    printf("Exiting the program...\n");
    return 0;
}