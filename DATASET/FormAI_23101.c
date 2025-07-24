//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_DEVICES 1000 // Maximum number of devices in the network
#define MAX_NEIGHBORS 10 // Maximum number of neighbours a device can have
#define BUF_SIZE 256 // Maximum size of buffer used for data transfer

// Structure to represent a device in the network
typedef struct device_t {
    char* ip;
    int name;
    int num_neighbors;
    struct device_t* neighbors[MAX_NEIGHBORS];
} device;

device network[MAX_DEVICES]; // Array to store all devices in the network
int num_devices = 0; // Number of devices in the network

// Function to add a new device to the network
void addDevice(char* ip, int name) {
    if (num_devices == MAX_DEVICES) {
        fprintf(stderr, "Max network size reached!\n");
        exit(1);
    }
    device* new_device = (device*) malloc(sizeof(device));
    new_device->ip = (char*) malloc(strlen(ip) + 1);
    strcpy(new_device->ip, ip);
    new_device->name = name;
    new_device->num_neighbors = 0;
    network[num_devices++] = *new_device;
}

// Function to add a neighbor to a device in the network
void addNeighbor(int device1, int device2) {
    if (device1 < 0 || device1 >= num_devices || device2 < 0 || device2 >= num_devices) {
        fprintf(stderr, "Invalid device number!\n");
        exit(1);
    }
    if (network[device1].num_neighbors == MAX_NEIGHBORS) {
        fprintf(stderr, "Max number of neighbors reached for device %d!\n", device1);
        exit(1);
    }
    if (network[device2].num_neighbors == MAX_NEIGHBORS) {
        fprintf(stderr, "Max number of neighbors reached for device %d!\n", device2);
        exit(1);
    }
    network[device1].neighbors[network[device1].num_neighbors++] = &network[device2];
    network[device2].neighbors[network[device2].num_neighbors++] = &network[device1];
}

// Function to print the network
void printNetwork() {
    int i, j;
    for (i = 0; i < num_devices; i++) {
        printf("Device %d: %s\n", network[i].name, network[i].ip);
        printf("Neighbors: ");
        for (j = 0; j < network[i].num_neighbors; j++) {
            printf("%d ", network[i].neighbors[j]->name);
        }
        printf("\n\n");
    }
}

int main() {
    // Add devices to the network
    addDevice("192.168.0.1", 1);
    addDevice("192.168.0.2", 2);
    addDevice("192.168.0.3", 3);
    addDevice("192.168.0.4", 4);
    addDevice("192.168.0.5", 5);

    // Add neighbors to the devices
    addNeighbor(0, 1);
    addNeighbor(0, 3);
    addNeighbor(1, 2);
    addNeighbor(1, 3);
    addNeighbor(2, 3);
    addNeighbor(2, 4);
    addNeighbor(3, 4);

    // Print the network
    printNetwork();

    return 0;
}