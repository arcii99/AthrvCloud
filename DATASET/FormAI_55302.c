//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 100
#define MAX_CONNECTIONS 1000

typedef struct Device {
    char* name;
    int id;
    int connections[MAX_CONNECTIONS];
    int num_connections;
} Device;

Device* devices[MAX_DEVICES];
int num_devices = 0;

void add_device(char* name) {
    Device* d = malloc(sizeof(Device));
    d->name = malloc(strlen(name) + 1);
    strcpy(d->name, name);
    d->id = num_devices++;

    devices[d->id] = d;
}

void add_connection(int id1, int id2) {
    if (id1 == id2) {
        fprintf(stderr, "Cannot connect device to itself.\n");
        return;
    }

    devices[id1]->connections[devices[id1]->num_connections++] = id2;
    devices[id2]->connections[devices[id2]->num_connections++] = id1;
}

void print_topology() {
    printf("Network Topology:\n");

    for (int i = 0; i < num_devices; i++) {
        printf("%d: %s -> ", devices[i]->id, devices[i]->name);

        for (int j = 0; j < devices[i]->num_connections; j++) {
            int conn_id = devices[i]->connections[j];
            printf("%s ", devices[conn_id]->name);
        }

        printf("\n");
    }
}

int main() {
    // Add devices
    add_device("Router1");
    add_device("Switch1");
    add_device("PC1");
    add_device("PC2");
    add_device("Router2");
    add_device("Switch2");
    add_device("Server");

    // Connect devices
    add_connection(0, 1);
    add_connection(1, 2);
    add_connection(1, 3);
    add_connection(0, 4);
    add_connection(4, 5);
    add_connection(5, 6);
    add_connection(3, 6);

    // Print topology
    print_topology();

    return 0;
}