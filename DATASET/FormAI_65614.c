//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NETWORKS 10
#define MAX_SSID_LENGTH 32

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int channel;
    float signal_strength;
} Network;

Network networks[MAX_NETWORKS];
int network_counter = 0;

void scan_networks() {
    // Simulate scanning for wireless networks
    for (int i = 0; i < MAX_NETWORKS; i++) {
        if (rand() % 2 == 0) {
            Network new_network;
            sprintf(new_network.ssid, "Network %d", i);
            new_network.channel = rand() % 12 + 1;
            new_network.signal_strength = (float) (rand() % 200) / 10 - 10;
            networks[network_counter] = new_network;
            network_counter++;
        }
    }
}

void print_networks() {
    for (int i = 0; i < network_counter; i++) {
        printf("SSID: %s, Channel: %d, Signal Strength: %.1f dBm\n", networks[i].ssid, networks[i].channel, networks[i].signal_strength);
    }
}

int main() {
    scan_networks();
    printf("Found %d wireless networks:\n", network_counter);
    print_networks();
    return 0;
}