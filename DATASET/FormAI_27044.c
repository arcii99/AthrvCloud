//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DEVICES 10
#define MAX_DEVICE_NAME_LENGTH 20
#define MAX_SIGNAL_STRENGTH 100

struct Device {
    char name[MAX_DEVICE_NAME_LENGTH];
    int signal_strength;
};

void scan_network(struct Device devices[], int *num_devices);
void sort_devices(struct Device devices[], int num_devices);
void display_devices(struct Device devices[], int num_devices);

int main() {
    struct Device devices[MAX_DEVICES];
    int num_devices = 0;

    printf("Scanning for wireless devices...\n");
    scan_network(devices, &num_devices);

    if (num_devices == 0) {
        printf("No devices found\n");
        return 0;
    }

    printf("Sorting devices by signal strength...\n");
    sort_devices(devices, num_devices);

    printf("Displaying devices in order of signal strength...\n");
    display_devices(devices, num_devices);

    return 0;
}

void scan_network(struct Device devices[], int *num_devices) {
    int i;
    srand(time(NULL));
    for(i = 0; i < MAX_DEVICES; i++) {
        int signal_strength = rand() % MAX_SIGNAL_STRENGTH;
        if (signal_strength > 0) {
            sprintf(devices[*num_devices].name, "Device%d", *num_devices+1);
            devices[*num_devices].signal_strength = signal_strength;
            (*num_devices)++;
        }
    }
}

void sort_devices(struct Device devices[], int num_devices) {
    int i, j;
    for (i = 0; i < num_devices-1; i++) {
        for (j = i+1; j < num_devices; j++) {
            if (devices[i].signal_strength < devices[j].signal_strength) {
                struct Device temp = devices[i];
                devices[i] = devices[j];
                devices[j] = temp;
            }
        }
    }
}

void display_devices(struct Device devices[], int num_devices) {
    int i;
    for (i = 0; i < num_devices; i++) {
        printf("%s: %d\n", devices[i].name, devices[i].signal_strength);
    }
}