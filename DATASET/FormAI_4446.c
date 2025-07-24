//FormAI DATASET v1.0 Category: Graph representation ; Style: optimized
#include<stdio.h>
#include<stdlib.h>

#define MAX 20

typedef struct {
    int vertex;
    int weight;
} Edge;

void addEdge(Edge[], int);
void printGraph(Edge[], int);

int main() {
    Edge graph[MAX];
    int numOfVertices;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numOfVertices);
    addEdge(graph, numOfVertices);
    printGraph(graph, numOfVertices);
    return 0;
}

void addEdge(Edge graph[], int size) {
    int i, j, weight;
    printf("Enter the adjacent vertices and corresponding weights: \n");
    for(i=0; i<size; i++) {
        for(j=i+1; j<size; j++) {
            printf("Vertex %d and Vertex %d: ", i, j);
            scanf("%d", &weight);
            graph[i*size+j].vertex = j;
            graph[i*size+j].weight = weight;
            graph[j*size+i].vertex = i;
            graph[j*size+i].weight = weight;
        }
    }
}

void printGraph(Edge graph[], int size) {
    int i, j;
    printf("\n");
    for(i=0; i<size; i++) {
        for(j=0; j<size; j++) {
            if(graph[i*size+j].weight != 0) {
                printf("(%d, %d): %d\n", i, graph[i*size+j].vertex, graph[i*size+j].weight);
            }
        }
    }
}