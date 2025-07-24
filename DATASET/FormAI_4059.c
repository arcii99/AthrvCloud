//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_DEVICES 100
#define MAX_CONNECTIONS 50

// Define a struct to store a device's information
struct Device {
    char name[50];
    char ip[15];
    char mac[17];
    int num_connections;
    int connections[MAX_CONNECTIONS];
};

// Declare global variables
struct Device devices[MAX_DEVICES];
int num_devices = 0;

// Declare function prototypes
void addDevice(char *name, char *ip, char *mac);
void addConnection(int device1, int device2);
void printTopology();

int main() {
    // add some sample devices to the network
    addDevice("Router", "192.168.0.1", "AA:BB:CC:DD:EE:FF");
    addDevice("Desktop", "192.168.0.10", "11:22:33:44:55:66");
    addDevice("Laptop", "192.168.0.11", "77:88:99:AA:BB:CC");

    // create some sample connections
    addConnection(0, 1); // Router connected to Desktop
    addConnection(0, 2); // Router connected to Laptop

    // print the network topology
    printTopology();

    // exit program
    return 0;
}

// function to add a new device to the network
void addDevice(char *name, char *ip, char *mac) {
    // check if we have reached maximum number of devices
    if (num_devices >= MAX_DEVICES) {
        printf("Error: maximum number of devices reached\n");
        return;
    }

    // create a new Device object and copy the values
    struct Device new_device;
    strcpy(new_device.name, name);
    strcpy(new_device.ip, ip);
    strcpy(new_device.mac, mac);
    new_device.num_connections = 0;

    // add the new device to the devices array
    devices[num_devices] = new_device;

    // increment the number of devices
    num_devices++;
}

// function to add a new connection between two devices
void addConnection(int device1, int device2) {
    // check if the devices are in range
    if (device1 >= num_devices || device2 >= num_devices) {
        printf("Error: devices out of range\n");
        return;
    }

    // add the connections (in both directions)
    devices[device1].connections[devices[device1].num_connections++] = device2;
    devices[device2].connections[devices[device2].num_connections++] = device1;
}

// function to print the network topology
void printTopology() {
    // print the header
    printf("\nNetwork Topology\n");

    // loop through all devices
    for (int i = 0; i < num_devices; i++) {
        // print the device name, IP address and MAC address
        printf("%s (%s) [%s]\n", devices[i].name, devices[i].ip, devices[i].mac);

        // loop through all connections for this device
        for (int j = 0; j < devices[i].num_connections; j++) {
            // print the connection information
            int connected_device = devices[i].connections[j];
            printf("  connected to %s (%s) [%s]\n", devices[connected_device].name, devices[connected_device].ip, devices[connected_device].mac);
        }

        // print an extra newline for readability
        printf("\n");
    }
}