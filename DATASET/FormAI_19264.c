//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 16
#define MAX_CONNECTIONS 32

// Define a device struct
typedef struct {
    char* name;
    int id;
    int num_connections;
    int connections[MAX_CONNECTIONS];
} device;

// Define the main network struct
typedef struct {
    device devices[MAX_DEVICES];
    int num_devices;
} network;

// Initialize the network struct
void init_network(network* net) {
    net->num_devices = 0;
}

// Add a device to the network
void add_device(network* net, char* name) {
    if (net->num_devices >= MAX_DEVICES) {
        printf("Error: network has reached maximum device capacity.\n");
        return;
    }
    device new_device;
    new_device.name = (char*) malloc(strlen(name) + 1);
    strcpy(new_device.name, name);
    new_device.id = net->num_devices;
    new_device.num_connections = 0;
    net->devices[net->num_devices] = new_device;
    net->num_devices++;
}

// Add a connection between two devices
void add_connection(network* net, int device_id_1, int device_id_2) {
    if (device_id_1 < 0 || device_id_1 >= net->num_devices
            || device_id_2 < 0 || device_id_2 >= net->num_devices) {
        printf("Error: one or both device IDs are invalid.\n");
        return;
    }
    if (net->devices[device_id_1].num_connections >= MAX_CONNECTIONS
            || net->devices[device_id_2].num_connections >= MAX_CONNECTIONS) {
        printf("Error: one or both devices have reached maximum connection capacity.\n");
        return;
    }
    net->devices[device_id_1].connections[net->devices[device_id_1].num_connections] = device_id_2;
    net->devices[device_id_1].num_connections++;

    net->devices[device_id_2].connections[net->devices[device_id_2].num_connections] = device_id_1;
    net->devices[device_id_2].num_connections++;
}

// Recursive function to traverse the network and print connections
void follow_connections(network* net, int device_id, int* visited) {
    int i;
    visited[device_id] = 1;
    printf("%s (%d) is connected to:", net->devices[device_id].name, device_id);

    device current_device = net->devices[device_id];
    for (i = 0; i < current_device.num_connections; i++) {
        int other_device_id = current_device.connections[i];
        if (!visited[other_device_id]) {
            printf(" %s (%d)", net->devices[other_device_id].name, other_device_id);
            follow_connections(net, other_device_id, visited);
        }
    }
    printf("\n");
}

// Output the network in a readable format
void print_network(network* net) {
    int i, j;
    int visited[MAX_DEVICES];
    for (i = 0; i < net->num_devices; i++) {
        visited[i] = 0;
    }
    for (i = 0; i < net->num_devices; i++) {
        if (!visited[i]) {
            follow_connections(net, i, visited);
        }
    }
}

int main() {
    network net;
    init_network(&net);

    add_device(&net, "router");
    add_device(&net, "firewall");
    add_device(&net, "switch");
    add_device(&net, "server 1");
    add_device(&net, "server 2");
    add_device(&net, "printer");

    add_connection(&net, 0, 1);
    add_connection(&net, 1, 2);
    add_connection(&net, 2, 3);
    add_connection(&net, 2, 4);
    add_connection(&net, 2, 5);

    print_network(&net);

    return 0;
}