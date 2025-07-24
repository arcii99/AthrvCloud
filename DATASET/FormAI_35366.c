//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 100
#define MAX_CONNECTIONS 1000

typedef struct device {
    char name[50];
    int id;
} Device;

typedef struct connection {
    int from;
    int to;
} Connection;

int main() {
    Device devices[MAX_DEVICES];
    Connection connections[MAX_CONNECTIONS];
    int num_devices = 0;
    int num_connections = 0;

    // Add devices to the network
    strcpy(devices[num_devices].name, "Router 1");
    devices[num_devices].id = num_devices;
    num_devices++;

    strcpy(devices[num_devices].name, "Switch 1");
    devices[num_devices].id = num_devices;
    num_devices++;

    strcpy(devices[num_devices].name, "Laptop 1");
    devices[num_devices].id = num_devices;
    num_devices++;

    strcpy(devices[num_devices].name, "Desktop 1");
    devices[num_devices].id = num_devices;
    num_devices++;

    // Add connections between devices
    connections[num_connections].from = devices[0].id;
    connections[num_connections].to = devices[1].id;
    num_connections++;

    connections[num_connections].from = devices[1].id;
    connections[num_connections].to = devices[2].id;
    num_connections++;

    connections[num_connections].from = devices[1].id;
    connections[num_connections].to = devices[3].id;
    num_connections++;

    // Print out the network topology
    printf("Network Topology:\n");
    for (int i = 0; i < num_connections; i++) {
        printf("%s -> %s\n", devices[connections[i].from].name, devices[connections[i].to].name);
    }

    return 0;
}