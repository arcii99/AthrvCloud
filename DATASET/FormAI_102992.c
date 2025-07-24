//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 50

// The Device struct stores device information
typedef struct {
    char name[20];
    char ip[16];
    int num_connections;
    int connected_devices[MAX_DEVICES];
} Device;

// The Network struct stores the entire network topology
typedef struct {
    Device devices[MAX_DEVICES];
    int num_devices;
} Network;

// Initializes a device with the given name and IP address
Device init_device(char *name, char *ip) {
    Device device;
    strcpy(device.name, name);
    strcpy(device.ip, ip);
    device.num_connections = 0;
    return device;
}

// Adds a connection between two devices based on their indices in the network array
void add_connection(Network *network, int index1, int index2) {
    if (network->devices[index1].num_connections < MAX_DEVICES && 
        network->devices[index2].num_connections < MAX_DEVICES) {
        network->devices[index1].connected_devices[network->devices[index1].num_connections] = index2;
        network->devices[index1].num_connections++;
        network->devices[index2].connected_devices[network->devices[index2].num_connections] = index1;
        network->devices[index2].num_connections++;
    } else {
        printf("ERROR: Maximum number of connections reached for one or both devices.\n");
    }
}

// Maps the entire network topology based on connections between devices
void map_network(Network *network) {
    printf("Mapping network topology...\n");
    for (int i = 0; i < network->num_devices; i++) {
        printf("%s (%s) is connected to:\n", network->devices[i].name, network->devices[i].ip);
        for (int j = 0; j < network->devices[i].num_connections; j++) {
            int connected_device_index = network->devices[i].connected_devices[j];
            printf("   %s (%s)\n", network->devices[connected_device_index].name, network->devices[connected_device_index].ip);
        }
    }
}

int main(void) {
    Network network;
    network.num_devices = 0;

    // Add devices to the network
    network.devices[network.num_devices] = init_device("Router", "192.168.0.1");
    network.num_devices++;
    network.devices[network.num_devices] = init_device("Laptop", "192.168.0.2");
    network.num_devices++;
    network.devices[network.num_devices] = init_device("Desktop", "192.168.0.3");
    network.num_devices++;

    // Add connections between devices
    add_connection(&network, 0, 1);
    add_connection(&network, 0, 2);

    // Map the network topology
    map_network(&network);

    return 0;
}