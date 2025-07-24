//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORKS 10
#define MAX_SSID_LENGTH 32

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} Network;

void scan_networks(Network *networks, int *num_networks) {
    // Mock function to simulate scanning for available Wi-Fi networks
    strcpy(networks[0].ssid, "My_WiFi_Network");
    networks[0].signal_strength = -75;
    strcpy(networks[1].ssid, "HomeNetwork");
    networks[1].signal_strength = -80;
    strcpy(networks[2].ssid, "CoffeeShopWiFi");
    networks[2].signal_strength = -60;
    *num_networks = 3;
}

int main() {
    Network networks[MAX_NETWORKS];
    int num_networks = 0;

    // Scan for available Wi-Fi networks
    scan_networks(networks, &num_networks);

    printf("Available Wi-Fi Networks:\n");
    for (int i = 0; i < num_networks; i++) {
        printf("%d. %s (%d dBm)\n", i+1, networks[i].ssid, networks[i].signal_strength);
    }

    // Calculate average signal strength
    int total_signal_strength = 0;
    for (int i = 0; i < num_networks; i++) {
        total_signal_strength += networks[i].signal_strength;
    }
    int average_signal_strength = total_signal_strength / num_networks;

    printf("Average Signal Strength: %d dBm\n", average_signal_strength);

    // Find strongest network
    int max_signal_strength = -100;
    char strongest_network[MAX_SSID_LENGTH];
    for (int i = 0; i < num_networks; i++) {
        if (networks[i].signal_strength > max_signal_strength) {
            max_signal_strength = networks[i].signal_strength;
            strcpy(strongest_network, networks[i].ssid);
        }
    }

    printf("Strongest Network: %s (%d dBm)\n", strongest_network, max_signal_strength);

    return 0;
}