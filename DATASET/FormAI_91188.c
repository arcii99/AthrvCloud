//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_DEVICES 100
#define MAX_CONNECTIONS 100

typedef struct {
    int id;
    char name[20];
    bool is_router;
    bool is_switch;
} Device;

typedef struct {
    int from_device_id;
    int to_device_id;
    int cost;
} Connection;

int num_devices = 0;
int num_connections = 0;
Device network_devices[MAX_DEVICES];
Connection network_connections[MAX_CONNECTIONS];

void add_device(char* name, bool is_router, bool is_switch) {
    Device new_device = {num_devices, "", is_router, is_switch};
    strncpy(new_device.name, name, sizeof(new_device.name) - 1);
    network_devices[num_devices++] = new_device;
}

void add_connection(int from_device_id, int to_device_id, int cost) {
    Connection new_connection = {from_device_id, to_device_id, cost};
    network_connections[num_connections++] = new_connection;
}

void print_device(Device device) {
    printf("Device %d: %s\n", device.id, device.name);
    if (device.is_router) {
        printf("  - Router\n");
    }
    if (device.is_switch) {
        printf("  - Switch\n");
    }
}

void print_connection(Connection connection) {
    printf("Connection %d: %d -> %d (cost: %d)\n", connection.from_device_id,
           connection.to_device_id, connection.cost);
}

void print_network() {
    printf("Network Topology:\n");
    printf("------------------\n");
    for (int i = 0; i < num_devices; i++) {
        print_device(network_devices[i]);
    }
    printf("\n");
    for (int i = 0; i < num_connections; i++) {
        print_connection(network_connections[i]);
    }
}

int main() {
    printf("Adding devices to network...\n");
    add_device("PC-1", false, false);
    add_device("Router-1", true, false);
    add_device("Switch-1", false, true);
    add_device("PC-2", false, false);
    
    printf("Adding connections to network...\n");
    add_connection(0, 1, 10);
    add_connection(0, 2, 5);
    add_connection(1, 3, 3);
    add_connection(2, 3, 1);
    
    print_network();
    
    return 0;
}