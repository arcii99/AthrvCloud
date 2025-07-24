//FormAI DATASET v1.0 Category: Graph representation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_VERTICES 20

typedef struct Edge {
    int src, dest, weight;
} Edge;

typedef struct Graph {
    int v_count, e_count;
    Edge edges[MAX_VERTICES * MAX_VERTICES];
} Graph;

Graph g;

bool isVertexVisited[MAX_VERTICES];

bool isEdgeVisited[MAX_VERTICES][MAX_VERTICES];

void addEdge(int src, int dest, int weight, int edge_index) {
    g.edges[edge_index].src = src;
    g.edges[edge_index].dest = dest;
    g.edges[edge_index].weight = weight;
}

void printGraph() {
    printf("Graph:\n");
    for (int i = 0; i < g.e_count; i++) {
        printf("(%d, %d, %d)\n", g.edges[i].src, g.edges[i].dest, g.edges[i].weight);
    }
}

int getRandomNumber(int max) {
    return rand() % max;
}

void generateRandomGraph(int v_count, int e_count) {
    srand ( time(NULL) );
    g.v_count = v_count;
    g.e_count = 0;
    for (int src = 0; src < v_count; src++) {
        for (int dest = 0; dest < v_count; dest++) {
            if (src != dest && !isEdgeVisited[src][dest] && !isEdgeVisited[dest][src]) {
                addEdge(src, dest, getRandomNumber(1000), g.e_count);
                g.e_count++;
                isEdgeVisited[src][dest] = true;
                isEdgeVisited[dest][src] = true;
            }
            if (g.e_count == e_count)
                break;
        }
        if (g.e_count == e_count)
            break;
    }
    printGraph();
}

void initArrays() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        isVertexVisited[i] = false;
        for (int j = 0; j < MAX_VERTICES; j++) {
            isEdgeVisited[i][j] = false;
        }
    }
}

void dfs(int vertex) {
    printf("Visiting vertex %d\n", vertex);
    isVertexVisited[vertex] = true;
    for (int i = 0; i < g.e_count; i++) {
        if (g.edges[i].src == vertex && !isVertexVisited[g.edges[i].dest])
            dfs(g.edges[i].dest);
    }
}

int main() {
    int v_count = 6, e_count = 10;
    initArrays();
    generateRandomGraph(v_count, e_count);
    dfs(0);
    return 0;
}