//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORK_DEVICES 100
#define MAX_NETWORK_CONNECTIONS 1000

typedef struct NetworkDevice {
    char name[50];
    char ip[20];
} NetworkDevice;

typedef struct NetworkConnection {
    NetworkDevice* fromDevice;
    NetworkDevice* toDevice;
    int latency;
} NetworkConnection;

typedef struct NetworkMap {
    NetworkDevice devices[MAX_NETWORK_DEVICES];
    NetworkConnection connections[MAX_NETWORK_CONNECTIONS];
    int numDevices;
    int numConnections;
} NetworkMap;

void addDevice(NetworkMap* map, char* name, char* ip) {
    if (map->numDevices == MAX_NETWORK_DEVICES) {
        printf("Maximum number of devices reached.\n");
        return;
    }
    
    NetworkDevice newDevice;
    strncpy(newDevice.name, name, 50);
    strncpy(newDevice.ip, ip, 20);
    
    map->devices[map->numDevices++] = newDevice;
    
    printf("Device added successfully.\n");
}

void addConnection(NetworkMap* map, char* fromDeviceName, char* toDeviceName, int latency) {
    NetworkDevice* fromDevice = NULL;
    NetworkDevice* toDevice = NULL;
    
    for (int i = 0; i < map->numDevices; i++) {
        if (strcmp(map->devices[i].name, fromDeviceName) == 0) {
            fromDevice = &map->devices[i];
        } else if (strcmp(map->devices[i].name, toDeviceName) == 0) {
            toDevice = &map->devices[i];
        }
        
        if (fromDevice != NULL && toDevice != NULL) {
            break;
        }
    }
    
    if (fromDevice == NULL || toDevice == NULL) {
        printf("Could not find one or more devices.\n");
        return;
    }
    
    if (map->numConnections == MAX_NETWORK_CONNECTIONS) {
        printf("Maximum number of connections reached.\n");
        return;
    }
    
    NetworkConnection newConnection;
    newConnection.fromDevice = fromDevice;
    newConnection.toDevice = toDevice;
    newConnection.latency = latency;
    
    map->connections[map->numConnections++] = newConnection;
    
    printf("Connection added successfully.\n");
}

void printMap(NetworkMap* map) {
    printf("------------Network Map------------\n");
    
    for (int i = 0; i < map->numDevices; i++) {
        printf("Device: %s (%s)\n", map->devices[i].name, map->devices[i].ip);
    }
    
    printf("\n");
    
    for (int i = 0; i < map->numConnections; i++) {
        printf("Connection: %s (%s) - %dms - %s (%s)\n",
               map->connections[i].fromDevice->name,
               map->connections[i].fromDevice->ip,
               map->connections[i].latency,
               map->connections[i].toDevice->name,
               map->connections[i].toDevice->ip);
    }
    
    printf("-----------------------------------\n");
}

int main() {
    NetworkMap map;
    map.numDevices = 0;
    map.numConnections = 0;
    
    addDevice(&map, "Router 1", "192.168.0.1");
    addDevice(&map, "Switch 1", "192.168.0.2");
    addDevice(&map, "PC 1", "192.168.0.3");
    addDevice(&map, "PC 2", "192.168.0.4");
    addDevice(&map, "Server 1", "192.168.0.5");
    addDevice(&map, "Router 2", "192.168.1.1");
    addDevice(&map, "Switch 2", "192.168.1.2");
    addDevice(&map, "PC 3", "192.168.1.3");
    
    addConnection(&map, "Router 1", "Switch 1", 10);
    addConnection(&map, "Switch 1", "PC 1", 5);
    addConnection(&map, "Switch 1", "PC 2", 5);
    addConnection(&map, "Switch 1", "Server 1", 20);
    addConnection(&map, "Router 2", "Switch 2", 10);
    addConnection(&map, "Switch 2", "PC 3", 5);
    addConnection(&map, "Router 1", "Router 2", 50);
    
    printMap(&map);
    
    return 0;
}