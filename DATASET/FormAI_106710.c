//FormAI DATASET v1.0 Category: Graph representation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// this is a function to print the graph
void printGraph(char **graph, int size) {
    printf("\n Graph:\n");
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            printf("%c ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // initialize an array to represent the graph
    char **graph;
    int size = 5;
    graph = (char **)malloc(size * sizeof(char *));
    for(int i=0; i<size; i++) {
        graph[i] = (char *)malloc(size * sizeof(char));
    }
    
    // populate the graph with nodes and edges
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            if(i == j) {
                graph[i][j] = 'O';
            } else if(i < j) {
                graph[i][j] = '-';
            } else {
                graph[i][j] = '|';
            }
        }
    }
    
    // print the graph
    printGraph(graph, size);
    
    // free the memory allocated for the graph
    for(int i=0; i<size; i++) {
        free(graph[i]);
    }
    free(graph);
    
    return 0;
}