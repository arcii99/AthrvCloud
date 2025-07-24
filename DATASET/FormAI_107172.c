//FormAI DATASET v1.0 Category: Graph representation ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>

#define MAX 20

struct Graph {
    int vertex_count;
    int edges[MAX][MAX];
};

void display_graph(struct Graph g) {
    printf("\n Adjacency matrix of Graph:\n");

    for(int i=0; i<g.vertex_count; i++) {
        for(int j=0; j<g.vertex_count; j++) {
            printf("%d   ", g.edges[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct Graph g;
    printf("\nEnter number of vertices: ");
    scanf("%d", &g.vertex_count);

    int is_edge;
    for(int i=0; i<g.vertex_count; i++) {
        for(int j=0; j<g.vertex_count; j++) {
            if(i == j) {
                g.edges[i][j] = 0;
            }
            else {
                printf("\nIs there an edge between vertex %d and vertex %d? (1 if YES / 0 if NO): ", i+1, j+1);
                scanf("%d", &is_edge);
                if(is_edge == 1) {
                    g.edges[i][j] = 1;
                }
                else {
                    g.edges[i][j] = 0;
                }
            }
        }
    }

    display_graph(g);

    return 0;
}