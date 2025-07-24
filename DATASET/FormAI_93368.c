//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NODES 20

struct Node {
    int id;
    int color;
    int num_neighbours;
    struct Node* neighbours[MAX_NODES];
};

int node_colors[MAX_NODES];

void set_node_color(struct Node* node, int color) {
    node->color = color;
    node_colors[node->id] = color;
}

int get_valid_color(struct Node* node) {
    int color = rand() % (node->num_neighbours + 1);

    while (color <= node->num_neighbours) {
        int i;
        for (i = 0; i < node->num_neighbours; i++) {
            if (node->neighbours[i]->color == color) {
                break;
            }
        }
        if (i == node->num_neighbours) {
            return color;
        }
        color++;
    }
    return -1;
}

void color_graph(struct Node* nodes, int num_nodes) {
    int i;
    for (i = 0; i < num_nodes; i++) {
        set_node_color(&nodes[i], -1);
    }

    for (i = 0; i < num_nodes; i++) {
        while (nodes[i].color == -1) {
            set_node_color(&nodes[i], get_valid_color(&nodes[i]));
        }
    }
}

void print_graph(struct Node* nodes, int num_nodes) {
    int i, j;
    for (i = 0; i < num_nodes; i++) {
        printf("Node %d (color %d): ", nodes[i].id, nodes[i].color);
        for (j = 0; j < nodes[i].num_neighbours; j++) {
            printf("%d ", nodes[i].neighbours[j]->id);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int i, j;

    struct Node nodes[MAX_NODES];
    for (i = 0; i < MAX_NODES; i++) {
        nodes[i].id = i;
        nodes[i].num_neighbours = 0;
        nodes[i].color = -1;
        for (j = 0; j < MAX_NODES; j++) {
            nodes[i].neighbours[j] = NULL;
        }
    }

    // Example Cyberpunk-style graph
    nodes[0].neighbours[nodes[0].num_neighbours++] = &nodes[1];
    nodes[0].neighbours[nodes[0].num_neighbours++] = &nodes[2];
    nodes[0].neighbours[nodes[0].num_neighbours++] = &nodes[4];
    nodes[1].neighbours[nodes[1].num_neighbours++] = &nodes[0];
    nodes[1].neighbours[nodes[1].num_neighbours++] = &nodes[2];
    nodes[1].neighbours[nodes[1].num_neighbours++] = &nodes[4];
    nodes[1].neighbours[nodes[1].num_neighbours++] = &nodes[5];
    nodes[1].neighbours[nodes[1].num_neighbours++] = &nodes[6];
    nodes[1].neighbours[nodes[1].num_neighbours++] = &nodes[11];
    nodes[2].neighbours[nodes[2].num_neighbours++] = &nodes[0];
    nodes[2].neighbours[nodes[2].num_neighbours++] = &nodes[1];
    nodes[2].neighbours[nodes[2].num_neighbours++] = &nodes[3];
    nodes[2].neighbours[nodes[2].num_neighbours++] = &nodes[4];
    nodes[2].neighbours[nodes[2].num_neighbours++] = &nodes[8];
    nodes[3].neighbours[nodes[3].num_neighbours++] = &nodes[2];
    nodes[3].neighbours[nodes[3].num_neighbours++] = &nodes[4];
    nodes[3].neighbours[nodes[3].num_neighbours++] = &nodes[8];
    nodes[3].neighbours[nodes[3].num_neighbours++] = &nodes[13];
    nodes[4].neighbours[nodes[4].num_neighbours++] = &nodes[0];
    nodes[4].neighbours[nodes[4].num_neighbours++] = &nodes[1];
    nodes[4].neighbours[nodes[4].num_neighbours++] = &nodes[2];
    nodes[4].neighbours[nodes[4].num_neighbours++] = &nodes[3];
    nodes[4].neighbours[nodes[4].num_neighbours++] = &nodes[5];
    nodes[4].neighbours[nodes[4].num_neighbours++] = &nodes[6];
    nodes[4].neighbours[nodes[4].num_neighbours++] = &nodes[7];
    nodes[5].neighbours[nodes[5].num_neighbours++] = &nodes[1];
    nodes[5].neighbours[nodes[5].num_neighbours++] = &nodes[4];
    nodes[5].neighbours[nodes[5].num_neighbours++] = &nodes[6];
    nodes[5].neighbours[nodes[5].num_neighbours++] = &nodes[11];
    nodes[6].neighbours[nodes[6].num_neighbours++] = &nodes[1];
    nodes[6].neighbours[nodes[6].num_neighbours++] = &nodes[4];
    nodes[6].neighbours[nodes[6].num_neighbours++] = &nodes[5];
    nodes[6].neighbours[nodes[6].num_neighbours++] = &nodes[11];
    nodes[7].neighbours[nodes[7].num_neighbours++] = &nodes[4];
    nodes[7].neighbours[nodes[7].num_neighbours++] = &nodes[8];
    nodes[8].neighbours[nodes[8].num_neighbours++] = &nodes[2];
    nodes[8].neighbours[nodes[8].num_neighbours++] = &nodes[3];
    nodes[8].neighbours[nodes[8].num_neighbours++] = &nodes[7];
    nodes[8].neighbours[nodes[8].num_neighbours++] = &nodes[12];
    nodes[9].neighbours[nodes[9].num_neighbours++] = &nodes[11];
    nodes[10].neighbours[nodes[10].num_neighbours++] = &nodes[12];
    nodes[11].neighbours[nodes[11].num_neighbours++] = &nodes[1];
    nodes[11].neighbours[nodes[11].num_neighbours++] = &nodes[5];
    nodes[11].neighbours[nodes[11].num_neighbours++] = &nodes[6];
    nodes[11].neighbours[nodes[11].num_neighbours++] = &nodes[9];
    nodes[12].neighbours[nodes[12].num_neighbours++] = &nodes[8];
    nodes[12].neighbours[nodes[12].num_neighbours++] = &nodes[10];
    nodes[13].neighbours[nodes[13].num_neighbours++] = &nodes[3];

    color_graph(nodes, MAX_NODES);
    print_graph(nodes, MAX_NODES);

    return 0;
}