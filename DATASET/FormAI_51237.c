//FormAI DATASET v1.0 Category: Graph representation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 10
#define MIN_WEIGHT 1
#define MAX_WEIGHT 100

int graph[MAX_NODES][MAX_NODES];

void initGraph() {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < MAX_NODES; i++) {
        for (j = 0; j < MAX_NODES; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                int weight = rand() % (MAX_WEIGHT - MIN_WEIGHT + 1) + MIN_WEIGHT;
                graph[i][j] = weight;
                graph[j][i] = weight;
            }
        }
    }
}

void printGraph() {
    printf("\nGraph Representation:\n\n");
    int i, j;
    for (i = 0; i < MAX_NODES; i++) {
        for (j = 0; j < MAX_NODES; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void printStats() {
    int totalEdges = 0;
    int totalWeight = 0;
    int i, j;
    for (i = 0; i < MAX_NODES; i++) {
        for (j = i + 1; j < MAX_NODES; j++) {
            if (graph[i][j] > 0) {
                totalEdges++;
                totalWeight += graph[i][j];
            }
        }
    }
    float avgWeight = (float) totalWeight / totalEdges;
    printf("\nGraph Statistics:\n\n");
    printf("- Total Nodes: %d\n", MAX_NODES);
    printf("- Total Edges: %d\n", totalEdges);
    printf("- Total Weight: %d\n", totalWeight);
    printf("- Average Weight: %.2f\n\n", avgWeight);
}

int main() {
    initGraph();
    printGraph();
    printStats();
    return 0;
}