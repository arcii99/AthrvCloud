//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int num_verticies = 5;
int vertex_colors[5];
int adjacency_matrix[5][5] = {
    {0,1,1,1,0},
    {1,0,1,1,1},
    {1,1,0,1,0},
    {1,1,1,0,1},
    {0,1,0,1,0}
};

bool is_safe(int vertex, int color) {
    for(int i = 0; i < num_verticies; i++) {
        if(adjacency_matrix[vertex][i] && vertex_colors[i] == color) {
            return false;
        }
    }
    return true;
}

bool graph_coloring_util(int num_colors, int vertex) {
    if(vertex == num_verticies) {
        return true;
    }

    for(int i = 1; i <= num_colors; i++) {
        if(is_safe(vertex, i)) {
            vertex_colors[vertex] = i;
            if(graph_coloring_util(num_colors, vertex + 1)) {
                return true;
            }
            vertex_colors[vertex] = 0;
        }
    }

    return false;
}

bool graph_coloring(int num_colors) {
    for(int i = 0; i < num_verticies; i++) {
        vertex_colors[i] = 0;
    }
    return graph_coloring_util(num_colors, 0);
}

int main() {
    int num_colors = 3;
    if(graph_coloring(num_colors)) {
        printf("The graph can be colored with %d colors.\n", num_colors);
        printf("The vertex colors are: ");
        for(int i = 0; i < num_verticies; i++) {
            printf("%d ", vertex_colors[i]);
        }
    }
    else {
        printf("The graph cannot be colored with %d colors.\n", num_colors);
    }
    return 0;
}