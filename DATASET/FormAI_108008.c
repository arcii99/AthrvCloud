//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SSID_LENGTH 32
#define MAX_CHANNEL 14

typedef struct WirelessNetwork {
    char ssid[MAX_SSID_LENGTH];
    int channel;
    bool secured;
} WirelessNetwork;

void scanWirelessNetworks(WirelessNetwork* networks, int* count) {
    printf("Scanning for wireless networks...\n");
    // scanning code goes here
    // for demonstration purposes, let's create some fake networks
    strcpy(networks[0].ssid, "HappyWiFi");
    networks[0].channel = 1;
    networks[0].secured = true;
    strcpy(networks[1].ssid, "BrightNet");
    networks[1].channel = 6;
    networks[1].secured = false;
    strcpy(networks[2].ssid, "RainbowLAN");
    networks[2].channel = 11;
    networks[2].secured = true;
    *count = 3;
}

void printWirelessNetworks(WirelessNetwork* networks, int count) {
    printf("Found %d wireless networks:\n", count);
    for (int i = 0; i < count; i++) {
        printf("%s (channel %d, %s)\n", networks[i].ssid, networks[i].channel, networks[i].secured ? "secured" : "unsecured");
    }
}

int main() {
    WirelessNetwork networks[10];
    int count = 0;
    scanWirelessNetworks(networks, &count);
    printWirelessNetworks(networks, count);
    return 0;
}