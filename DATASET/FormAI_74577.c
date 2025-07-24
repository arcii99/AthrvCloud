//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 1000
#define MAX_NAME_LEN 50

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    int num_connections;
    int connections[MAX_DEVICES];
} Device;

void map_topology(Device *devices, int num_devices) {
    int i, j;

    for (i = 0; i < num_devices; i++) {
        printf("%s [%d]", devices[i].name, devices[i].id);
        printf(" connected to: ");

        for (j = 0; j < devices[i].num_connections; j++) {
            if (j > 0)
                printf(", ");
            int conn_id = devices[i].connections[j];
            printf("%s [%d]", devices[conn_id].name, devices[conn_id].id);
        }

        printf("\n");
    }
}

int main() {
    Device devices[MAX_DEVICES] = {
        {0, "Router 1", 3, {1, 2, 3}},
        {1, "Computer A", 1, {0}},
        {2, "Switch 1", 3, {0, 3, 4}},
        {3, "Router 2", 2, {0, 2}},
        {4, "Access Point", 1, {2}},
    };

    int num_devices = 5;
    map_topology(devices, num_devices);

    return 0;
}