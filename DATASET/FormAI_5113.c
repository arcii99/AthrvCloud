//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DEVICES 50
#define MAX_SSID_LENGTH 32
#define MAX_BSSID_LENGTH 17

struct device_info {
    char ssid[MAX_SSID_LENGTH];
    char bssid[MAX_BSSID_LENGTH];
    int channel;
};

void generate_random_ssid(char *ssid) {
    int i;
    for (i = 0; i < MAX_SSID_LENGTH - 1; i++) {
        ssid[i] = 'a' + rand() % 26;
    }
    ssid[MAX_SSID_LENGTH - 1] = '\0';
}

void generate_random_bssid(char *bssid) {
    int i;
    for (i = 0; i < MAX_BSSID_LENGTH - 1; i++) {
        if (i % 3 == 2) {
            bssid[i] = ':';
        } else {
            bssid[i] = '0' + rand() % 16;
        }
    }
    bssid[MAX_BSSID_LENGTH - 1] = '\0';
}

void scan_wireless_network(struct device_info *devices, int *num_devices) {
    int i;
    srand(time(NULL));
    *num_devices = rand() % MAX_DEVICES;
    for (i = 0; i < *num_devices; i++) {
        generate_random_ssid(devices[i].ssid);
        generate_random_bssid(devices[i].bssid);
        devices[i].channel = rand() % 14 + 1;
    }
}

void print_device_info(struct device_info device) {
    printf("%s (%s), Channel %d\n", device.ssid, device.bssid, device.channel);
}

int main() {
    struct device_info devices[MAX_DEVICES];
    int i, num_devices;
    scan_wireless_network(devices, &num_devices);
    printf("Wireless Network Scan Results:\n");
    for (i = 0; i < num_devices; i++) {
        print_device_info(devices[i]);
    }
    return 0;
}