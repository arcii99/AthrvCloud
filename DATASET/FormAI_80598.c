//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 256
#define MAX_CONNECTIONS 65536

struct device {
    char name[64];
    int id;
    struct device *connections[MAX_DEVICES];
};

struct device devices[MAX_DEVICES];
struct device *device_lookup[MAX_DEVICES];
int num_devices;

struct connection {
    int device1;
    int port1;
    int device2;
    int port2;
};

struct connection connections[MAX_CONNECTIONS];
int num_connections;

void add_device(char *name) {
    struct device *dev;

    dev = &devices[num_devices];
    strcpy(dev->name, name);
    dev->id = num_devices;
    num_devices++;

    device_lookup[dev->id] = dev;
}

void add_connection(int device1, int port1, int device2, int port2) {
    struct device *dev1, *dev2;

    dev1 = device_lookup[device1];
    dev2 = device_lookup[device2];

    dev1->connections[port1] = dev2;
    dev2->connections[port2] = dev1;

    connections[num_connections].device1 = device1;
    connections[num_connections].port1 = port1;
    connections[num_connections].device2 = device2;
    connections[num_connections].port2 = port2;
    num_connections++;
}

void print_topology() {
    int i, j;
    struct device *dev;

    for (i = 0; i < num_devices; i++) {
        dev = &devices[i];

        printf("%s:\n", dev->name);
        for (j = 0; j < MAX_DEVICES; j++) {
            if (dev->connections[j]) {
                printf("\tport %d connected to %s port %d\n", j, dev->connections[j]->name, dev->connections[j]->id);
            }
        }
    }
}

int main(int argc, char **argv) {
    add_device("router1");
    add_device("router2");
    add_device("switch1");
    add_connection(0, 0, 1, 0);
    add_connection(1, 1, 2, 1);
    add_connection(2, 0, 1, 2);

    print_topology();

    return 0;
}