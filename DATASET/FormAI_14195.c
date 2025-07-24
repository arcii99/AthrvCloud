//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store device information
typedef struct device {
    char name[20];
    char ip[16];
} device;

// Structure to store link information
typedef struct link {
    device start_device;
    device end_device;
} link;

// Traverse the device list to check if a device exists
int device_exists(device *devices, int size, device *d) {
    for (int i = 0; i < size; i++) {
        if (strcmp(devices[i].name, d->name) == 0 && strcmp(devices[i].ip, d->ip) == 0)
            return 1;
    }
    return 0;
}

// Traverse the link list to check if a link exists
int link_exists(link *links, int size, link *l) {
    for (int i = 0; i < size; i++) {
        if (strcmp(links[i].start_device.name, l->start_device.name) == 0 &&
            strcmp(links[i].start_device.ip, l->start_device.ip) == 0 &&
            strcmp(links[i].end_device.name, l->end_device.name) == 0 &&
            strcmp(links[i].end_device.ip, l->end_device.ip) == 0)
            return 1;
    }
    return 0;
}

int main() {
    device *devices = NULL;
    link *links = NULL;
    int num_devices = 0, num_links = 0;
    char input[50];

    printf("Network Topology Mapper\n");
    printf("Enter device and link information in the following format:\n");
    printf("Device: <name> <IP address>\n");
    printf("Link: <start device name> <start device IP> - <end device name> <end device IP>\n\n");

    while (1) {
        printf("> ");
        fgets(input, 50, stdin);

        if (strncmp(input, "Device:", 7) == 0) {
            device *d = (device*) malloc(sizeof(device));
            sscanf(input + 8, "%s %s", d->name, d->ip);
            if (device_exists(devices, num_devices, d) == 0) {
                num_devices++;
                devices = (device*) realloc(devices, sizeof(device) * num_devices);
                devices[num_devices - 1] = *d;
                printf("Device added: %s %s\n", d->name, d->ip);
            }
            else {
                printf("Device already exists\n");
            }
            free(d);
        }
        else if (strncmp(input, "Link:", 5) == 0) {
            link *l = (link*) malloc(sizeof(link));
            sscanf(input + 6, "%s %s - %s %s", l->start_device.name, l->start_device.ip, l->end_device.name, l->end_device.ip);
            if (device_exists(devices, num_devices, &l->start_device) == 0) {
                printf("Start device does not exist\n");
            }
            else if (device_exists(devices, num_devices, &l->end_device) == 0) {
                printf("End device does not exist\n");
            }
            else if (link_exists(links, num_links, l) == 1) {
                printf("Link already exists\n");
            }
            else {
                num_links++;
                links = (link*) realloc(links, sizeof(link) * num_links);
                links[num_links - 1] = *l;
                printf("Link added: %s %s - %s %s\n", l->start_device.name, l->start_device.ip,
                    l->end_device.name, l->end_device.ip);
            }
            free(l);
        }
        else {
            printf("Invalid input\n");
        }
    }

    return 0;
}