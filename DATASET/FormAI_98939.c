//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 100
#define MAX_NAME_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    int num_ports;
    int connected_ports[MAX_DEVICES];
} Device;

typedef struct {
    Device devices[MAX_DEVICES];
    int num_devices;
} Network;

void add_device(Network *network, char *name, int num_ports, int *connected_ports) {
    Device device;
    strncpy(device.name, name, MAX_NAME_LEN);
    device.num_ports = num_ports;
    memcpy(device.connected_ports, connected_ports, num_ports * sizeof(int));
    network->devices[network->num_devices] = device;
    network->num_devices++;
}

void print_network_topology(Network *network) {
    printf("Network Topology:\n");
    for (int i = 0; i < network->num_devices; i++) {
        printf("%s:\n", network->devices[i].name);
        for (int j = 0; j < network->devices[i].num_ports; j++) {
            int connected_port = network->devices[i].connected_ports[j];
            if (connected_port != -1) {
                printf("  Port %d is connected to %s's port %d\n", j+1, network->devices[connected_port].name, find_port(network, connected_port, i)+1);
            } else {
                printf("  Port %d is not connected\n", j+1);
            }
        }
    }
}

int find_port(Network *network, int device_index, int connected_device_index) {
    Device device = network->devices[device_index];
    for (int i = 0; i < device.num_ports; i++) {
        if (device.connected_ports[i] == connected_device_index) {
            return i;
        }
    }
    return -1;
}

int main() {
    Network network;
    network.num_devices = 0;

    int connected_ports1[] = {-1, 1, -1, -1};
    add_device(&network, "Switch1", 4, connected_ports1);

    int connected_ports2[] = {0, 2, 4, -1};
    add_device(&network, "Router1", 3, connected_ports2);

    int connected_ports3[] = {1, -1, 3, -1};
    add_device(&network, "Switch2", 3, connected_ports3);

    int connected_ports4[] = {2, -1, -1, 0};
    add_device(&network, "Server1", 4, connected_ports4);

    print_network_topology(&network);

    return 0;
}