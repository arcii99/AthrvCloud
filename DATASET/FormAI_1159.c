//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_COLOR 4                             // maximum color available
#define ROW 5                                   // number of rows or vertices
#define COLUMN 5                                // number of columns or vertices

int graph[ROW][COLUMN] = {                      // given graph in the form of a matrix
    { 0, 1, 0, 1, 1 },
    { 1, 0, 1, 1, 0 },
    { 0, 1, 0, 1, 0 },
    { 1, 1, 1, 0, 1 },
    { 1, 0, 0, 1, 0 }
};

bool isSafe(int vertex, int color, int colorSet[]) {  // function to check if the color is safe to apply
    for(int i = 0; i < ROW; i++) {
        if(graph[vertex][i] && colorSet[i] == color) {  // check if adjacent vertices have same color
            return false;
        }
    }
    return true;   // if no adjacent vertices have same color then return true
}

bool graphColoring(int vertex, int colorSet[]) {   // main recursive function for Graph Coloring
    if(vertex == ROW) {      // if all vertices are colored then exit the function
        return true;
    }
    for(int c = 1; c <= MAX_COLOR; c++) {      // for each color
        if(isSafe(vertex, c, colorSet)) {     // check if the color is safe for this vertex
            colorSet[vertex] = c;             // assign the color to this vertex
            if(graphColoring(vertex + 1, colorSet)) {   // recursively assign color to next vertices
                return true;
            }
            colorSet[vertex] = 0;          // if the assigned color is not correct then remove it and try again
        }
    }
    return false;   // if no color is safe for this vertex then return false
}

int main() {
    int colorSet[ROW] = {0};      // colorset for each vertex
    if(graphColoring(0, colorSet)) {      // if all vertices are successfully colored
        printf("The graph can be colored with %d colors\n", MAX_COLOR);
        for(int i = 0; i < ROW; i++) {
            printf("Vertex %d has color %d\n", i+1, colorSet[i]);  // print the colored vertices
        }
    }
    else {    // if it is not possible to color all vertices
        printf("The graph cannot be colored with the given colors!");
    }
    return 0;
}