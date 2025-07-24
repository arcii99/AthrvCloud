//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: funny
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>

#define MAX_DEVICES 20
#define MAX_CONNECTIONS 50

typedef struct {
    int id;
    char name[20];
    char address[50];
    int connections[MAX_CONNECTIONS];
} Device;

void print_device(Device d) {
    printf("DEVICE:\n");
    printf("  ID: %d\n", d.id);
    printf("  Name: %s\n", d.name);
    printf("  Address: %s\n", d.address);
    printf("  Connections: ");
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        if (d.connections[i] != -1) {
            printf("%d ", d.connections[i]);
        }
    }
    printf("\n");
}

void map_network(Device devices[], int num_devices) {
    int connected_devices[num_devices][num_devices];
    memset(connected_devices, 0, sizeof(connected_devices));
    for (int i = 0; i < num_devices; i++) {
        for (int j = 0; j < MAX_CONNECTIONS; j++) {
            if (devices[i].connections[j] != -1) {
                int conn_id = devices[i].connections[j];
                connected_devices[i][conn_id] = 1;
                connected_devices[conn_id][i] = 1;
            }
        }
    }

    printf("NETWORK MAP:\n");
    for (int i = 0; i < num_devices; i++) {
        printf("%s [%d]:\n", devices[i].name, devices[i].id);
        for (int j = 0; j < num_devices; j++) {
            if (connected_devices[i][j] == 1 && i != j) {
                printf("  -> %s [%d]\n", devices[j].name, devices[j].id);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    Device devices[MAX_DEVICES];
    int num_devices = 0;

    // generate some random devices
    for (int i = 0; i < 10; i++) {
        Device d;
        d.id = rand() % 1000;
        sprintf(d.name, "Device%d", d.id);
        sprintf(d.address, "192.168.%d.%d", i+1, rand() % 255);
        for (int j = 0; j < MAX_CONNECTIONS; j++) {
            d.connections[j] = -1;
        }
        devices[num_devices++] = d;
    }

    // connect some devices
    for (int i = 0; i < num_devices; i++) {
        for (int j = 0; j < 2; j++) {
            int conn_id = rand() % num_devices;
            if (conn_id != i && devices[i].connections[j] == -1 && devices[conn_id].connections[j] == -1) {
                devices[i].connections[j] = conn_id;
                devices[conn_id].connections[j] = i;
            }
        }
    }

    // print out devices
    for (int i = 0; i < num_devices; i++) {
        print_device(devices[i]);
    }

    // map network
    map_network(devices, num_devices);

    return 0;
}