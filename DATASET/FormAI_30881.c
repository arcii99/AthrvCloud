//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DEVICES 100
#define MAX_CONNECTIONS 1000

struct device {
    char name[50];
    int num_ports;
    int ports[10];
};

struct connection {
    int device1;
    int port1;
    int device2;
    int port2;
};

int num_devices = 0;
struct device devices[MAX_DEVICES];

int num_connections = 0;
struct connection connections[MAX_CONNECTIONS];

int find_device_index(char *name) {
    int i;
    for (i = 0; i < num_devices; i++) {
        if (strcmp(name, devices[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

void add_device(char *name, int num_ports) {
    int index = find_device_index(name);
    if (index >= 0) {
        printf("Device %s already exists!\n", name);
    } else if (num_devices >= MAX_DEVICES) {
        printf("Maximum number of devices exceeded!\n");
    } else {
        struct device new_device;
        strcpy(new_device.name, name);
        new_device.num_ports = num_ports;
        int i;
        for (i = 0; i < num_ports; i++) {
            new_device.ports[i] = -1;
        }
        devices[num_devices] = new_device;
        num_devices++;
        printf("Device %s added!\n", name);
    }
}

void add_connection(char *device1_name, int port1, char *device2_name, int port2) {
    int device1_index = find_device_index(device1_name);
    int device2_index = find_device_index(device2_name);
    if (device1_index == -1) {
        printf("Device %s not found!\n", device1_name);
    } else if (device2_index == -1) {
        printf("Device %s not found!\n", device2_name);
    } else if (devices[device1_index].num_ports <= port1) {
        printf("Port %d does not exist on device %s!\n", port1, device1_name);
    } else if (devices[device2_index].num_ports <= port2) {
        printf("Port %d does not exist on device %s!\n", port2, device2_name);
    } else if (num_connections >= MAX_CONNECTIONS) {
        printf("Maximum number of connections exceeded!\n");
    } else if (devices[device1_index].ports[port1] != -1) {
        printf("Port %d on device %s is already connected!\n", port1, device1_name);
    } else if (devices[device2_index].ports[port2] != -1) {
        printf("Port %d on device %s is already connected!\n", port2, device2_name);
    } else {
        struct connection new_connection;
        new_connection.device1 = device1_index;
        new_connection.port1 = port1;
        new_connection.device2 = device2_index;
        new_connection.port2 = port2;
        devices[device1_index].ports[port1] = num_connections;
        devices[device2_index].ports[port2] = num_connections;
        connections[num_connections] = new_connection;
        num_connections++;
        printf("Connection between %s:%d and %s:%d established!\n", device1_name, port1, device2_name, port2);
    }
}

void print_topology() {
    printf("Network Topology:\n");
    int i;
    for (i = 0; i < num_connections; i++) {
        struct connection current = connections[i];
        printf("%s:%d -> %s:%d\n", devices[current.device1].name, current.port1, devices[current.device2].name, current.port2);
    }
}

int main() {
    add_device("Switch 1", 3);
    add_device("Router 1", 2);
    add_device("Server 1", 4);
    add_device("Workstation 1", 1);
    add_connection("Switch 1", 0, "Router 1", 0);
    add_connection("Switch 1", 1, "Server 1", 1);
    add_connection("Router 1", 1, "Server 1", 0);
    add_connection("Server 1", 2, "Workstation 1", 0);
    print_topology();
    return 0;
}