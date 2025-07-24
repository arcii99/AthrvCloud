//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORKS 10
#define MAX_SSID_LENGTH 32

struct network {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
};

int main() {
    struct network networks[MAX_NETWORKS];
    int num_networks = 0;

    // Simulate scanning for nearby networks and populate networks array
    strcpy(networks[0].ssid, "MyHomeNetwork");
    networks[0].signal_strength = -60;
    num_networks++;
    strcpy(networks[1].ssid, "CoffeeShopWiFi");
    networks[1].signal_strength = -80;
    num_networks++;
    strcpy(networks[2].ssid, "OfficeWiFi");
    networks[2].signal_strength = -70;
    num_networks++;

    printf("Found %d networks:\n", num_networks);
    for (int i = 0; i < num_networks; i++) {
        printf("%s: %d dBm\n", networks[i].ssid, networks[i].signal_strength);
    }

    // Find the network with the highest signal strength
    int max_signal_strength = -1000;
    char max_ssid[MAX_SSID_LENGTH];
    for (int i = 0; i < num_networks; i++) {
        if (networks[i].signal_strength > max_signal_strength) {
            max_signal_strength = networks[i].signal_strength;
            strcpy(max_ssid, networks[i].ssid);
        }
    }

    printf("The network with the highest signal strength is %s with %d dBm\n", max_ssid, max_signal_strength);

    return 0;
}