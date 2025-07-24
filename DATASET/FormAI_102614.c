//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_DEVICES 1000

struct device {
    char name[50];
    int signal_strength;
};

void get_random_name(char *name) {
    const char *prefixes[] = {"TP-Link", "Linksys", "Netgear", "D-Link", "Asus", "Belkin", "Buffalo", "Cisco"};
    const char *types[] = {"Router", "Access Point", "Extender", "Repeater", "Modem", "Gateway"};
    const char *suffixes[] = {"A", "B", "C", "D", "E"};
    sprintf(name, "%s %s %s", prefixes[rand() % 8], types[rand() % 6], suffixes[rand() % 5]);
}

int get_random_signal_strength() {
    return -rand() % 101; // generate negative value for simplicity
}

void print_device(struct device *d) {
    printf("%-50s%+3d dBm\n", d->name, d->signal_strength);
}

int main() {
    struct device devices[MAX_DEVICES];
    int num_devices = rand() % MAX_DEVICES;
    
    for (int i = 0; i < num_devices; i++) {
        get_random_name(devices[i].name);
        devices[i].signal_strength = get_random_signal_strength();
    }
    
    // Sort array of devices by signal strength (higher magnitude signal means closer to 0, so we flip sign)
    for (int i = 0; i < num_devices - 1; i++) {
        for (int j = 0; j < num_devices - i - 1; j++) {
            if (abs(devices[j].signal_strength) < abs(devices[j+1].signal_strength)) {
                struct device temp = devices[j];
                devices[j] = devices[j+1];
                devices[j+1] = temp;
            }
        }
    }
    
    // Print sorted array of devices
    printf("Wi-Fi Signal Strength Analyzer\n\n");
    printf("%-50sSignal Strength\n", "Device Name");
    printf("----------------------------------------------\n");
    for (int i = 0; i < num_devices; i++) {
        print_device(&devices[i]);
    }
    
    return 0;
}