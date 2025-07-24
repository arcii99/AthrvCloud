//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

int total_vertices;
int color[MAX_VERTICES];
int graph[MAX_VERTICES][MAX_VERTICES];

void print_color(int color_num) {
    switch(color_num) {
        case 0:
            printf("RED ");
            break;
        case 1:
            printf("GREEN ");
            break;
        case 2:
            printf("BLUE ");
            break;
        case 3:
            printf("YELLOW ");
            break;
        default:
            printf("INVALID COLOR");
    }  
}

int is_valid_color(int vertex, int c) {
    //check if any adjacent vertex has the same color
    for(int i = 0; i < total_vertices; i++) {
        if(graph[vertex][i] && c == color[i]) {
            return 0;
        }
    }
    return 1;
}

void graph_color(int vertex) {
    if(vertex == total_vertices) {
        printf("Vertex-Color Mapping:\n");
        for(int i = 0; i < total_vertices; i++) {
            printf("Vertex %d -> ", i+1);
            print_color(color[i]);
            printf("\n");
        }
        printf("\n");
        return;
    }
    
    for(int c = 0; c < 4; c++) {
        if(is_valid_color(vertex, c)) {
            color[vertex] = c;
            graph_color(vertex+1);
            color[vertex] = 0;
        }
    }
}

int main() {
    printf("Enter the total number of vertices in the graph (MAX 100): ");
    scanf("%d", &total_vertices);
    
    memset(color, 0, sizeof(color));
    memset(graph, 0, sizeof(graph));
    
    printf("\nEnter the edges in the graph in the following format (each edge separated by a newline):\nsource_vertex destination_vertex\nEnter -1 -1 to terminate.\n");
    int src, dest;
    while(1) {
        scanf("%d %d", &src, &dest);
        if(src == -1 && dest == -1) {
            break;
        }
        graph[src-1][dest-1] = 1;
        graph[dest-1][src-1] = 1;
    }
    
    printf("\nColoring the graph...\n\n");
    graph_color(0);
    
    return 0;
}