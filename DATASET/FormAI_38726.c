//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DEVICES 10
#define MAX_NEIGHBORS 4

typedef struct device {
    int id;
    int neighbors[MAX_NEIGHBORS];
    int num_neighbors;
} device;

int main() {
    device devices[MAX_DEVICES];

    // Initialize devices
    srand(time(NULL));
    for (int i = 0; i < MAX_DEVICES; i++) {
        devices[i].id = i;
        devices[i].num_neighbors = 0;
        for (int j = 0; j < MAX_NEIGHBORS; j++) {
            devices[i].neighbors[j] = -1;
        }
    }

    // Create random connections between devices
    for (int i = 0; i < MAX_DEVICES; i++) {
        int num_connections = rand() % MAX_NEIGHBORS;
        for (int j = 0; j < num_connections; j++) {
            int neighbor_id = rand() % MAX_DEVICES;
            if (neighbor_id != devices[i].id) {
                devices[i].neighbors[j] = neighbor_id;
                devices[i].num_neighbors++;
            }
        }
    }

    // Print connections
    printf(" Network Topology Mapper\n");
    printf(" -----------------------\n");
    for (int i = 0; i < MAX_DEVICES; i++) {
        printf(" Device %d is connected to:", devices[i].id);
        for (int j = 0; j < devices[i].num_neighbors; j++) {
            printf(" %d", devices[i].neighbors[j]);
        }
        printf("\n");
    }

    return 0;
}