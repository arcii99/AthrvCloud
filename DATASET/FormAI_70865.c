//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Defining network devices
struct device {
    char type[20];
    char ip_address[20];
    char mac_address[20];
};

int main() {
    int num_devices;

    printf("Enter the number of devices in the network topology: ");
    scanf("%d", &num_devices);

    struct device network[num_devices]; // creating an array of network devices

    // Adding details of network devices
    for(int i=0; i<num_devices; i++) {
        printf("\nDevice %d\n", i+1);
        printf("Enter type of device (router/switch/host): ");
        scanf("%s", network[i].type);
        printf("Enter IP address of device: ");
        scanf("%s", network[i].ip_address);
        printf("Enter MAC address of device: ");
        scanf("%s", network[i].mac_address);
    }

    // Displaying network topology
    printf("\n\nNetwork Topology\n\n");
    for(int i=0; i<num_devices; i++) {
        printf("Device %d\n", i+1);
        printf("Type: %s\n", network[i].type);
        printf("IP address: %s\n", network[i].ip_address);
        printf("MAC address: %s\n\n", network[i].mac_address);
    }

    return 0;
}