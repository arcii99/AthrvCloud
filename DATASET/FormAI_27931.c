//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 1000
#define MAX_CONNECTIONS 5000

int deviceIndex = 0;
int connectionIndex = 0;

struct Device {
    char name[100];
    char ip[16];
    char type[50];
};

struct Connection {
    int device1Index;
    int device2Index;
};

struct Device devices[MAX_DEVICES];
struct Connection connections[MAX_CONNECTIONS];

void addDevice(char *name, char *ip, char *type) {
    if (deviceIndex < MAX_DEVICES) {
        strcpy(devices[deviceIndex].name, name);
        strcpy(devices[deviceIndex].ip, ip);
        strcpy(devices[deviceIndex].type, type);
        deviceIndex++;
    } else {
        printf("ERROR: Max device limit reached!\n");
    }
}

void addConnection(int device1Index, int device2Index) {
    if (connectionIndex < MAX_CONNECTIONS) {
        connections[connectionIndex].device1Index = device1Index;
        connections[connectionIndex].device2Index = device2Index;
        connectionIndex++;
    } else {
        printf("ERROR: Max connection limit reached!\n");
    }
}

void printDevices() {
    printf("Devices:\n");
    for (int i = 0; i < deviceIndex; i++) {
        printf("- Name: %s, IP: %s, Type: %s\n", devices[i].name, devices[i].ip, devices[i].type);
    }
}

void printConnections() {
    printf("Connections:\n");
    for (int i = 0; i < connectionIndex; i++) {
        printf("- Device 1: %s (%s), Device 2: %s (%s)\n", 
            devices[connections[i].device1Index].name, devices[connections[i].device1Index].type,
            devices[connections[i].device2Index].name, devices[connections[i].device2Index].type
        );
    }
}

int main() {
    addDevice("Router1", "192.168.0.1", "Router");
    addDevice("Switch1", "192.168.0.2", "Switch");
    addDevice("Server1", "192.168.0.3", "Server");
    addDevice("Server2", "192.168.0.4", "Server");
    addDevice("PC1", "192.168.0.5", "PC");
    addDevice("PC2", "192.168.0.6", "PC");
    
    addConnection(0, 1); // Router1 to Switch1
    addConnection(1, 2); // Switch1 to Server1
    addConnection(1, 3); // Switch1 to Server2
    addConnection(4, 1); // PC1 to Switch1
    addConnection(5, 1); // PC2 to Switch1
    
    printDevices();
    printf("\n");
    printConnections();
    
    return 0;
}