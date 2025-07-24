//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_DEVICES 20
#define MAX_NAME_LENGTH 50

typedef struct {
    char *name;
    char *ip_address;
    int num_connections;
    char *connection_names[MAX_DEVICES];
} Device;

void print_devices(Device *devices, int num_devices) {
    printf("Device List:\n");
    for (int i = 0; i < num_devices; i++) {
        printf("Device Name: %s\n", devices[i].name);
        printf("IP Address: %s\n", devices[i].ip_address);
        printf("Number of Connections: %d\n", devices[i].num_connections);
        printf("Connection Names:\n");
        for (int j = 0; j < devices[i].num_connections; j++) {
            printf("\t%s\n", devices[i].connection_names[j]);
        }
        printf("\n");
    }
}

int main() {
    Device devices[MAX_DEVICES];
    int num_devices = 0;

    // Add devices
    devices[num_devices].name = "Device 1";
    devices[num_devices].ip_address = "192.168.1.1";
    devices[num_devices].num_connections = 1;
    devices[num_devices].connection_names[0] = "Device 2";
    num_devices++;

    devices[num_devices].name = "Device 2";
    devices[num_devices].ip_address = "192.168.1.2";
    devices[num_devices].num_connections = 2;
    devices[num_devices].connection_names[0] = "Device 1";
    devices[num_devices].connection_names[1] = "Device 3";
    num_devices++;

    devices[num_devices].name = "Device 3";
    devices[num_devices].ip_address = "192.168.1.3";
    devices[num_devices].num_connections = 1;
    devices[num_devices].connection_names[0] = "Device 2";
    num_devices++;

    // Print devices
    print_devices(devices, num_devices);

    return 0;
}