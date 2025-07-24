//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 20
#define MAX_EDGES 100

typedef struct {
    int vertex;
    int color;
} Node;

int numNodes;
Node nodes[MAX_VERTICES];

int numEdges;
int edges[MAX_EDGES][2];

void createGraph();
void initializeNodes();
void initializeEdges();
void printGraph();
int findColor(int vertex);

int main() {
    srand(time(NULL));

    createGraph();
    initializeNodes();
    initializeEdges();
    printGraph();

    for (int i = 0; i < numNodes; i++) {
        int color = findColor(nodes[i].vertex);
        nodes[i].color = color;
    }

    printf("\nFinal graph with colors:\n");
    printGraph();

    return 0;
}

void createGraph() {
    printf("Creating graph...\n");
    numNodes = rand() % (MAX_VERTICES - 1) + 2;
    numEdges = rand() % ((numNodes * (numNodes - 1) / 2) + 1);

    printf("Number of nodes: %d\n", numNodes);
    printf("Number of edges: %d\n", numEdges);

    for (int i = 0; i < numEdges; i++) {
        edges[i][0] = rand() % numNodes;
        edges[i][1] = rand() % numNodes;
    }
}

void initializeNodes() {
    for (int i = 0; i < numNodes; i++) {
        nodes[i].vertex = i;
        nodes[i].color = -1;
    }
}

void initializeEdges() {
    for (int i = 0; i < numEdges; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        if (u != v) { // No self-loops
            for (int j = 0; j < 2; j++) {
                int temp = u;
                u = v;
                v = temp;

                int k = 0;
                while (k < i && (edges[k][0] != u || edges[k][1] != v)) {
                    k++;
                }

                if (k == i) {
                    edges[i][0] = u;
                    edges[i][1] = v;
                }
            }
        }
    }
}

void printGraph() {
    printf("Node\tColor\n");
    for (int i = 0; i < numNodes; i++) {
        printf("%d\t%d\n", nodes[i].vertex, nodes[i].color);
    }

    printf("Edges:\n");
    for (int i = 0; i < numEdges; i++) {
        printf("(%d, %d)\n", edges[i][0], edges[i][1]);
    }
}

int findColor(int vertex) {
    int usedColors[MAX_VERTICES] = { 0 };
    for (int i = 0; i < numEdges; i++) {
        if (edges[i][0] == vertex || edges[i][1] == vertex) {
            int neighbor = edges[i][0] == vertex ? edges[i][1] : edges[i][0];
            if (nodes[neighbor].color != -1) {
                usedColors[nodes[neighbor].color] = 1;
            }
        }
    }

    int color = 0;
    while (usedColors[color]) {
        color++;
    }

    return color;
}