//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int n, graph[MAX][MAX], colors[MAX];

void init(){
    int i, j;
    for(i=0; i<n; i++){
        colors[i] = 0;
        for(j=0; j<n; j++){
            graph[i][j] = 0;
        }
    }
}

void read_graph(){
    int i, j, e;

    printf("\nEnter the no. of vertices: ");
    scanf("%d", &n);

    init();

    printf("\nEnter the no. of edges: ");
    scanf("%d", &e);

    for(i=0; i<e; i++){
        int u, v;
        printf("\nEnter the edge (u, v): ");
        scanf("%d%d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }
}

int is_safe(int v, int c){
    int i;
    for(i=0; i<n; i++){
        if(graph[v][i] && c==colors[i]){
            return 0;
        }
    }
    return 1;
}

int graph_color(int v){
    int c;
    if(v == n){
        return 1;
    }
    for(c=1; c<=n; c++){
        if(is_safe(v, c)){
            colors[v] = c;
            if(graph_color(v+1)){
                return 1;
            }
            colors[v] = 0;
        }
    }
    return 0;
}

int main(){
    read_graph();
    if(graph_color(0)){
        printf("\nColoring Possible\n");
        printf("\nThe Vertex - Color combinations are: \n");
        for(int i=0;i<n;i++) {
          printf("Vertex %d -> Color %d \n",i, colors[i]);
        }
    }
    else{
        printf("\nColoring Not Possible\n");
    }
    return 0;
}