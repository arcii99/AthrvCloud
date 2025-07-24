//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10
#define MAX_CONNECTIONS 20

// Device struct representing a network device
typedef struct device {
    char* name;
    char* ip_address;
} Device;

// Connection struct representing a connection between two devices
typedef struct connection {
    Device* device1;
    Device* device2;
} Connection;

int main() {
    // Create an array to hold network devices
    Device devices[MAX_DEVICES];
    int device_count = 0;

    // Create an array to hold network connections
    Connection connections[MAX_CONNECTIONS];
    int connection_count = 0;

    // Add some sample devices
    Device router = {"Router", "192.168.0.1"};
    Device switch1 = {"Switch1", "192.168.0.2"};
    Device switch2 = {"Switch2", "192.168.0.3"};
    Device laptop = {"Laptop", "192.168.0.4"};
    Device printer = {"Printer", "192.168.0.5"};
    Device server = {"Server", "192.168.0.6"};

    devices[device_count++] = router;
    devices[device_count++] = switch1;
    devices[device_count++] = switch2;
    devices[device_count++] = laptop;
    devices[device_count++] = printer;
    devices[device_count++] = server;

    // Add some sample connections
    Connection connection1 = {&router, &switch1};
    Connection connection2 = {&router, &switch2};
    Connection connection3 = {&switch1, &laptop};
    Connection connection4 = {&switch1, &printer};
    Connection connection5 = {&switch2, &server};

    connections[connection_count++] = connection1;
    connections[connection_count++] = connection2;
    connections[connection_count++] = connection3;
    connections[connection_count++] = connection4;
    connections[connection_count++] = connection5;

    // Display the network topology
    printf("Virtual Network Mapper\n");
    printf("=======================\n\n");
    printf("Devices:\n");
    for (int i = 0; i < device_count; i++) {
        printf("%s [%s]\n", devices[i].name, devices[i].ip_address);
    }

    printf("\nConnections:\n");
    for (int i = 0; i < connection_count; i++) {
        printf("%s [%s] --- %s [%s]\n",
            connections[i].device1->name, connections[i].device1->ip_address,
            connections[i].device2->name, connections[i].device2->ip_address);
    }

    return 0;
}