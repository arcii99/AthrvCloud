//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 1000
#define MAX_SSID_LENGTH 32

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int channel;
    int signal_strength;
} wifi_device;

int num_devices = 0;
wifi_device devices[MAX_DEVICES];

void scan_networks() {
    // Simulate scanning for wireless networks
    printf("Scanning for wireless networks...\n");

    // Add some random devices to the devices array
    for (int i = 0; i < MAX_DEVICES; i++) {
        wifi_device device;
        sprintf(device.ssid, "Wifi%d", i);
        device.channel = rand() % 11;
        device.signal_strength = -rand() % 100;
        devices[num_devices++] = device;
    }
}

void print_devices() {
    for (int i = 0; i < num_devices; i++) {
        printf("SSID: %s\n", devices[i].ssid);
        printf("Channel: %d\n", devices[i].channel);
        printf("Signal Strength: %d dBm\n\n", devices[i].signal_strength);
    }
}

void filter_by_channel(int channel) {
    num_devices = 0;
    for (int i = 0; i < MAX_DEVICES; i++) {
        wifi_device device = devices[i];
        if (device.channel == channel) {
            devices[num_devices++] = device;
        }
    }
}

int main() {
    scan_networks();
    printf("All devices:\n");
    print_devices();

    printf("Filtering by channel 6...\n");
    filter_by_channel(6);
    printf("Devices on channel 6:\n");
    print_devices();

    return 0;
}