//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DEVICES 100
#define MAX_INTERFACES 10

typedef struct {
    char name[20];
    int num_interfaces;
    char interfaces[MAX_INTERFACES][20];
} Device;

void init_devices(Device* devices, int num_devices) {
    for(int i = 0; i < num_devices; i++) {
        strcpy(devices[i].name, "");
        devices[i].num_interfaces = 0;
        for(int j = 0; j < MAX_INTERFACES; j++) {
            strcpy(devices[i].interfaces[j], "");
        }
    }
}

int find_device_index(Device* devices, int num_devices, char* device_name) {
    for(int i = 0; i < num_devices; i++) {
        if(strcmp(devices[i].name, device_name) == 0) {
            return i;
        }
    }
    return -1;
}

void add_device(Device* devices, int* num_devices, char* device_name, char** interface_names, int num_interfaces) {
    int index = find_device_index(devices, *num_devices, device_name);
    if(index != -1) {
        printf("Device %s already exists.\n", device_name);
        return;
    }
    if(*num_devices == MAX_DEVICES) {
        printf("Maximum number of devices reached.\n");
        return;
    }
    Device new_device;
    strcpy(new_device.name, device_name);
    new_device.num_interfaces = num_interfaces;
    for(int i = 0; i < num_interfaces; i++) {
        strcpy(new_device.interfaces[i], interface_names[i]);
    }
    devices[*num_devices] = new_device;
    *num_devices += 1;
    printf("Device %s added successfully.\n", device_name);
}

void remove_device(Device* devices, int* num_devices, char* device_name) {
    int index = find_device_index(devices, *num_devices, device_name);
    if(index == -1) {
        printf("Device %s does not exist.\n", device_name);
        return;
    }
    for(int i = index; i < *num_devices - 1; i++) {
        devices[i] = devices[i+1];
    }
    *num_devices -= 1;
    printf("Device %s removed successfully.\n", device_name);
}

void print_topology(Device* devices, int num_devices) {
    printf("Current Network Topology:\n");
    for(int i = 0; i < num_devices; i++) {
        printf("%s ", devices[i].name);
        for(int j = 0; j < devices[i].num_interfaces; j++) {
            printf("--%s", devices[i].interfaces[j]);
            int neighbor_index = find_device_index(devices, num_devices, devices[i].interfaces[j]);
            if(neighbor_index != -1) {
                for(int k = 0; k < devices[neighbor_index].num_interfaces; k++) {
                    if(strcmp(devices[neighbor_index].interfaces[k], devices[i].name) == 0) {
                        printf("--%s", devices[neighbor_index].interfaces[k]);
                    }
                }
            }
        }
        printf("\n");
    }
}

int main() {
    Device devices[MAX_DEVICES];
    int num_devices = 0;

    char device_name[20];
    char interface_names[MAX_INTERFACES][20];
    int num_interfaces;

    while(true) {
        printf("\nMenu:\n");
        printf("1. Add device\n");
        printf("2. Remove device\n");
        printf("3. Print topology\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter device name: ");
                scanf("%s", device_name);
                printf("Enter number of interfaces: ");
                scanf("%d", &num_interfaces);
                printf("Enter interface names (use spaces between names): ");
                for(int i = 0; i < num_interfaces; i++) {
                    scanf("%s", interface_names[i]);
                }
                add_device(devices, &num_devices, device_name, interface_names, num_interfaces);
                break;
            case 2:
                printf("Enter device name to remove: ");
                scanf("%s", device_name);
                remove_device(devices, &num_devices, device_name);
                break;
            case 3:
                print_topology(devices, num_devices);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}