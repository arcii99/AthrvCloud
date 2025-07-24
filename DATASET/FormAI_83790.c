//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 50
#define MAX_NAME_LENGTH 20

// Device struct to store information about each device
typedef struct Device {
    char name[MAX_NAME_LENGTH];
    int numConnections;
    struct Device* connections[MAX_DEVICES];
} Device;

// Array to store all devices in the network
Device devices[MAX_DEVICES];

// Function to connect two devices together
void connectDevices(Device* device1, Device* device2) {
    device1->connections[device1->numConnections++] = device2;
    device2->connections[device2->numConnections++] = device1;
}

// Function to print the network topology map
void printMap() {
    printf("\n\n================ NETWORK TOPOLOGY MAP ================\n\n");

    // Loop through all devices in the network
    for (int i = 0; i < MAX_DEVICES; i++) {
        // If device is not in the network, skip it
        if (strlen(devices[i].name) == 0) {
            continue;
        }

        // Print device name and number of connections
        printf("%s (%d connections):\n", devices[i].name, devices[i].numConnections);

        // Print each connected device's name and a line connecting them
        for (int j = 0; j < devices[i].numConnections; j++) {
            printf("     | - %s\n", devices[i].connections[j]->name);
        }
    }

    printf("\n=======================================================\n\n");
}

int main() {
    // Initialize all devices in the network
    for (int i = 0; i < MAX_DEVICES; i++) {
        devices[i].numConnections = 0;
    }

    // Create devices
    Device device1 = {"Router 1", 0};
    Device device2 = {"Switch 1", 0};
    Device device3 = {"Switch 2", 0};
    Device device4 = {"Server 1", 0};
    Device device5 = {"Printer 1", 0};

    // Connect devices
    connectDevices(&device1, &device2);
    connectDevices(&device1, &device3);
    connectDevices(&device2, &device4);
    connectDevices(&device3, &device4);
    connectDevices(&device3, &device5);

    // Add devices to the network
    devices[0] = device1;
    devices[1] = device2;
    devices[2] = device3;
    devices[3] = device4;
    devices[4] = device5;

    // Print network topology map
    printMap();

    return 0;
}