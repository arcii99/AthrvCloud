//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 100
#define MAX_CONNECTIONS 1000

struct device {
    char name[20];
    int id;
    int connections[MAX_DEVICES];
    int num_connections;
};

struct topology {
    struct device devices[MAX_DEVICES];
    int num_devices;
    int connections[MAX_CONNECTIONS][2];
    int num_connections;
};

int find_device_id(struct topology *topo, char *name) {
    int i;
    for (i = 0; i < topo->num_devices; i++) {
        if (strcmp(topo->devices[i].name, name) == 0) {
            return topo->devices[i].id;
        }
    }
    return -1;
}

void add_device(struct topology *topo, char *name) {
    if (topo->num_devices == MAX_DEVICES) {
        printf("Error: Maximum number of devices reached\n");
        return;
    }
    struct device *dev = &(topo->devices[topo->num_devices]);
    strcpy(dev->name, name);
    dev->id = topo->num_devices;
    dev->num_connections = 0;
    topo->num_devices++;
}

void add_connection(struct topology *topo, char *dev1, char *dev2) {
    int id1 = find_device_id(topo, dev1);
    int id2 = find_device_id(topo, dev2);
    if (id1 == -1 || id2 == -1) {
        printf("Error: Invalid device name\n");
        return;
    }
    if (topo->num_connections == MAX_CONNECTIONS) {
        printf("Error: Maximum number of connections reached\n");
        return;
    }
    topo->connections[topo->num_connections][0] = id1;
    topo->connections[topo->num_connections][1] = id2;
    topo->devices[id1].connections[topo->devices[id1].num_connections] = id2;
    topo->devices[id1].num_connections++;
    topo->devices[id2].connections[topo->devices[id2].num_connections] = id1;
    topo->devices[id2].num_connections++;
    topo->num_connections++;
}

void print_topology(struct topology *topo) {
    printf("Number of devices: %d\n", topo->num_devices);
    int i;
    for (i = 0; i < topo->num_devices; i++) {
        printf("Device %d: %s\n", i, topo->devices[i].name);
    }
    printf("Number of connections: %d\n", topo->num_connections);
    for (i = 0; i < topo->num_connections; i++) {
        int id1 = topo->connections[i][0];
        int id2 = topo->connections[i][1];
        printf("Connection %d: %s <-> %s\n", i, topo->devices[id1].name, topo->devices[id2].name);
    }
}

int main() {
    struct topology topo;
    topo.num_devices = 0;
    topo.num_connections = 0;

    add_device(&topo, "Router 1");
    add_device(&topo, "Switch 1");
    add_device(&topo, "Computer 1");
    add_device(&topo, "Computer 2");
    add_device(&topo, "Printer 1");

    add_connection(&topo, "Router 1", "Switch 1");
    add_connection(&topo, "Switch 1", "Computer 1");
    add_connection(&topo, "Switch 1", "Computer 2");
    add_connection(&topo, "Switch 1", "Printer 1");

    print_topology(&topo);

    return 0;
}