//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_DEVICES 50
#define MAX_EDGES 100

// Device structure to hold basic info
typedef struct Device {
    char name[20];
    char ip[20];
    char type[20];
} Device;

// Edge structure to hold connection info
typedef struct Edge {
    Device* dev1;
    Device* dev2;
} Edge;

// Global arrays to hold all devices and edges
Device devices[MAX_DEVICES];
Edge edges[MAX_EDGES];

// Global variables to keep track of number of devices and edges
int numDevices = 0;
int numEdges = 0;

// Function to add a new device to the devices array
void addDevice(char* name, char* ip, char* type) {
    Device newDev;
    strcpy(newDev.name, name);
    strcpy(newDev.ip, ip);
    strcpy(newDev.type, type);
    devices[numDevices++] = newDev;
}

// Function to add a new edge to the edges array
void addEdge(Device* dev1, Device* dev2) {
    Edge newEdge;
    newEdge.dev1 = dev1;
    newEdge.dev2 = dev2;
    edges[numEdges++] = newEdge;
}

// Function to print all devices and their connections
void printTopology() {
    printf("Network Topology:\n");
    for (int i = 0; i < numDevices; i++) {
        printf("Name: %s\tIP: %s\tType: %s\tConnections: ", devices[i].name, devices[i].ip, devices[i].type);
        for (int j = 0; j < numEdges; j++) {
            if (edges[j].dev1 == &devices[i]) {
                printf("%s ", edges[j].dev2->name);
            } else if (edges[j].dev2 == &devices[i]) {
                printf("%s ", edges[j].dev1->name);
            }
        }
        printf("\n");
    }
}

// Example program to demonstrate the use of the network topology mapper
int main() {
    // Add some devices to the network
    addDevice("Router", "192.168.1.1", "Router");
    addDevice("Laptop", "192.168.1.2", "PC");
    addDevice("Printer", "192.168.1.3", "Printer");

    // Add some edges to the network
    addEdge(&devices[0], &devices[1]);
    addEdge(&devices[0], &devices[2]);

    // Print the topology
    printTopology();

    return 0;
}