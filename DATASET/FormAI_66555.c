//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000
#define MAX_EDGES 100000

struct edge
{
    int src;
    int dest;
    double weight;
};

struct node
{
    int id;
    int visited;
    int num_edges;
    struct edge edges[MAX_EDGES];
};

struct circuit
{
    int num_nodes;
    int num_edges;
    struct node nodes[MAX_NODES];
};

void add_edge(struct circuit* c, int src_id, int dest_id, double weight)
{
    struct node* src_node = NULL;
    struct node* dest_node = NULL;

    for (int i = 0; i < c->num_nodes; ++i)
    {
        if (c->nodes[i].id == src_id)
        {
            src_node = &c->nodes[i];
        }
        if (c->nodes[i].id == dest_id)
        {
            dest_node = &c->nodes[i];
        }
    }

    if (!src_node)
    {
        src_node = &c->nodes[c->num_nodes];
        src_node->id = src_id;
        src_node->num_edges = 0;
        src_node->visited = 0;
        c->num_nodes++;
    }

    if (!dest_node)
    {
        dest_node = &c->nodes[c->num_nodes];
        dest_node->id = dest_id;
        dest_node->num_edges = 0;
        dest_node->visited = 0;
        c->num_nodes++;
    }

    struct edge e = {src_node->id, dest_node->id, weight};
    src_node->edges[src_node->num_edges] = e;
    src_node->num_edges++;
    c->num_edges++;
}

void simulate_circuit(struct circuit* c)
{
    // Reset all node visited flags
    for (int i = 0; i < c->num_nodes; ++i)
    {
        c->nodes[i].visited = 0;
    }

    // Simulate circuit
    double voltage[c->num_nodes];
    voltage[0] = 5; // Set source voltage to 5

    while (!c->nodes[c->num_nodes-1].visited)
    {
        // Find unvisited node with lowest voltage
        int curr_node = -1;
        double min_voltage = 100000;
        for (int i = 0; i < c->num_nodes; ++i)
        {
            if (!c->nodes[i].visited && voltage[i] < min_voltage)
            {
                curr_node = i;
                min_voltage = voltage[i];
            }
        }

        // Set visited flag
        c->nodes[curr_node].visited = 1;

        // Update voltages of neighboring nodes
        struct node* n = &c->nodes[curr_node];
        for (int i = 0; i < n->num_edges; ++i)
        {
            int neighbor_id = n->edges[i].dest;
            voltage[neighbor_id] = voltage[curr_node] - n->edges[i].weight;
        }
    }

    printf("Output voltage: %lf\n", voltage[c->num_nodes-1]);
}

int main()
{
    struct circuit c = {0};

    add_edge(&c, 0, 1, 1.0);
    add_edge(&c, 0, 2, 2.0);
    add_edge(&c, 1, 2, 1.5);
    add_edge(&c, 1, 3, 0.5);
    add_edge(&c, 2, 3, 1.0);

    simulate_circuit(&c);

    return 0;
}