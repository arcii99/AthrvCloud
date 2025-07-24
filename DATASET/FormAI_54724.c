//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_DEVICES 10 // Maximum number of devices to scan
#define MAX_NAME_LENGTH 20 // Maximum length of device name

struct WirelessDevice {
    char name[MAX_NAME_LENGTH];
    char ip[16]; // IPv4 Address
    int signal_strength;
};

int main() {
    struct WirelessDevice devices[MAX_DEVICES];
    int device_count = 0;

    // Scan for devices and populate the devices array
    printf("Scanning for wireless devices...\n");
    for (int i = 0; i < MAX_DEVICES; i++) {
        if (rand() % 2 == 0) { // Simulate device discovery randomly
            // Populate device properties
            sprintf(devices[device_count].name, "Device %d", device_count+1);
            sprintf(devices[device_count].ip, "192.168.1.%d", 10+device_count);
            devices[device_count].signal_strength = rand() % 100;

            device_count++;

            printf("Found device: \"%s\" (IP: %s, Signal strength: %d)\n", 
                   devices[device_count-1].name, devices[device_count-1].ip, devices[device_count-1].signal_strength);
        }
    }

    // Sort devices by signal strength (highest to lowest)
    for (int i = 0; i < device_count; i++) {
        for (int j = i+1; j < device_count; j++) {
            if (devices[i].signal_strength < devices[j].signal_strength) {
                // Swap devices
                struct WirelessDevice temp = devices[i];
                devices[i] = devices[j];
                devices[j] = temp;
            }
        }
    }

    // Print devices in sorted order
    printf("Wireless devices sorted by signal strength:\n");
    for (int i = 0; i < device_count; i++) {
        printf("%d. \"%s\" (IP: %s, Signal strength: %d)\n", 
               i+1, devices[i].name, devices[i].ip, devices[i].signal_strength);
    }

    return 0;
}