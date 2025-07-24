//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define NO_OF_VERTICES 5

int graph[NO_OF_VERTICES][NO_OF_VERTICES] = { {0, 1, 1, 0, 0},
                                            {1, 0, 1, 1, 1},
                                            {1, 1, 0, 1, 0},
                                            {0, 1, 1, 0, 1},
                                            {0, 1, 0, 1, 0} };

int color[NO_OF_VERTICES];

bool isSafe(int vertex, int currentColor) {
    for(int i = 0; i < NO_OF_VERTICES; i++) {
        if(graph[vertex][i] == 1 && currentColor == color[i])
            return false;
    }
    return true;
}

bool graphColor(int vertex) {
    if(vertex == NO_OF_VERTICES) 
        return true;
    for(int i = 1; i <= NO_OF_VERTICES; i++) {
        if(isSafe(vertex, i)) {
            color[vertex] = i;
            if(graphColor(vertex+1) == true)
                return true;
            color[vertex] = 0;
        }
    }
    return false;
}

int main() {
    if(graphColor(0) == true) {
        printf("Coloring successful\n");
        for(int i = 0; i < NO_OF_VERTICES; i++)
            printf("Vertex %d --> Color %d\n", i+1, color[i]);
    }
    else
        printf("Coloring not possible");
    return 0;
}