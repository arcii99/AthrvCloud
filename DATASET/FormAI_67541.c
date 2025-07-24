//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Cryptic
#include <stdio.h>
#define MAX_VERTICES 1000

int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];
int n, m;

void dfs(int v, int c){
    color[v] = c;
    for(int i=0; i<n; i++){
        if(graph[v][i] == 1 && color[i] == 0){
            dfs(i, 3-c);
        }
    }
}

void solve(){
    for(int i=0; i<n; i++){
        if(color[i] == 0){
            dfs(i, 1);
        }
    }
    for(int i=0; i<n; i++){
        printf("Vertex %d has color %d\n", i, color[i]);
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    solve();
    return 0;
}