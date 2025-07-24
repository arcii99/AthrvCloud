//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct _Node {
    int id;
    int num_links;
    int links[MAX_NODES];
} Node;

void map_topology(Node nodes[], int num_nodes);
void print_mapping(Node nodes[], int num_nodes);

int main() {
    int num_nodes;

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    Node nodes[num_nodes];

    for (int i = 0; i < num_nodes; i++) {
        nodes[i].id = i;
        nodes[i].num_links = 0;
    }

    // Populate links
    for (int i = 0; i < num_nodes; i++) {
        printf("Enter the number of links for node %d: ", i);
        scanf("%d", &nodes[i].num_links);

        for (int j = 0; j < nodes[i].num_links; j++) {
            int link_id;
            printf("Enter the ID for link %d: ", j + 1);
            scanf("%d", &link_id);
            nodes[i].links[j] = link_id;
        }
    }

    map_topology(nodes, num_nodes);
    print_mapping(nodes, num_nodes);

    return 0;
}

void map_topology(Node nodes[], int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < nodes[i].num_links; j++) {
            int link_id = nodes[i].links[j];
            int num_link_links = nodes[link_id].num_links;

            // Check if link is bidirectional
            if (nodes[link_id].id == i) {
                continue;
            }

            // Add link to each node's links
            for (int k = 0; k < num_link_links; k++) {
                if (nodes[link_id].links[k] == i) {
                    continue;
                }
                nodes[i].links[nodes[i].num_links] = nodes[link_id].links[k];
                nodes[i].num_links++;
            }
        }
    }
}

void print_mapping(Node nodes[], int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        printf("Links for node %d: ", nodes[i].id);
        for (int j = 0; j < nodes[i].num_links; j++) {
            printf("%d ", nodes[i].links[j]);
        }
        printf("\n");
    }
}