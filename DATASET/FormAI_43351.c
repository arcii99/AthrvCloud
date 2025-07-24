//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: authentic
#include<stdio.h>
#include<stdlib.h>

int graph_coloring(int vertex, int graph[vertex][vertex], int colors[], int color_num[]) {
    int i, j, l, count = 0, flag = 0;
    int vertex_colors[vertex];

    for(i = 0; i < vertex; i++) {
        vertex_colors[i] = 0;
    }

    for(i = 0; i < vertex; i++) {
        for(j = 0; j < vertex; j++) {
            if(graph[i][j] == 1 && i != j) {
                if(vertex_colors[j] == colors[i]) {
                    flag = 1;
                }
            }
        }

        if(flag == 1) {
            flag = 0;
            continue;
        }

        vertex_colors[i] = colors[i];
        color_num[i] = colors[i];
        count++;

        for(l = 1; l <= vertex; l++) {
            colors[i] = l;

            if(graph_coloring(vertex, graph, colors, color_num) == 1) {
                return 1;
            }
        }

        vertex_colors[i] = 0;
        colors[i] = 0;
    }

    if(count == vertex) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int vertex, i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertex);

    int graph[vertex][vertex], colors[vertex], color_num[vertex];

    printf("Enter the adjacency matrix:\n");

    for(i = 0; i < vertex; i++) {
        for(j = 0; j < vertex; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nGraph:\n");

    for(i = 0; i < vertex; i++) {
        for(j = 0; j < vertex; j++) {
            printf("%d ", graph[i][j]);
        }

        printf("\n");
    }

    for(i = 0; i < vertex; i++) {
        colors[i] = 0;
        color_num[i] = 0;
    }

    if(graph_coloring(vertex, graph, colors, color_num) == 1) {
        printf("\nPossible graph coloring:\n");

        for(i = 0; i < vertex; i++) {
            printf("Vertex %d: Color %d\n", i + 1, color_num[i]);
        }
    } else {
        printf("\nGraph cannot be colored!\n");
    }

    return 0;
}