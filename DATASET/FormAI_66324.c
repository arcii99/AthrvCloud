//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 50
#define MAX_NAME_LEN 10

struct node {
    char name[MAX_NAME_LEN];
    bool value;
};

struct edge {
    int start_node_id;
    int end_node_id;
};

struct circuit {
    struct node nodes[MAX_NODES];
    struct edge edges[MAX_NODES * 2];
    int num_nodes;
    int num_edges;
};

void initialize_circuit(struct circuit* c) {
    memset(c, 0, sizeof(struct circuit));
}

bool is_node(const char* name) {
    for (int i = 0; i < strlen(name); ++i) {
        if (!isalnum(name[i])) {
            return false;
        }
    }
    return true;
}

int find_node(struct circuit* c, const char* name) {
    for (int i = 0; i < c->num_nodes; ++i) {
        if (strcmp(c->nodes[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void add_node(struct circuit* c, const char* name) {
    if (!is_node(name)) {
        printf("[ERROR] Invalid node name: %s\n", name);
        exit(EXIT_FAILURE);
    }

    if (find_node(c, name) != -1) {
        printf("[ERROR] Node already exists: %s\n", name);
        exit(EXIT_FAILURE);
    }

    if (c->num_nodes >= MAX_NODES) {
        printf("[ERROR] Maximum number of nodes exceeded\n");
        exit(EXIT_FAILURE);
    }

    strcpy(c->nodes[c->num_nodes].name, name);
    ++c->num_nodes;
}

void add_edge(struct circuit* c, const char* start, const char* end) {
    int start_id = find_node(c, start);
    if (start_id == -1) {
        printf("[ERROR] Invalid start node: %s\n", start);
        exit(EXIT_FAILURE);
    }

    int end_id = find_node(c, end);
    if (end_id == -1) {
        printf("[ERROR] Invalid end node: %s\n", end);
        exit(EXIT_FAILURE);
    }

    if (c->num_edges >= MAX_NODES * 2) {
        printf("[ERROR] Maximum number of edges exceeded\n");
        exit(EXIT_FAILURE);
    }

    c->edges[c->num_edges].start_node_id = start_id;
    c->edges[c->num_edges].end_node_id = end_id;
    ++c->num_edges;
}

void initialize_values(struct circuit* c) {
    for (int i = 0; i < c->num_nodes; ++i) {
        c->nodes[i].value = rand() % 2;
    }
}

void print_circuit(struct circuit* c) {
    printf("Circuit:\n");
    for (int i = 0; i < c->num_nodes; ++i) {
        printf("%s: %d\n", c->nodes[i].name, c->nodes[i].value);
    }
    printf("\n");
}

void simulate_circuit(struct circuit* c) {
    initialize_values(c);
    print_circuit(c);
}

int main() {
    srand(time(NULL));

    struct circuit c;
    initialize_circuit(&c);

    add_node(&c, "A");
    add_node(&c, "B");
    add_node(&c, "C");

    add_edge(&c, "A", "B");
    add_edge(&c, "A", "C");
    add_edge(&c, "B", "C");

    simulate_circuit(&c);

    return 0;
}