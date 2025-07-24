//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: introspective
/*
Network Topology Mapper
This program is capable of mapping a small computer network topology by displaying a list of connected devices and their corresponding neighbors using Depth-First Search algorithm.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of devices supported
#define MAX_DEVICES 10

// Structure representing a device in the network topology
struct device {
    char *name;
    struct device *neighbors[MAX_DEVICES];
    int num_neighbors;
    int visited;
};

// Function to add a device as a neighbor to another device
void add_neighbor(struct device *device1, struct device *device2) {
    if (device1->num_neighbors < MAX_DEVICES) {
        device1->neighbors[device1->num_neighbors++] = device2;
    } else {
        printf("Unable to add neighbor: %s already has the maximum number of neighbors.\n", device1->name);
    }
}

// Depth-First Search algorithm implementation
void dfs(struct device *device) {
    int i;
    printf("%s\n", device->name);
    device->visited = 1;
    for (i = 0; i < device->num_neighbors; i++) {
        if (!device->neighbors[i]->visited) {
            dfs(device->neighbors[i]);
        }
    }
}

int main() {
    // Initialize devices in the network topology
    struct device a = {"Device A", {}, 0, 0};
    struct device b = {"Device B", {}, 0, 0};
    struct device c = {"Device C", {}, 0, 0};
    struct device d = {"Device D", {}, 0, 0};
    struct device e = {"Device E", {}, 0, 0};

    // Add neighbors
    add_neighbor(&a, &b);
    add_neighbor(&a, &c);
    add_neighbor(&b, &d);
    add_neighbor(&c, &d);
    add_neighbor(&c, &e);
    add_neighbor(&d, &e);

    // Display network topology
    printf("Network Topology:\n");
    dfs(&a);

    return 0;
}