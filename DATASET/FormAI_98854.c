//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 100
#define MAX_CONNECTIONS 200

struct device {
    int id;
    char name[20];
    char ip_address[15];
};

struct connection {
    int id;
    int source_device;
    int destination_device;
};

int num_devices = 0;
struct device devices[MAX_DEVICES];

int num_connections = 0;
struct connection connections[MAX_CONNECTIONS];

int find_device(char ip_address[]) {
    for(int i=0; i<num_devices; i++) {
        if(strcmp(devices[i].ip_address, ip_address) == 0) {
            return devices[i].id;
        }
    }
    return -1;
}

void add_device(char name[], char ip_address[]) {
    if(num_devices >= MAX_DEVICES) {
        printf("Unable to add device. Maximum number of devices reached.\n");
        return;
    }
    struct device new_device;
    new_device.id = num_devices + 1;
    strcpy(new_device.name, name);
    strcpy(new_device.ip_address, ip_address);
    devices[num_devices] = new_device;
    num_devices++;
    printf("Device added successfully.\n");
}

void add_connection(char source_ip[], char destination_ip[]) {
    int source_device = find_device(source_ip);
    if(source_device == -1) {
        printf("Unable to add connection. Source device not found.\n");
        return;
    }
    int destination_device = find_device(destination_ip);
    if(destination_device == -1) {
        printf("Unable to add connection. Destination device not found.\n");
        return;
    }
    if(num_connections >= MAX_CONNECTIONS) {
        printf("Unable to add connection. Maximum number of connections reached.\n");
        return;
    }
    struct connection new_connection;
    new_connection.id = num_connections + 1;
    new_connection.source_device = source_device;
    new_connection.destination_device = destination_device;
    connections[num_connections] = new_connection;
    num_connections++;
    printf("Connection added successfully.\n");
}

void print_topology() {
    printf("Network Topology:\n");
    for(int i=0; i<num_connections; i++) {
        printf("%s (%s) -> %s (%s)\n", devices[connections[i].source_device-1].name, devices[connections[i].source_device-1].ip_address, devices[connections[i].destination_device-1].name, devices[connections[i].destination_device-1].ip_address);
    }
}

int main() {
    add_device("Router 1", "192.168.0.1");
    add_device("Switch 1", "192.168.0.2");
    add_device("Router 2", "192.168.1.1");
    add_device("Switch 2", "192.168.1.2");
    add_connection("192.168.0.1", "192.168.0.2");
    add_connection("192.168.1.1", "192.168.1.2");
    add_connection("192.168.0.2", "192.168.1.2");
    print_topology();
    return 0;
}