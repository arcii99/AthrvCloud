//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIFI_SIGNAL_STRENGTH 100
#define MIN_WIFI_SIGNAL_STRENGTH 0

typedef struct {
    char ssid[32];
    int signalStrength;
} wifi_device_t;

typedef struct {
    wifi_device_t devices[10];
    int num_devices;
} wifi_network_t;

void print_devices(wifi_network_t network) {
    printf("\nSSID\tSignal Strength\n");
    printf("------------------------\n");
    for(int i = 0; i < network.num_devices; i++) {
        printf("%s\t%d%%\n", network.devices[i].ssid, network.devices[i].signalStrength);
    }
}

void add_device(wifi_network_t *network, wifi_device_t device) {
    if(network->num_devices == 10) {
        printf("Network is full! Could not add device.\n");
    } else {
        network->devices[network->num_devices] = device;
        network->num_devices++;
    }
}

wifi_device_t get_device_with_highest_signal_strength(wifi_network_t network) {
    int highest_signal_strength = MIN_WIFI_SIGNAL_STRENGTH;
    wifi_device_t device_with_highest_strength;
    for(int i = 0; i < network.num_devices; i++) {
        if(network.devices[i].signalStrength > highest_signal_strength) {
            highest_signal_strength = network.devices[i].signalStrength;
            device_with_highest_strength = network.devices[i];
        }
    }
    return device_with_highest_strength;
}

int main() {
    wifi_device_t device1 = {"Home Wifi", 75};
    wifi_device_t device2 = {"Guest Wifi", 60};
    wifi_device_t device3 = {"Office Wifi", 88};
    wifi_device_t device4 = {"Public Wifi", 40};
    
    wifi_network_t network;
    network.num_devices = 0;
    add_device(&network, device1);
    add_device(&network, device2);
    add_device(&network, device3);
    add_device(&network, device4);
    
    printf("Initial Wifi Network:\n");
    print_devices(network);
    
    wifi_device_t device5 = {"Cafe Wifi", 95};
    add_device(&network, device5);
    
    printf("\nWifi Network after adding Cafe Wifi:\n");
    print_devices(network);
    
    wifi_device_t device_with_highest_strength = get_device_with_highest_signal_strength(network);
    printf("\nThe device with highest signal strength is %s with %d%% strength.\n", device_with_highest_strength.ssid, device_with_highest_strength.signalStrength);
    
    return 0;
}