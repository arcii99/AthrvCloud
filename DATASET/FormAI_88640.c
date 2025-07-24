//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 100
#define MAX_LINKS 100

typedef struct {
    char ip_address[16];
    char device_type[20];
    int num_ports;
    int ports[MAX_DEVICES];
} Device;

typedef struct {
    int source_port;
    int dest_port;
    int source_device;
    int dest_device;
} Link;

int main() {
    Device devices[MAX_DEVICES];
    Link links[MAX_LINKS];
    int num_devices = 0;
    int num_links = 0;
    
    // Add devices
    strcpy(devices[num_devices].ip_address, "192.168.1.1");
    strcpy(devices[num_devices].device_type, "Router");
    devices[num_devices].num_ports = 4;
    devices[num_devices].ports[0] = 1;
    devices[num_devices].ports[1] = 2;
    devices[num_devices].ports[2] = 3;
    devices[num_devices].ports[3] = 4;
    num_devices++;
    
    strcpy(devices[num_devices].ip_address, "192.168.1.2");
    strcpy(devices[num_devices].device_type, "Switch");
    devices[num_devices].num_ports = 24;
    for (int i = 0; i < devices[num_devices].num_ports; i++) {
        devices[num_devices].ports[i] = i + 1;
    }
    num_devices++;
    
    strcpy(devices[num_devices].ip_address, "192.168.1.3");
    strcpy(devices[num_devices].device_type, "Computer");
    devices[num_devices].num_ports = 1;
    devices[num_devices].ports[0] = 1;
    num_devices++;
    
    // Add links
    links[num_links].source_device = 0;
    links[num_links].source_port = 1;
    links[num_links].dest_device = 1;
    links[num_links].dest_port = 1;
    num_links++;
    
    links[num_links].source_device = 1;
    links[num_links].source_port = 2;
    links[num_links].dest_device = 2;
    links[num_links].dest_port = 1;
    num_links++;
    
    // Print network topology
    printf("Network Topology:\n");
    for (int i = 0; i < num_devices; i++) {
        printf("%s (%s) connected to ", devices[i].ip_address, devices[i].device_type);
        for (int j = 0; j < num_links; j++) {
            if (links[j].source_device == i) {
                for (int k = 0; k < num_devices; k++) {
                    if (links[j].dest_device == k) {
                        printf("%s (%s) on port %d\n", devices[k].ip_address, devices[k].device_type, links[j].dest_port);
                    }
                }
            }
        }
    }
    
    return 0;
}