//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 50
#define MAX_LINE_LEN 100

typedef struct Node {
    char name[MAX_LINE_LEN];
    int index;
    double voltage;
    double previous_voltage;
    double capacitance;
    int is_ground;
    int num_connected_nodes;
    int connected_nodes[MAX_NODES];
    double adjacent_matrix[MAX_NODES][MAX_NODES];
} Node;

void add_connections(Node* node1, Node* node2, double value) {
    node1->connected_nodes[node1->num_connected_nodes++] = node2->index;
    node2->connected_nodes[node2->num_connected_nodes++] = node1->index;
    node1->adjacent_matrix[node1->index][node2->index] += value;
    node2->adjacent_matrix[node2->index][node1->index] += value;
}

void init_nodes(Node* nodes, int num_nodes) {
    int i, j;

    for (i = 0; i < num_nodes; i++) {
        nodes[i].index = i;
        nodes[i].voltage = 0;
        nodes[i].previous_voltage = 0;
        nodes[i].capacitance = 0;
        nodes[i].is_ground = 0;
        nodes[i].num_connected_nodes = 0;

        for (j = 0; j < MAX_NODES; j++) {
            nodes[i].connected_nodes[j] = -1;
        }

        for (j = 0; j < num_nodes; j++) {
            nodes[i].adjacent_matrix[i][j] = 0;
        }
    }
}

void print_nodes(Node* nodes, int num_nodes) {
    int i, j;

    printf("Num nodes: %d\n", num_nodes);

    for (i = 0; i < num_nodes; i++) {
        printf("Node %d: %s\n", i, nodes[i].name);
        printf("  Voltage: %f\n", nodes[i].voltage);
        printf("  Capacitance: %f\n", nodes[i].capacitance);
        printf("  Is ground: %d\n", nodes[i].is_ground);
        printf("  Connected nodes: ");

        for (j = 0; j < nodes[i].num_connected_nodes; j++) {
            printf("%d ", nodes[i].connected_nodes[j]);
        }

        printf("\n");
    }
}

void forward_euler(Node* nodes, int num_nodes, double time_step, double end_time) {
    int i, j;
    double current_time = 0;

    while (current_time <= end_time) {
        for (i = 0; i < num_nodes; i++) {
            nodes[i].previous_voltage = nodes[i].voltage;
        }

        for (i = 0; i < num_nodes; i++) {
            double current = 0;

            for (j = 0; j < nodes[i].num_connected_nodes; j++) {
                int connected_node_index = nodes[i].connected_nodes[j];
                double voltage_diff = nodes[i].previous_voltage - nodes[connected_node_index].previous_voltage;
                current += nodes[i].adjacent_matrix[i][connected_node_index] * voltage_diff;
            }

            if (nodes[i].capacitance > 0) {
                current /= nodes[i].capacitance;
            }

            nodes[i].voltage = nodes[i].previous_voltage + time_step * current;
        }

        current_time += time_step;
    }
}

int main() {
    Node nodes[MAX_NODES];
    int num_nodes = 0;
    char curr_line[MAX_LINE_LEN];

    while (fgets(curr_line, MAX_LINE_LEN, stdin)) {
        if (curr_line[0] == '#') {
            continue;
        }

        char* curr_token = strtok(curr_line, " ");

        if (strcmp(curr_token, ".end") == 0) {
            break;
        }

        if (strcmp(curr_token, "gnd") == 0) {
            nodes[num_nodes].is_ground = 1;
            sprintf(nodes[num_nodes].name, "gnd");
            num_nodes++;
            continue;
        }

        Node* new_node = &nodes[num_nodes];
        new_node->is_ground = 0;

        sprintf(new_node->name, "%s", curr_token);
        curr_token = strtok(NULL, " ");

        while (curr_token) {
            if (strchr(curr_token, 'k')) {
                add_connections(new_node, &nodes[atoi(curr_token)+num_nodes], 1000);
            } else if (strchr(curr_token, 'M')) {
                add_connections(new_node, &nodes[atoi(curr_token)*1000000+num_nodes], 0.000001);
            } else if (atof(curr_token)) {
                add_connections(new_node, &nodes[atoi(curr_token)-1], atof(curr_token));
            }

            curr_token = strtok(NULL, " ");
        }

        num_nodes++;
    }

    init_nodes(nodes, num_nodes);
    print_nodes(nodes, num_nodes);
    forward_euler(nodes, num_nodes, 0.0001, 0.1);
    print_nodes(nodes, num_nodes);

    return 0;
}