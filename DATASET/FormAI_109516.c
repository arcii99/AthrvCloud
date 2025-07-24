//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define NUM_NETWORKS 5
#define MAX_SSID_LENGTH 20
#define MAX_SIGNAL_STRENGTH 100

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} WirelessNetwork;

WirelessNetwork scan_networks() {
    WirelessNetwork networks[NUM_NETWORKS];
    srand(time(NULL));

    for (int i = 0; i < NUM_NETWORKS; i++) {
        char ssid[MAX_SSID_LENGTH];
        int signal_strength = rand() % MAX_SIGNAL_STRENGTH;

        for (int j = 0; j < MAX_SSID_LENGTH-1; j++) {
            ssid[j] = (char)((rand() % 26) + 97);
        }
        ssid[MAX_SSID_LENGTH-1] = '\0';

        strcpy(networks[i].ssid, ssid);
        networks[i].signal_strength = signal_strength;
    }

    int strongest_network_index = 0;
    for (int i = 1; i < NUM_NETWORKS; i++) {
        if (networks[i].signal_strength > networks[strongest_network_index].signal_strength) {
            strongest_network_index = i;
        }
    }
    return networks[strongest_network_index];
}

int main() {
    printf("Scanning wireless networks...\n");
    WirelessNetwork strongest_network = scan_networks();
    printf("Strongest network found: SSID: %s, Signal Strength: %d\n",
           strongest_network.ssid, strongest_network.signal_strength);
    return 0;
}