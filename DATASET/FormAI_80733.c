//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_DEVICES 10
#define MAX_SSID_LENGTH 50

struct Device {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
};

void scan_devices(struct Device *devices, int *num_devices) {
    // Simulate scanning for Wi-Fi devices
    printf("Scanning for devices...\n");
    sleep(1);

    // Mock data for testing purposes
    const char *mock_ssids[MAX_DEVICES] = {"Device1", "Device2", "Device3", "Device4", "Device5", "Device6", "Device7", "Device8", "Device9", "Device10"};
    int mock_strengths[MAX_DEVICES] = {-60, -75, -80, -85, -90, -92, -95, -97, -99, -100};
    const int mock_num_devices = 6;

    // Copy mock data to array of devices
    for (int i = 0; i < mock_num_devices; i++) {
        strncpy(devices[i].ssid, mock_ssids[i], MAX_SSID_LENGTH);
        devices[i].signal_strength = mock_strengths[i];
    }

    *num_devices = mock_num_devices;
}

void print_devices(struct Device *devices, int num_devices) {
    printf("Available devices:\n");
    for (int i = 0; i < num_devices; i++) {
        printf("%s (%d dBm)\n", devices[i].ssid, devices[i].signal_strength);
    }
}

void sort_devices(struct Device *devices, int num_devices) {
    // Bubble sort devices by signal strength (descending order)
    for (int i = 0; i < num_devices - 1; i++) {
        for (int j = 0; j < num_devices - 1 - i; j++) {
            if (devices[j].signal_strength < devices[j+1].signal_strength) {
                // Swap devices
                char temp_ssid[MAX_SSID_LENGTH];
                strcpy(temp_ssid, devices[j].ssid);

                int temp_strength = devices[j].signal_strength;

                strcpy(devices[j].ssid, devices[j+1].ssid);
                devices[j].signal_strength = devices[j+1].signal_strength;

                strcpy(devices[j+1].ssid, temp_ssid);
                devices[j+1].signal_strength = temp_strength;
            }
        }
    }
}

int main() {
    struct Device devices[MAX_DEVICES];
    int num_devices = 0;

    scan_devices(devices, &num_devices);
    print_devices(devices, num_devices);
    sort_devices(devices, num_devices);
    printf("Devices sorted by signal strength:\n");
    print_devices(devices, num_devices);

    return 0;
}