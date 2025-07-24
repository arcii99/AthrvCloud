//FormAI DATASET v1.0 Category: Graph representation ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];

// function to initialize graph
void initializeGraph() {
    int i, j;
    for(i = 0; i < MAX_VERTICES; i++) {
        for(j = 0; j < MAX_VERTICES; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }
}

// function to get index of vertex
int getVertexIndex(char vertex) {
    return (int)(vertex - 'A');
}

// function to add edge between two vertices
void addEdge(char from_vertex, char to_vertex) {
    int from_index = getVertexIndex(from_vertex);
    int to_index = getVertexIndex(to_vertex);
    graph[from_index][to_index] = 1;
    graph[to_index][from_index] = 1;   // for undirected graph
}

// function to display the graph
void displayGraph() {
    int i, j;
    printf("\nGraph:\n");
    for(i = 0; i < MAX_VERTICES; i++) {
        for(j = 0; j < MAX_VERTICES; j++) {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}

// function to traverse graph using DFS
void dfs(int vertex) {
    visited[vertex] = 1;
    printf("%c ", (char)(vertex + 'A'));
    int i;
    for(i = 0; i < MAX_VERTICES; i++) {
        if(graph[vertex][i] && !visited[i]) {
            dfs(i);
        }
    }
}

// main function
int main() {
    initializeGraph();
    addEdge('A', 'B');
    addEdge('A', 'D');
    addEdge('B', 'C');
    addEdge('B', 'E');
    addEdge('C', 'F');
    addEdge('D', 'E');
    addEdge('E', 'F');

    displayGraph();

    printf("\nDFS Traversal: ");
    dfs(0);

    return 0;
}