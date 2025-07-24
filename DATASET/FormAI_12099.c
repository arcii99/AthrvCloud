//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define VERTICES 5

bool isSafe(int graph[VERTICES][VERTICES], int colors[VERTICES], int vertex, int color){
    for(int i=0;i<VERTICES;i++){
        if(graph[vertex][i] && colors[i] == color){
            return false;
        }
    }
    return true;
}

bool graphColoring(int graph[VERTICES][VERTICES], int colors[VERTICES], int vertex){
    if(vertex == VERTICES){
        return true;
    }
    for(int color=1;color<=VERTICES;color++){
        if(isSafe(graph, colors, vertex, color)){
            colors[vertex] = color;
            if(graphColoring(graph, colors, vertex+1)){
                return true;
            }
            colors[vertex] = 0;
        }
    }
    return false;
}

void printColors(int colors[VERTICES]){
    printf("The colors assigned to the vertices are:\n");
    for(int i=0;i<VERTICES;i++){
        printf("Vertex %d: Color %d\n", i+1, colors[i]);
    }
}

int main(){
    int graph[VERTICES][VERTICES] = {{0,1,1,1,0},
                                      {1,0,1,0,1},
                                      {1,1,0,1,1},
                                      {1,0,1,0,1},
                                      {0,1,1,1,0}};
    int colors[VERTICES] = {0};
    if(graphColoring(graph, colors, 0)){
        printColors(colors);
    }
    else{
        printf("Graph cannot be colored with %d colors.\n", VERTICES);
    }
    return 0;
}