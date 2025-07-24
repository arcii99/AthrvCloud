//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 20
#define MAX_IP_LENGTH 16

typedef struct {
    char name[MAX_NAME_LENGTH];
    char ip[MAX_IP_LENGTH];
    bool connected;
} Device;

typedef struct {
    Device devices[10];
    int num_devices;
} Network;

void add_device(Network* network, char* name, char* ip) {
    if (network->num_devices < 10) {
        strcpy(network->devices[network->num_devices].name, name);
        strcpy(network->devices[network->num_devices].ip, ip);
        network->devices[network->num_devices].connected = true;
        network->num_devices++;
    }
}

void connect_devices(Network* network, int device1_index, int device2_index) {
    network->devices[device1_index].connected = true;
    network->devices[device2_index].connected = true;
}

void print_network(Network network) {
    printf("Network Topology:\n");
    for (int i = 0; i < network.num_devices; i++) {
        Device device = network.devices[i];
        printf("%s (%s)", device.name, device.ip);
        if (device.connected) {
            printf(" --> ");
        } else {
            printf(" [UNCONNECTED] --> ");
        }
    }
    printf("END\n");
}

int main() {
    Network network = {0};

    add_device(&network, "Router", "192.168.1.1");
    add_device(&network, "Switch 1", "192.168.1.2");
    add_device(&network, "Switch 2", "192.168.1.3");
    add_device(&network, "PC 1", "192.168.1.4");
    add_device(&network, "PC 2", "192.168.1.5");

    connect_devices(&network, 0, 1);
    connect_devices(&network, 1, 2);
    connect_devices(&network, 2, 3);
    connect_devices(&network, 2, 4);

    print_network(network);

    return 0;
}