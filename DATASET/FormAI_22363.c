//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_NETWORKS 10
#define MAX_SSID_LENGTH 32

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} wifi_network_t;

int main() {
    wifi_network_t networks[MAX_NUM_NETWORKS];
    int num_networks = 0;

    // Some code to fetch the current list of available Wi-Fi networks,
    // and their corresponding signal strengths, from the underlying OS.
    // This may involve calling external libraries or system APIs.

    // For the sake of simplicity, we'll just hardcode a few networks here.
    strcpy(networks[0].ssid, "my_wifi_network");
    networks[0].signal_strength = -70;
    strcpy(networks[1].ssid, "guest_wifi");
    networks[1].signal_strength = -80;
    strcpy(networks[2].ssid, "work_wifi");
    networks[2].signal_strength = -50;
    num_networks = 3;

    printf("Found %d Wi-Fi networks:\n", num_networks);
    for (int i = 0; i < num_networks; i++) {
        printf("%s (%d dBm)\n", networks[i].ssid, networks[i].signal_strength);
    }

    // Sort the list of Wi-Fi networks by signal strength (in descending order).
    for (int i = 0; i < num_networks; i++) {
        for (int j = i + 1; j < num_networks; j++) {
            if (networks[j].signal_strength > networks[i].signal_strength) {
                wifi_network_t temp = networks[i];
                networks[i] = networks[j];
                networks[j] = temp;
            }
        }
    }

    printf("\nRanking of Wi-Fi networks by signal strength:\n");
    for (int i = 0; i < num_networks; i++) {
        printf("%d. %s (%d dBm)\n", i+1, networks[i].ssid, networks[i].signal_strength);
    }

    return 0;
}