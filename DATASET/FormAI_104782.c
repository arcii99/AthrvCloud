//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10
#define MAX_CONNECTIONS 20

typedef struct {
    int id;
    char name[20];
    char type[10];
    char status[10];
    int connections[MAX_CONNECTIONS];
    int num_connections;
} Device;

Device devices[MAX_DEVICES];
int num_devices = 0;

void add_device(char *name, char *type, char *status) {
    if (num_devices >= MAX_DEVICES) {
        printf("Error: maximum number of devices reached\n");
        return;
    }
    Device *device = &devices[num_devices];
    device->id = num_devices + 1;
    strcpy(device->name, name);
    strcpy(device->type, type);
    strcpy(device->status, status);
    device->num_connections = 0;
    num_devices++;
}

void add_connection(int device_id_1, int device_id_2) {
    if (device_id_1 > num_devices || device_id_2 > num_devices) {
        printf("Error: invalid device ID\n");
        return;
    }
    Device *device_1 = &devices[device_id_1 - 1];
    Device *device_2 = &devices[device_id_2 - 1];
    if (device_1->num_connections >= MAX_CONNECTIONS
        || device_2->num_connections >= MAX_CONNECTIONS) {
        printf("Error: maximum number of connections reached\n");
        return;
    }
    device_1->connections[device_1->num_connections] = device_id_2;
    device_1->num_connections++;
    device_2->connections[device_2->num_connections] = device_id_1;
    device_2->num_connections++;
}

void print_devices() {
    printf("ID\tName\t\tType\t\tStatus\t\tConnections\n");
    for (int i = 0; i < num_devices; i++) {
        Device *device = &devices[i];
        printf("%d\t%s\t\t%s\t%s\t", device->id, device->name, device->type, device->status);
        for (int j = 0; j < device->num_connections; j++) {
            printf("%d ", device->connections[j]);
        }
        printf("\n");
    }
}

int main() {
    add_device("Router 1", "Router", "Active");
    add_device("Server 1", "Server", "Active");
    add_device("Switch 1", "Switch", "Active");

    add_connection(1, 2);
    add_connection(1, 3);

    print_devices();

    return 0;
}