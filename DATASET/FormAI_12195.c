//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DEVICES 100 // Maximum number of network devices
#define MAX_CONNECTIONS 500 // Maximum number of connections between devices

// Structure to hold information about each network device
typedef struct {
    int id;
    char name[20];
    char ip_address[16];
} Device;

// Structure to hold information about network topology
typedef struct {
    Device devices[MAX_DEVICES];
    int num_devices;
    int connections[MAX_DEVICES][MAX_DEVICES];
    int num_connections;
} NetworkTopology;

// Function to add a new device to the network topology
void add_device(NetworkTopology *topology, char *name, char *ip_address) {
    Device device;
    device.id = topology->num_devices + 1;
    strcpy(device.name, name);
    strcpy(device.ip_address, ip_address);
    topology->devices[topology->num_devices++] = device;
}

// Function to add a new connection between devices
void add_connection(NetworkTopology *topology, int device_id_1, int device_id_2) {
    topology->connections[device_id_1 - 1][device_id_2 - 1] = 1;
    topology->connections[device_id_2 - 1][device_id_1 - 1] = 1;
    topology->num_connections++;
}

// Function to print the entire network topology
void print_topology(NetworkTopology *topology) {
    printf("Network Topology:\n\n");

    // Print device information
    printf("Devices:\n\n");
    for (int i = 0; i < topology->num_devices; i++) {
        printf("%d. %s (%s)\n", topology->devices[i].id, topology->devices[i].name, topology->devices[i].ip_address);
    }

    // Print connection information
    printf("\nConnections:\n\n");
    for (int i = 0; i < topology->num_devices; i++) {
        for (int j = i + 1; j < topology->num_devices; j++) {
            if (topology->connections[i][j]) {
                printf("%s (%s) <--> %s (%s)\n", topology->devices[i].name, topology->devices[i].ip_address, topology->devices[j].name, topology->devices[j].ip_address);
            }
        }
    }
}

int main() {
    NetworkTopology topology;
    topology.num_devices = 0;
    topology.num_connections = 0;

    // Add devices to the network topology
    add_device(&topology, "Device 1", "192.168.0.1");
    add_device(&topology, "Device 2", "192.168.0.2");
    add_device(&topology, "Device 3", "192.168.0.3");
    add_device(&topology, "Device 4", "192.168.0.4");

    // Add connections between devices
    add_connection(&topology, 1, 2);
    add_connection(&topology, 1, 3);
    add_connection(&topology, 2, 4);
    add_connection(&topology, 3, 4);

    // Print the entire network topology
    print_topology(&topology);

    return 0;
}