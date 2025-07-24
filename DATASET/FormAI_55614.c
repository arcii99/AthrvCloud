//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DEVICES 10
#define MAX_CONNECTIONS 20

typedef struct device {
    char name[20];
    int id;
    bool is_alive;
} device_t;

typedef struct connection {
    int from_id;
    int to_id;
    bool is_alive;
} connection_t;

device_t devices[MAX_DEVICES];
connection_t connections[MAX_CONNECTIONS];

int main() {
    int num_devices = 0;
    int num_connections = 0;

    // Generate devices with random names and IDs
    for (int i=0; i < MAX_DEVICES; i++) {
        char name[20] = "";
        int id = rand() % 100 + 1;
        for (int j=0; j < id%5+5; j++) {
            char c = (char)(rand() % 26 + 97); // Random lowercase letter
            strncat(name, &c, 1);
        }
        device_t device = { .id = id, .is_alive = true };
        strcpy(device.name, name);
        devices[num_devices++] = device;
    }

    // Generate connections between random devices
    for (int i=0; i < MAX_CONNECTIONS; i++) {
        int from_id = rand() % num_devices + 1;
        int to_id = rand() % num_devices + 1;
        connection_t connection = { .from_id = from_id, .to_id = to_id, .is_alive = true };
        connections[num_connections++] = connection;
    }

    // Display topological map
    printf("Topological Map\n");
    printf("----------------\n");
    for(int i=0; i < num_devices; i++) {
        for(int j=0; j < num_connections; j++) {
            if(connections[j].from_id == devices[i].id && connections[j].is_alive && devices[i].is_alive) {
                printf("%s <---> ", devices[i].name); // Display outgoing connection
                for(int k = 0; k < num_devices; k++) {
                    if(connections[j].to_id == devices[k].id && devices[k].is_alive) {
                        printf("%s\n", devices[k].name); // Display incoming connection
                    }
                }
            }
        }
    }

    // Simulate network failure
    for(int i=0; i < rand() % num_connections; i++) {
        int index = rand() % num_connections;
        connections[index].is_alive = false;
    }
    for(int i=0; i < rand() % num_devices; i++) {
        int index = rand() % num_devices;
        devices[index].is_alive = false;
    }

    // Display updated topological map
    printf("\n\nUpdated Topological Map\n");
    printf("-------------------------\n");
    for(int i=0; i < num_devices; i++) {
        for(int j=0; j < num_connections; j++) {
            if(connections[j].from_id == devices[i].id && connections[j].is_alive && devices[i].is_alive) {
                printf("%s <---> ", devices[i].name); // Display outgoing connection
                for(int k = 0; k < num_devices; k++) {
                    if(connections[j].to_id == devices[k].id && devices[k].is_alive) {
                        printf("%s\n", devices[k].name); // Display incoming connection
                    }
                }
            }
        }
    }

    return 0;
}