//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORKS 10 // Maximum number of networks to scan
#define MAX_SSID_LENGTH 32 // Maximum length of SSID name

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} wifi_network;

// Function to scan for available Wi-Fi networks and return an array of wifi_network structs
wifi_network* scan_wifi() {
    // Simulating Wi-Fi scan by randomly generating signal strengths for up to MAX_NETWORKS
    wifi_network* networks = malloc(MAX_NETWORKS * sizeof(wifi_network));
    if (networks == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    int num_networks = rand() % (MAX_NETWORKS + 1);
    for (int i = 0; i < num_networks; i++) {
        int signal_strength = rand() % 101; // Generate a signal strength from 0 to 100
        sprintf(networks[i].ssid, "Network%d", i); // Set network SSID as "NetworkX" where X is the index number
        networks[i].signal_strength = signal_strength;
    }
    return networks;
}

// Function to print out the list of available Wi-Fi networks and their signal strengths
void print_wifi_list(wifi_network* networks, int num_networks) {
    printf("Available Wi-Fi networks:\n");
    printf("-------------------------\n");
    for (int i = 0; i < num_networks; i++) {
        printf("%s: %d%%\n", networks[i].ssid, networks[i].signal_strength);
    }
}

// Main function to run the Wi-Fi signal strength analyzer program
int main() {
    // Scan for available Wi-Fi networks and print out list
    wifi_network* networks = scan_wifi();
    int num_networks = sizeof(networks) / sizeof(wifi_network);
    print_wifi_list(networks, num_networks);
    free(networks);
    return 0;
}