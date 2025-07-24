//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>

#define MAX_NODES 20
#define MAX_COLORS 4

int graph[MAX_NODES][MAX_NODES];
int node_colors[MAX_NODES];

void initialize_graph(int num_nodes) {
    for(int i=0; i<num_nodes; i++) {
        for(int j=0; j<num_nodes; j++) {
            graph[i][j] = 0;
        }
        node_colors[i] = 0;
    }
}

int is_safe(int node, int color, int num_nodes) {
    for(int i=0; i<num_nodes; i++) {
        if(graph[node][i] && color == node_colors[i]) {
            return 0;
        }
    }
    return 1;
}

int graph_color(int node, int num_nodes, int num_colors) {
    if(node == num_nodes) {
        return 1;
    }

    for(int i=1; i<=num_colors; i++) {
        if(is_safe(node, i, num_nodes)) {
            node_colors[node] = i;

            if(graph_color(node+1, num_nodes, num_colors)) {
                return 1;
            }

            node_colors[node] = 0;
        }
    }

    return 0;
}

void print_colors(int num_nodes) {
    printf("Node Colors:\n");
    for(int i=0; i<num_nodes; i++) {
        printf("Node %d: Color %d\n", i+1, node_colors[i]);
    }
}

void add_edge(int from, int to) {
    graph[from][to] = 1;
    graph[to][from] = 1;
}

int main() {
    int num_nodes = 5;
    initialize_graph(num_nodes);

    add_edge(0, 1);
    add_edge(0, 2);
    add_edge(1, 2);
    add_edge(1, 3);
    add_edge(2, 3);
    add_edge(3, 4);

    int num_colors = 3;
    if(graph_color(0, num_nodes, num_colors)) {
        print_colors(num_nodes);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}