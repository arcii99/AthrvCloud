//FormAI DATASET v1.0 Category: Graph representation ; Style: optimized
#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 10

void add_edge(int graph[MAX_VERTICES][MAX_VERTICES], int source, int destination);
void print_graph(int graph[MAX_VERTICES][MAX_VERTICES]);

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {{0}};
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 0);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 3);

    print_graph(graph);
    return 0;
}

void add_edge(int graph[MAX_VERTICES][MAX_VERTICES], int source, int destination) {
    graph[source][destination] = 1;
}

void print_graph(int graph[MAX_VERTICES][MAX_VERTICES]) {
    int i,j;
    printf("  ");
    for(i=0;i<MAX_VERTICES;i++)
        printf("%d ",i);
    printf("\n");
    for(i=0;i<MAX_VERTICES;i++) {
        printf("%d ",i);
        for(j=0;j<MAX_VERTICES;j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
}