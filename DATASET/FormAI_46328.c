//FormAI DATASET v1.0 Category: Graph representation ; Style: Dennis Ritchie
#include <stdio.h>

#define MAX_NODES 20
#define MAX_EDGES 50

int edges[MAX_EDGES][2], num_nodes, num_edges;

void add_edge(int u, int v) {
    edges[num_edges][0] = u;
    edges[num_edges][1] = v;
    num_edges++;
}

void print_graph() {
    printf("Graph:\n");
    for (int i = 0; i < num_edges; i++) {
        printf("%d -> %d\n", edges[i][0], edges[i][1]);
    }
}

int main() {
    printf("Enter the number of nodes in the graph (max %d): ", MAX_NODES);
    scanf("%d", &num_nodes);
    
    printf("Enter the edges of the graph (in the format u v)\n");
    printf("Enter -1 to quit.\n");
    
    int u, v;
    while (scanf("%d %d", &u, &v)) {
        if (u == -1 || v == -1) {
            break;
        }
        add_edge(u, v);
    }
    
    print_graph();
    
    return 0;
}