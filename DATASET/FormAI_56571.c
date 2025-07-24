//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: high level of detail
#include <stdio.h>
#include <string.h>

#define MAX_DEVICES 100 // Maximum number of devices in network
#define MAX_CONNECTIONS 200 // Maximum number of connections between devices

typedef struct {
    char name[20];
    char ip_address[15];
} device_t;

typedef struct {
    device_t source;
    device_t destination;
} connection_t;

int num_devices = 0; // Current number of devices in network
int num_connections = 0; // Current number of connections between devices

device_t devices[MAX_DEVICES];
connection_t connections[MAX_CONNECTIONS];

void add_device(char* name, char* ip_address) {
    if (num_devices >= MAX_DEVICES) {
        printf("Maximum number of devices reached!\n");
        return;
    }
    
    // Check if device already exists
    int i;
    for (i = 0; i < num_devices; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            printf("Device with name %s already exists!\n", name);
            return;
        }
    }
    
    device_t new_device;
    strcpy(new_device.name, name);
    strcpy(new_device.ip_address, ip_address);
    
    devices[num_devices] = new_device;
    num_devices++;
    
    printf("Device added successfully!\n");
}

void add_connection(char* source_name, char* destination_name) {
    // Check if devices exist
    int i;
    int source_index = -1;
    int destination_index = -1;
    for (i = 0; i < num_devices; i++) {
        if (strcmp(devices[i].name, source_name) == 0) {
            source_index = i;
        }
        if (strcmp(devices[i].name, destination_name) == 0) {
            destination_index = i;
        }
    }
    if (source_index == -1) {
        printf("Device with name %s does not exist!\n", source_name);
        return;
    }
    if (destination_index == -1) {
        printf("Device with name %s does not exist!\n", destination_name);
        return;
    }
    
    // Check if connection already exists
    for (i = 0; i < num_connections; i++) {
        if (strcmp(connections[i].source.name, source_name) == 0 &&
            strcmp(connections[i].destination.name, destination_name) == 0) {
            printf("Connection already exists!\n");
            return;
        }
    }
    
    connection_t new_connection;
    new_connection.source = devices[source_index];
    new_connection.destination = devices[destination_index];
    
    connections[num_connections] = new_connection;
    num_connections++;
    
    printf("Connection added successfully!\n");
}

void print_network() {
    int i;
    printf("Devices:\n");
    for (i = 0; i < num_devices; i++) {
        printf("%s (%s)\n", devices[i].name, devices[i].ip_address);
    }
    printf("\nConnections:\n");
    for (i = 0; i < num_connections; i++) {
        printf("%s -- %s\n", connections[i].source.name, connections[i].destination.name);
    }
}

int main() {
    add_device("Router 1", "192.168.0.1");
    add_device("PC 1", "192.168.0.2");
    add_device("PC 2", "192.168.0.3");
    
    add_connection("Router 1", "PC 1");
    add_connection("Router 1", "PC 2");
    
    print_network();
    
    return 0;
}