//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define MAX_DEVICES 50
#define MAX_EDGES 100

struct Device {
    int id;
    char name[20];
    int connections[MAX_DEVICES];
    int num_connections;
};

struct Edge {
    int source;
    int dest;
};

int find_device(struct Device network[], int num_devices, char name[]) {
    for (int i = 0; i < num_devices; i++) {
        if (strcmp(network[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void add_device(struct Device network[], int *num_devices, char name[]) {
    if (*num_devices < MAX_DEVICES) {
        int id = (*num_devices)++;
        strcpy(network[id].name, name);
        network[id].id = id;
        network[id].num_connections = 0;
    }
}

void add_edge(struct Device network[], int num_devices, struct Edge edges[], int *num_edges, char source[], char dest[]) {
    int source_id = find_device(network, num_devices, source);
    int dest_id = find_device(network, num_devices, dest);

    if (source_id != -1 && dest_id != -1 && *num_edges < MAX_EDGES) {
        edges[(*num_edges)++] = (struct Edge) { source_id, dest_id };
        network[source_id].connections[network[source_id].num_connections++] = dest_id;
        network[dest_id].connections[network[dest_id].num_connections++] = source_id;
    }
}

void print_network(struct Device network[], int num_devices, struct Edge edges[], int num_edges) {
    printf("Network Topology:\n");
    printf("Devices:\n");
    for (int i = 0; i < num_devices; i++) {
        printf("%d: %s\n", network[i].id, network[i].name);
    }
    printf("Edges:\n");
    for (int i = 0; i < num_edges; i++) {
        printf("(%d, %d)\n", edges[i].source, edges[i].dest);
    }
}

int main() {
    struct Device network[MAX_DEVICES];
    struct Edge edges[MAX_EDGES];
    int num_devices = 0;
    int num_edges = 0;

    add_device(network, &num_devices, "Router 1");
    add_device(network, &num_devices, "Switch 1");
    add_device(network, &num_devices, "Server 1");
    add_device(network, &num_devices, "Router 2");

    add_edge(network, num_devices, edges, &num_edges, "Router 1", "Switch 1");
    add_edge(network, num_devices, edges, &num_edges, "Switch 1", "Server 1");
    add_edge(network, num_devices, edges, &num_edges, "Router 2", "Switch 1");
    
    print_network(network, num_devices, edges, num_edges);

    return 0;
}