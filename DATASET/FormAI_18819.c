//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NETWORKS 10
#define MAX_SSID_LEN 32

typedef struct {
    char ssid[MAX_SSID_LEN];
    int signal_strength;
} network_t;

void print_networks(network_t networks[], int num_networks) {
    printf("Available Wi-Fi networks:\n");
    for (int i = 0; i < num_networks; i++) {
        printf("%s - Signal strength: %ddBm\n", networks[i].ssid, networks[i].signal_strength);
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator with current time

    network_t networks[MAX_NETWORKS];
    int num_networks = rand() % MAX_NETWORKS; // Generate random number of networks (up to MAX_NETWORKS)
    for (int i = 0; i < num_networks; i++) {
        // Generate random SSID
        char ssid[MAX_SSID_LEN];
        int ssid_len = rand() % (MAX_SSID_LEN - 1) + 1; // Random length, between 1 and MAX_SSID_LEN-1
        for (int j = 0; j < ssid_len; j++) {
            ssid[j] = 'a' + rand() % 26;
        }
        ssid[ssid_len] = '\0';

        // Generate random signal strength
        int signal_strength = rand() % 101 - 100; // Random value between -100 and 0

        // Add network to array
        strncpy(networks[i].ssid, ssid, MAX_SSID_LEN);
        networks[i].signal_strength = signal_strength;
    }

    print_networks(networks, num_networks);

    return 0;
}