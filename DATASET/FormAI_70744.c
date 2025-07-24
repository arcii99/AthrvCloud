//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: active
#include<stdio.h>
#define max_vertices 50
#define max_edges 50
 
int vertices, edges;
int graph[max_vertices][max_edges];
int visited[max_vertices];
 
void addEdge(int s, int d) {
    graph[s][edges] = d; //add edge to source vertex
    graph[d][edges++] = s; //also add edge to destination vertex
}
 
void init() {
    int i;
    for(i=0; i<max_vertices; i++) {
        visited[i] = 0; //initialize visited array to zero
    }
    edges = 0; //initialize number of edges
}
 
void dfs(int vertex) {
    visited[vertex] = 1; //mark vertex as visited
    printf("%d ",vertex); //print vertex
    int i;
    for(i=0; i<edges; i++) {
        if(graph[vertex][i] && !visited[graph[vertex][i]]) { //if edge exists and destination is not visited 
            dfs(graph[vertex][i]); //recursive call to visit destination vertex
        }
    }
}
 
int main() {
    scanf("%d %d",&vertices,&edges);
    init();
    int i,j;
    for(i=0; i<edges; i++) {
        int s,d;
        scanf("%d %d",&s,&d); //input source and destination vertices of each edge
        addEdge(s,d);
    }
    int start_vertex;
    scanf("%d",&start_vertex); //input starting vertex for dfs
    dfs(start_vertex);
    return 0;
}