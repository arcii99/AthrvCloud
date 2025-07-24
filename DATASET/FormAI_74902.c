//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 20

int graph[MAX_NODES][MAX_NODES];
int color[MAX_NODES];
int num_nodes;

void initialize(){
    int i,j;
    for(i=0;i<MAX_NODES;i++){
        for(j=0;j<MAX_NODES;j++){
            graph[i][j] = 0;
        }
        color[i] = 0;
    }
    num_nodes = 0;
}

void add_edge(int u,int v){
    graph[u][v] = 1;
    graph[v][u] = 1;
    if(u > num_nodes) num_nodes = u;
    if(v > num_nodes) num_nodes = v;
}

void print_colors(){
    int i;
    printf("Vertex Colors:\n");
    for(i=1;i<=num_nodes;i++){
        printf("Vertex %d: Color %d\n",i,color[i]);
    }
}

int color_vertex(int v){
    int c,i;
    int used[ MAX_NODES ];
    for(i=0;i<MAX_NODES;i++) used[i] = 0;
    for(i=1;i<=num_nodes;i++){
        if(graph[v][i] == 1){
            used[color[i]] = 1;
        }
    }
    for(c=1;c<=num_nodes;c++){
        if(used[c] == 0){
            return c; //found unused color
        }
    }
    return -1; //no color available
}

void color_graph(){
    int i,c;
    for(i=1;i<=num_nodes;i++){
        c = color_vertex(i);
        if(c == -1){
            printf("Graph cannot be colored \n");
            return;
        }
        color[i] = c;
    }
    print_colors();
}

int main(){
    initialize();

    add_edge(1,2);
    add_edge(1,4);
    add_edge(2,3);
    add_edge(2,5);
    add_edge(3,5);
    add_edge(4,5);
    add_edge(4,6);
    add_edge(5,6);

    color_graph();

    return 0;
}