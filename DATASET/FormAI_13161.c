//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define a structure for a network device
struct Device {
    char name[20];
    char ipAddress[16];
    int numPorts;
};

// Define a structure for a connection between devices
struct Connection {
    char device1[20];
    char device2[20];
    int port1;
    int port2;
};

// Define a function to print out device information
void printDevice(struct Device dev) {
    printf("Device name: %s\n", dev.name);
    printf("IP address: %s\n", dev.ipAddress);
    printf("Number of ports: %d\n", dev.numPorts);
}

// Define a function to print out connection information
void printConnection(struct Connection conn) {
    printf("Connection between %s port %d and %s port %d\n", conn.device1, conn.port1, conn.device2, conn.port2);
}

int main() {
    // Create an array of devices and connections
    struct Device devices[5];
    struct Connection connections[5];

    // Add some devices to the array
    strcpy(devices[0].name, "Router 1");
    strcpy(devices[0].ipAddress, "192.168.1.1");
    devices[0].numPorts = 4;

    strcpy(devices[1].name, "Switch 1");
    strcpy(devices[1].ipAddress, "192.168.1.2");
    devices[1].numPorts = 8;

    strcpy(devices[2].name, "PC 1");
    strcpy(devices[2].ipAddress, "192.168.1.3");
    devices[2].numPorts = 1;

    strcpy(devices[3].name, "Router 2");
    strcpy(devices[3].ipAddress, "192.168.2.1");
    devices[3].numPorts = 4;

    strcpy(devices[4].name, "Switch 2");
    strcpy(devices[4].ipAddress, "192.168.2.2");
    devices[4].numPorts = 8;

    // Add some connections to the array
    strcpy(connections[0].device1, "Router 1");
    strcpy(connections[0].device2, "Switch 1");
    connections[0].port1 = 1;
    connections[0].port2 = 1;

    strcpy(connections[1].device1, "Switch 1");
    strcpy(connections[1].device2, "PC 1");
    connections[1].port1 = 2;
    connections[1].port2 = 1;

    strcpy(connections[2].device1, "Router 2");
    strcpy(connections[2].device2, "Switch 2");
    connections[2].port1 = 1;
    connections[2].port2 = 1;

    strcpy(connections[3].device1, "Switch 2");
    strcpy(connections[3].device2, "PC 1");
    connections[3].port1 = 2;
    connections[3].port2 = 1;

    strcpy(connections[4].device1, "Switch 1");
    strcpy(connections[4].device2, "Switch 2");
    connections[4].port1 = 3;
    connections[4].port2 = 3;

    // Print out the network topology
    printf("*** Network Topology ***\n");

    for(int i=0; i<5; i++) {
        printDevice(devices[i]);
        printf("\n");
    }

    for(int i=0; i<5; i++) {
        printConnection(connections[i]);
    }

    return 0;
}