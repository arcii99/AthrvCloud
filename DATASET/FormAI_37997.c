//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 1000
#define MAX_NAME_LEN 20
#define MAX_IP_LEN 15

typedef struct {
    char name[MAX_NAME_LEN];
    char ip_address[MAX_IP_LEN];
    int port_num;
    int num_connections;
    char *connections[MAX_DEVICES];
} Device;

Device devices[MAX_DEVICES];
int num_devices = 0;


void add_device(char *name, char *ip_address, int port_num) {
    strcpy(devices[num_devices].name, name);
    strcpy(devices[num_devices].ip_address, ip_address);
    devices[num_devices].port_num = port_num;
    devices[num_devices].num_connections = 0;
    num_devices++;
}


void add_connection(char *device_name, char *connection_name) {
    int i, j;
    for (i = 0; i < num_devices; i++) {
        if (strcmp(devices[i].name, device_name) == 0) {
            for (j = 0; j < num_devices; j++) {
                if (strcmp(devices[j].name, connection_name) == 0) {
                    devices[i].connections[devices[i].num_connections] = devices[j].name;
                    devices[i].num_connections++;
                    break;
                }
            }
            break;
        }
    }
}


void print_topology() {
    int i, j;
    printf("Network Topology:\n");
    for (i = 0; i < num_devices; i++) {
        printf("%s (%s:%d)", devices[i].name, devices[i].ip_address, devices[i].port_num);
        printf(" connected to ");
        for (j = 0; j < devices[i].num_connections; j++) {
            printf("%s, ", devices[i].connections[j]);
        }
        printf("\n");
    }
}


int main() {
    add_device("Router1", "192.168.1.1", 80);
    add_device("Switch1", "192.168.1.2", 8080);
    add_device("PC1", "192.168.1.3", 8080);
    add_device("PC2", "192.168.1.4", 8080);

    add_connection("Router1", "Switch1");
    add_connection("Switch1", "PC1");
    add_connection("Switch1", "PC2");

    print_topology();

    return 0;
}