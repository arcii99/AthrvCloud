//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure to hold information about a network device
typedef struct {
    char device_name[50];
    char device_ip[16];
    bool is_router;
    int num_connections;
    char connected_devices[10][50];
} network_device;

// Function to print details of a device
void print_device_info(network_device dev) {
    printf("Device Name: %s\n", dev.device_name);
    printf("Device IP: %s\n", dev.device_ip);
    printf("Is Router: %s\n", (dev.is_router ? "Yes" : "No"));
    printf("Number of Connections: %d\n", dev.num_connections);
    printf("Connected Devices:\n");
    for (int i = 0; i < dev.num_connections; i++) {
        printf("\t%s\n", dev.connected_devices[i]);
    }
    printf("\n");
}

// Function to search for a device by device name
int search_device_by_name(network_device *devices, int num_devices, char* device_name) {
    for (int i = 0; i < num_devices; i++) {
        if (strcmp(devices[i].device_name, device_name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to add a new device to the network
void add_device(network_device *devices, int *num_devices) {
    network_device dev;
    printf("Enter Device Name: ");
    scanf("%s", dev.device_name);
    getchar();  // to clear the newline character from input buffer
    printf("Enter Device IP: ");
    scanf("%s", dev.device_ip);
    getchar();
    printf("Is Router (1 for Yes, 0 for No): ");
    scanf("%d", &dev.is_router);
    getchar();
    printf("Enter Number of Connections: ");
    scanf("%d", &dev.num_connections);
    getchar();
    for (int i = 0; i < dev.num_connections; i++) {
        printf("Enter Connected Device %d Name: ", i+1);
        scanf("%s", dev.connected_devices[i]);
        getchar();
    }
    devices[*num_devices] = dev;
    *num_devices += 1;
    printf("Device Added Successfully!\n\n");
}

// Function to remove a device from the network
void remove_device(network_device *devices, int *num_devices) {
    char device_name[50];
    printf("Enter Device Name to Remove: ");
    scanf("%s", device_name);
    int index = search_device_by_name(devices, *num_devices, device_name);
    if (index == -1) {
        printf("Device Not Found!\n\n");
    } else {
        for (int i = index; i < *num_devices-1; i++) {
            devices[i] = devices[i+1];
        }
        *num_devices -= 1;
        printf("Device Removed Successfully!\n\n");
    }
}

int main() {
    network_device devices[10];
    int num_devices = 0;

    // Sample devices for testing purposes
    network_device dev1 = {"Router", "192.168.0.1", true, 2, {"Server", "PC1"}};
    network_device dev2 = {"Server", "192.168.0.2", false, 2, {"Router", "PC2"}};
    network_device dev3 = {"PC1", "192.168.0.3", false, 1, {"Router"}};
    network_device dev4 = {"PC2", "192.168.0.4", false, 1, {"Server"}};
    devices[0] = dev1;
    devices[1] = dev2;
    devices[2] = dev3;
    devices[3] = dev4;
    num_devices = 4;

    // User menu
    bool exit_program = false;
    while (!exit_program) {
        printf("1. View Network Topology\n");
        printf("2. Add Device\n");
        printf("3. Remove Device\n");
        printf("4. Exit\n");
        printf("Enter Your Choice: ");
        int choice;
        scanf("%d", &choice);
        getchar();  // to clear the newline character from input buffer
        printf("\n");
        switch (choice) {
            case 1:
                for (int i = 0; i < num_devices; i++) {
                    print_device_info(devices[i]);
                }
                break;
            case 2:
                add_device(devices, &num_devices);
                break;
            case 3:
                remove_device(devices, &num_devices);
                break;
            case 4:
                exit_program = true;
                break;
            default:
                printf("Invalid Choice! Try Again.\n\n");
        }
    }

    return 0;
}