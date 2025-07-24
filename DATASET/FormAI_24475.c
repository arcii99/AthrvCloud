//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 50
#define MAX_SSID_LENGTH 32

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} wifi_device;

int main() {

    // Initialize random seed
    srand(0);

    wifi_device devices[MAX_DEVICES];
    int num_devices = 0;

    // Simulate detecting some devices
    printf("Detecting Wi-Fi devices...\n");
    for (int i = 0; i < MAX_DEVICES; i++) {
        if (rand() % 2 == 0) {
            snprintf(devices[num_devices].ssid, MAX_SSID_LENGTH, "Device %d", i);
            devices[num_devices].signal_strength = rand() % 101;
            printf("%s detected with signal strength %d%%\n", devices[num_devices].ssid, devices[num_devices].signal_strength);
            num_devices++;
        }
    }

    // Allow the user to configure the minimum signal strength to display
    int min_signal_strength;
    printf("Enter minimum signal strength to display (0-100): ");
    scanf("%d", &min_signal_strength);

    // Display the devices above the minimum signal strength
    printf("Devices with signal strength greater than %d%%:\n", min_signal_strength);
    printf("SSID\tSignal Strength\n");
    for (int i = 0; i < num_devices; i++) {
        if (devices[i].signal_strength >= min_signal_strength) {
            printf("%s\t%d%%\n", devices[i].ssid, devices[i].signal_strength);
        }
    }

    return 0;
}