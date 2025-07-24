//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NETWORKS 10
#define MAX_SSID_LENGTH 50

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} Network;

void scan_networks(Network *networks, int *num_networks, int max_networks) {
    printf("Scanning for wireless networks...\n");
    // Code to scan for networks and store the output in the 'networks' array
    
    // For now, let's just add some dummy networks
    *num_networks = 4;
    strcpy(networks[0].ssid, "My WiFi Network");
    networks[0].signal_strength = -84;
    strcpy(networks[1].ssid, "Neighbour1");
    networks[1].signal_strength = -78;
    strcpy(networks[2].ssid, "Neighbour2");
    networks[2].signal_strength = -87;
    strcpy(networks[3].ssid, "SomeOtherNetwork");
    networks[3].signal_strength = -70;
}

void print_networks(Network *networks, int num_networks) {
    printf("\nFound %d networks:\n", num_networks);
    printf("%-30s Signal Strength\n", "SSID");
    for (int i = 0; i < num_networks; i++) {
        printf("%-30s %d dBm\n", networks[i].ssid, networks[i].signal_strength);
    }
}

void sort_networks(Network *networks, int num_networks) {
    // Insertion sort algorithm to sort networks by signal strength
    for (int i = 1; i < num_networks; i++) {
        Network key = networks[i];
        int j = i - 1;
        while (j >= 0 && networks[j].signal_strength < key.signal_strength) {
            networks[j + 1] = networks[j];
            j = j - 1;
        }
        networks[j + 1] = key;
    }
}

int main() {
    Network networks[MAX_NETWORKS];
    int num_networks = 0;
    int max_networks = MAX_NETWORKS;
    
    // Scan for networks and store the results in the 'networks' array
    scan_networks(networks, &num_networks, max_networks);
    
    // Print the list of networks
    print_networks(networks, num_networks);
    
    // Sort the networks by signal strength
    sort_networks(networks, num_networks);
    
    // Print the sorted list of networks
    printf("\nSorted by signal strength:\n");
    print_networks(networks, num_networks);
    
    return 0;
}