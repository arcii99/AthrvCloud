//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DEVICES 50
#define MAX_CONNECTIONS 100

typedef struct {
    int id;
    char device_name[20];
    bool is_router;
    bool is_modem;
} Device;

typedef struct {
    int id1;
    int id2;
} Connection;

int device_count = 0;
int connection_count = 0;
Device devices[MAX_DEVICES];
Connection connections[MAX_CONNECTIONS];

void add_device(char name[], bool is_router, bool is_modem) {
    devices[device_count].id = device_count+1;
    strcpy(devices[device_count].device_name, name);
    devices[device_count].is_router = is_router;
    devices[device_count].is_modem = is_modem;
    device_count++;
}

void add_connection(int device_id1, int device_id2) {
    connections[connection_count].id1 = device_id1;
    connections[connection_count].id2 = device_id2;
    connection_count++;
}

void display_devices() {
    printf("ID  Device Name              Router      Modem\n");
    printf("----------------------------------------------\n");
    for (int i = 0; i < device_count; i++) {
        printf("%-3d %-22s %-10s %-5s\n", devices[i].id, devices[i].device_name, devices[i].is_router ? "YES" : "NO", devices[i].is_modem ? "YES" : "NO");
    }
    printf("\n");
}

void display_connections() {
    printf("Device 1               Device 2\n");
    printf("--------------------------------\n");
    for (int i = 0; i < connection_count; i++) {
        printf("%-22s %-22s\n", devices[connections[i].id1-1].device_name, devices[connections[i].id2-1].device_name);
    }
    printf("\n");
}

int main() {

    // Add some devices
    add_device("Router 1", true, false);
    add_device("Modem 1", false, true);
    add_device("Switch 1", false, false);
    add_device("Laptop 1", false, false);
    add_device("Desktop 1", false, false);
    add_device("Router 2", true, false);
    add_device("Modem 2", false, true);
    
    // Add some connections
    add_connection(1, 2);
    add_connection(1, 3);
    add_connection(3, 4);
    add_connection(3, 5);
    add_connection(6, 7);
    
    // Display the network topology
    printf("DEVICES:\n");
    display_devices();
    printf("CONNECTIONS:\n");
    display_connections();
    
    return 0;
}