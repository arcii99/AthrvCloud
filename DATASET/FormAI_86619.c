//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 50

// Structure to hold information about a network device
typedef struct {
    char name[20];
} Device;

// Graph structure to represent network connections
typedef struct {
    int num_devices;
    Device devices[MAX_DEVICES];
    int connections[MAX_DEVICES][MAX_DEVICES];
} Network;

// Function to print the network topology
void print_network(Network network) {
    printf("Network Topology:\n\n");

    for (int i = 0; i < network.num_devices; i++) {
        printf("%s: ", network.devices[i].name);

        for (int j = 0; j < network.num_devices; j++) {
            if (network.connections[i][j] == 1) {
                printf("%s ", network.devices[j].name);
            }
        }

        printf("\n");
    }
}

int main() {
    // Initialize the network
    Network network;
    network.num_devices = 10;

    // Define the devices
    strcpy(network.devices[0].name, "Device 1");
    strcpy(network.devices[1].name, "Device 2");
    strcpy(network.devices[2].name, "Device 3");
    strcpy(network.devices[3].name, "Device 4");
    strcpy(network.devices[4].name, "Device 5");
    strcpy(network.devices[5].name, "Device 6");
    strcpy(network.devices[6].name, "Device 7");
    strcpy(network.devices[7].name, "Device 8");
    strcpy(network.devices[8].name, "Device 9");
    strcpy(network.devices[9].name, "Device 10");

    // Randomly generate connections
    srand(time(NULL));
    for (int i = 0; i < network.num_devices; i++) {
        for (int j = i; j < network.num_devices; j++) {
            if (i == j) {
                network.connections[i][j] = 0;
            } else {
                network.connections[i][j] = network.connections[j][i] = rand() % 2;
            }
        }
    }

    // Print the network topology
    print_network(network);

    return 0;
}