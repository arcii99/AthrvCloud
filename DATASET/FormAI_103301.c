//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DEVICES 64

typedef struct {
    char device_name[20];
    char device_type[20];
    int num_links;
    char linked_devices[20][20];
} Device;

Device devices[MAX_DEVICES];
int num_devices = 0;

bool device_exists(char *device_name) {
    for (int i = 0; i < num_devices; i++) {
        if (strcmp(device_name, devices[i].device_name) == 0) {
            return true;
        }
    }
    return false;
}

void add_device(char *device_name, char *device_type) {
    if (num_devices >= MAX_DEVICES) {
        printf("Error: Maximum number of devices reached.\n");
        return;
    }
    if (device_exists(device_name)) {
        printf("Error: Device '%s' already exists.\n", device_name);
        return;
    }
    Device new_device;
    strcpy(new_device.device_name, device_name);
    strcpy(new_device.device_type, device_type);
    new_device.num_links = 0;
    devices[num_devices] = new_device;
    num_devices++;
}

Device* find_device(char *device_name) {
    for (int i = 0; i < num_devices; i++) {
        if (strcmp(device_name, devices[i].device_name) == 0) {
            return &devices[i];
        }
    }
    return NULL;
}

void link_devices(char *device_1, char *device_2) {
    Device *dev_1 = find_device(device_1);
    Device *dev_2 = find_device(device_2);
    if (dev_1 == NULL || dev_2 == NULL) {
        printf("Error: One or more devices not found.\n");
        return;
    }
    if (dev_1->num_links >= 20 || dev_2->num_links >= 20) {
        printf("Error: Maximum number of links per device reached.\n");
        return;
    }
    for (int i = 0; i < dev_1->num_links; i++) {
        if (strcmp(dev_1->linked_devices[i], device_2) == 0) {
            printf("Error: Devices '%s' and '%s' already linked.\n", device_1, device_2);
            return;
        }
    }
    strcpy(dev_1->linked_devices[dev_1->num_links], device_2);
    dev_1->num_links++;
    strcpy(dev_2->linked_devices[dev_2->num_links], device_1);
    dev_2->num_links++;
}

void print_topology() {
    printf("Network Topology:\n\n");
    for (int i = 0; i < num_devices; i++) {
        printf("%s (%s):\n", devices[i].device_name, devices[i].device_type);
        for (int j = 0; j < devices[i].num_links; j++) {
            printf("\t- %s\n", devices[i].linked_devices[j]);
        }
        printf("\n");
    }
}

int main() {
    add_device("R1", "Router");
    add_device("R2", "Router");
    add_device("SW1", "Switch");
    add_device("PC1", "PC");
    add_device("PC2", "PC");
    link_devices("R1", "SW1");
    link_devices("R2", "SW1");
    link_devices("SW1", "PC1");
    link_devices("SW1", "PC2");
    print_topology();
    return 0;
}