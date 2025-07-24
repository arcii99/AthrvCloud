//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NODES 1000
#define MAX_EDGES 5000

typedef struct TrafficData {
    int node;
    float bandwidth;
    float delay;
} TrafficData;

typedef struct Edge {
    int src;
    int dest;
    float bandwidth;
    float delay;
} Edge;

typedef struct Node {
    int id;
    int num_edges;
    Edge edges[MAX_EDGES];
    float max_bandwidth;
    float min_delay;
    float avg_bandwidth;
    float avg_delay;
} Node;

int num_nodes, num_edges;
Node nodes[MAX_NODES];
TrafficData traffic_data[MAX_NODES];

void initialize_nodes() {
    for (int i=0; i<num_nodes; i++) {
        nodes[i].id = i;
        nodes[i].num_edges = 0;
        nodes[i].max_bandwidth = 0;
        nodes[i].min_delay = 0;
        nodes[i].avg_bandwidth = 0;
        nodes[i].avg_delay = 0;
    }
}

void add_edge(int src, int dest, float bandwidth, float delay) {
    nodes[src].edges[nodes[src].num_edges].src = src;
    nodes[src].edges[nodes[src].num_edges].dest = dest;
    nodes[src].edges[nodes[src].num_edges].bandwidth = bandwidth;
    nodes[src].edges[nodes[src].num_edges].delay = delay;
    nodes[src].num_edges++;
}

void read_traffic_data(char* filename) {
    FILE* fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Unable to open file %s\n", filename);
        exit(1);
    }
    
    int node_id;
    float bandwidth, delay;
    while (fscanf(fp, "%d %f %f", &node_id, &bandwidth, &delay) != EOF) {
        TrafficData td;
        td.node = node_id;
        td.bandwidth = bandwidth;
        td.delay = delay;
        traffic_data[node_id] = td;
    }

    fclose(fp);
}

void read_network_data(char* filename) {
    FILE* fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Unable to open file %s\n", filename);
        exit(1);
    }

    fscanf(fp, "%d %d", &num_nodes, &num_edges);
    initialize_nodes();

    int src, dest;
    float bandwidth, delay;
    while (fscanf(fp, "%d %d %f %f", &src, &dest, &bandwidth, &delay) != EOF) {
        add_edge(src, dest, bandwidth, delay);
    }

    fclose(fp);
}

void calculate_network_stats() {
    for (int i=0; i<num_nodes; i++) {
        Node node = nodes[i];
        node.max_bandwidth = 0;
        node.min_delay = 999999;
        node.avg_bandwidth = 0;
        node.avg_delay = 0;

        for (int j=0; j<node.num_edges; j++) {
            Edge edge = node.edges[j];
            node.avg_bandwidth += edge.bandwidth;
            node.avg_delay += edge.delay;

            if (edge.bandwidth > node.max_bandwidth) {
                node.max_bandwidth = edge.bandwidth;
            }

            if (edge.delay < node.min_delay) {
                node.min_delay = edge.delay;
            }
        }

        node.avg_bandwidth /= node.num_edges;
        node.avg_delay /= node.num_edges;

        nodes[i] = node;
    }
}

void print_network_stats() {
    printf("Network Stats:\n");
    for (int i=0; i<num_nodes; i++) {
        Node node = nodes[i];
        printf("Node %d: Avg Bandwidth=%.2f Mbps, Max Bandwidth=%.2f Mbps, Avg Delay=%.2f ms, Min Delay=%.2f ms\n", 
            node.id, node.avg_bandwidth, node.max_bandwidth, node.avg_delay, node.min_delay);
    }
}

void print_traffic_data() {
    printf("Incoming Traffic Data:\n");
    for (int i=0; i<num_nodes; i++) {
        TrafficData td = traffic_data[i];
        printf("Node %d: Bandwidth=%.2f Mbps, Delay=%.2f ms\n", td.node, td.bandwidth, td.delay);
    }
}

void randomize_traffic_data() {
    srand(time(NULL));
    for (int i=0; i<num_nodes; i++) {
        TrafficData td;
        td.node = i;
        td.bandwidth = ((float) rand() / RAND_MAX) * nodes[i].max_bandwidth;
        td.delay = ((float) rand() / RAND_MAX) * (nodes[i].min_delay / 2);
        traffic_data[i] = td;
    }
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <network_data_file> <traffic_data_file>\n", argv[0]);
        exit(1);
    }

    read_network_data(argv[1]);
    calculate_network_stats();

    read_traffic_data(argv[2]);
    randomize_traffic_data();

    print_network_stats();
    print_traffic_data();

    return 0;
}