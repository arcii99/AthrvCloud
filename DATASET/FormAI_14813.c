//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define a maximum number of devices to be mapped
#define MAX_DEVICES 10

// Define the Device structure
struct Device {
    char name[20];
    char ip[15];
    char mac[18];
    bool isUp;
};

// Define the topology structure
struct Topology {
    struct Device devices[MAX_DEVICES];
    unsigned int numDevices;
};

// Define a function to add a device to the topology
void addDevice(struct Device *device, struct Topology *topology) {
    topology->devices[topology->numDevices] = *device;
    topology->numDevices++;
}

// Define a function to print the topology
void printTopology(struct Topology *topology) {
    printf("Topology:\n");
    for (int i = 0; i < topology->numDevices; i++) {
        printf("%s (%s, %s)", topology->devices[i].name, topology->devices[i].ip, topology->devices[i].mac);
        if (!topology->devices[i].isUp) printf(" - Device is down");
        printf("\n");
    }
}

int main() {
    // Create the topology object
    struct Topology topology = {};
    
    // Create the devices
    struct Device device1 = {"Router", "192.168.1.1", "00:01:02:03:04:05", true};
    struct Device device2 = {"Switch", "192.168.1.2", "06:07:08:09:0a:0b", true};
    struct Device device3 = {"Server", "192.168.1.3", "0c:0d:0e:0f:10:11", false};
    
    // Add the devices to the topology
    addDevice(&device1, &topology);
    addDevice(&device2, &topology);
    addDevice(&device3, &topology);
    
    // Print the topology
    printTopology(&topology);
    
    return 0;
}