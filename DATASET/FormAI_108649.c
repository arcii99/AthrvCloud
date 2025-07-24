//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXV 100
typedef struct {
    int v;
    int e;
    int color[MAXV];
    int adj[MAXV][MAXV];
} Graph;

bool is_ok(Graph* g, int v, int color){
    int i;
    for(i=0; i<g->v; i++){
        if(g->adj[v][i] && g->color[i] == color){
            return false;
        }
    }
    return true;
}

bool color_graph(Graph* g, int v){
    int color;
    if(v == g->v) return true;
    for(color=0; color<g->v; color++){
        if(is_ok(g, v, color)){
            g->color[v] = color;
            if(color_graph(g, v+1)){
                return true;
            }
            g->color[v] = -1;
        }
    }
    return false;
}

void print_color(Graph* g){
    int i;
    printf("Vertex   Color\n");
    for(i=0; i<g->v; i++){
        printf("%4d     %4d\n", i, g->color[i]);
    }
}

int main(){
    Graph g;
    int i, j;

    g.v = 5;
    g.e = 8;
    for(i=0; i<g.v; i++){
        for(j=0; j<g.v; j++){
            g.adj[i][j] = 0;
        }
    }

    g.adj[0][1] = g.adj[1][0] = 1;
    g.adj[0][2] = g.adj[2][0] = 1;
    g.adj[0][4] = g.adj[4][0] = 1;
    g.adj[1][2] = g.adj[2][1] = 1;
    g.adj[1][3] = g.adj[3][1] = 1;
    g.adj[2][3] = g.adj[3][2] = 1;
    g.adj[2][4] = g.adj[4][2] = 1;
    g.adj[3][4] = g.adj[4][3] = 1;

    for(i=0; i<g.v; i++){
        g.color[i] = -1;
    }

    color_graph(&g,0);
    print_color(&g);

    return 0;
}