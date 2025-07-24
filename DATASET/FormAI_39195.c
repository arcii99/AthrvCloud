//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 50

// Define a structure to hold device information
typedef struct device {
    char name[20];
    int id;
    int connected_devices[MAX_DEVICES];
    int num_connections;
} Device;

// Function to add a connection between two devices
void add_connection(Device *device1, Device *device2) {
    device1->connected_devices[device1->num_connections] = device2->id;
    device2->connected_devices[device2->num_connections] = device1->id;
    device1->num_connections++;
    device2->num_connections++;
}

int main() {
    // Create an array of devices and initialize them
    Device devices[5];
    strcpy(devices[0].name, "Router");
    devices[0].id = 0;
    devices[0].num_connections = 0;

    strcpy(devices[1].name, "Switch");
    devices[1].id = 1;
    devices[1].num_connections = 0;

    strcpy(devices[2].name, "Server");
    devices[2].id = 2;
    devices[2].num_connections = 0;

    strcpy(devices[3].name, "Desktop");
    devices[3].id = 3;
    devices[3].num_connections = 0;

    strcpy(devices[4].name, "Laptop");
    devices[4].id = 4;
    devices[4].num_connections = 0;

    // Add connections between devices
    add_connection(&devices[0], &devices[1]);
    add_connection(&devices[0], &devices[2]);
    add_connection(&devices[1], &devices[3]);
    add_connection(&devices[1], &devices[4]);
    add_connection(&devices[3], &devices[4]);

    // Print out the network topology
    printf("Network Topology:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s (ID: %d)", devices[i].name, devices[i].id);
        printf(" is connected to:");
        for (int j = 0; j < devices[i].num_connections; j++) {
            printf(" %d", devices[i].connected_devices[j]);
        }
        printf("\n");
    }

    return 0;
}