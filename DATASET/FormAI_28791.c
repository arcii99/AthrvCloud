//FormAI DATASET v1.0 Category: Graph representation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define V 10 // Number of vertices in the graph

// Generate a random graph
void generateGraph(int graph[][V]) {
    srand(time(NULL));
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(i == j) {
                graph[i][j] = 0;
            }
            else {
                graph[i][j] = rand() % 2;
            }
        }
    }
}

// Display the graph using a Donald Knuth-style graph representation
void displayGraph(int graph[][V]) {
    printf("    ");
    for(int i = 0; i < V; i++) {
        printf("%c ", 'A' + i);
    }
    printf("\n    ");
    for(int i = 0; i < V; i++) {
        printf("- ");
    }
    printf("\n");
    for(int i = 0; i < V; i++) {
        printf("%c | ", 'A' + i);
        for(int j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V];
    generateGraph(graph);
    displayGraph(graph);

    return 0;
}