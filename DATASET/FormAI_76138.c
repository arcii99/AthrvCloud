//FormAI DATASET v1.0 Category: Graph representation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES];
int vertexCount = 0;

void addVertex() {
    if (vertexCount < MAX_VERTICES) {
        graph[vertexCount][vertexCount] = 0;
        vertexCount++;
    }
    else {
        printf("Sorry, can't add another vertex!");
    }
}

void addEdge(int source, int destination) {
    if (source >= 0 && source < vertexCount && destination >= 0 && destination < vertexCount) {
        graph[source][destination] = 1;
        graph[destination][source] = 1;
    }
    else {
        printf("Invalid edge!\n");
    }
}

void printGraph() {
    int i, j;
    for (i = 0; i < vertexCount; i++) {
        for (j = 0; j < vertexCount; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Welcome to my Happy Graph Example Program!\n");
    printf("Let's add some vertices to our graph!\n");

    addVertex();
    addVertex();
    addVertex();

    printf("Our graph looks like this:\n");
    printGraph();

    printf("Now let's add some edges:\n");

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 3);

    printf("Our updated graph looks like this:\n");
    printGraph();

    printf("Yay! Our Happy Graph Example Program is complete!\n");

    return 0;
}