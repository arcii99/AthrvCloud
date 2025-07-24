//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DEVICES 100
#define MAX_NAME_LENGTH 20

struct Device {
    char name[MAX_NAME_LENGTH];
    int neighbors[MAX_DEVICES];
    int num_neighbors;
    bool visited;
};

int num_devices = 0;
struct Device devices[MAX_DEVICES];

void add_device(char* name) {
    strcpy(devices[num_devices].name, name);
    devices[num_devices].num_neighbors = 0;
    devices[num_devices].visited = false;
    num_devices++;
}

void add_neighbor(int source, int dest) {
    devices[source].neighbors[devices[source].num_neighbors] = dest;
    devices[source].num_neighbors++;
}

void depth_first_search(int device_index) {
    printf("%s\n", devices[device_index].name);
    devices[device_index].visited = true;

    for (int i = 0; i < devices[device_index].num_neighbors; i++) {
        int neighbor_index = devices[device_index].neighbors[i];

        if (!devices[neighbor_index].visited) {
            depth_first_search(neighbor_index);
        }
    }
}

int main() {
    add_device("Server 1");
    add_device("Router 1");
    add_device("Switch");
    add_device("Router 2");
    add_device("Server 2");

    add_neighbor(0, 1);
    add_neighbor(0, 2);
    add_neighbor(1, 2);
    add_neighbor(1, 3);
    add_neighbor(3, 4);

    depth_first_search(0);

    return EXIT_SUCCESS;
}