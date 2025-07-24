//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int graph[MAX][MAX], colorMap[MAX], totalVertices, totalEdges;

void displayGraph() {
    int i, j;
    printf("\n Graph : \n");
    for (i = 0; i < totalVertices; i++) {
        for (j = 0; j < totalVertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int canColor(int vertex, int currentColor) {
    int i;
    for (i = 0; i < totalVertices; i++) {
        if (graph[vertex][i] == 1 && colorMap[i] == currentColor) {
            return 0;
        }
    }
    return 1;
}

void colorGraph(int vertex, int totalColors) {
    int i, newColor = 1;
    if (vertex == totalVertices) {
        printf("\n Solution : ");
        for (i = 0; i < totalVertices; i++) {
            printf("%d ", colorMap[i]);
        }
        printf("\n");
        exit(1);
    }
    for (newColor = 1; newColor <= totalColors; newColor++) {
        if (canColor(vertex, newColor)) {
            colorMap[vertex] = newColor;
            colorGraph(vertex + 1, totalColors);
            colorMap[vertex] = 0;
        }
    }
}

int main() {
    int i, j, source, destination, totalColors;
    printf("\n Enter Total Vertices : ");
    scanf("%d", &totalVertices);
    printf("\n Enter Total Edges : ");
    scanf("%d", &totalEdges);
    printf("\n Enter Edge from Source to Destination : \n");
    for (i = 0; i < totalEdges; i++) {
        printf("\n Edge %d : ", i + 1);
        scanf("%d %d", &source, &destination);
        graph[source - 1][destination - 1] = 1;
        graph[destination - 1][source - 1] = 1;
    }
    displayGraph();
    printf("\n Enter Total Colors : ");
    scanf("%d", &totalColors);
    colorGraph(0, totalColors);
    return 0;
}