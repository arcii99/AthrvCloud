//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NETWORKS 10

int num_networks;
char ssid[MAX_NETWORKS][20];
int signal_strength[MAX_NETWORKS];

void scan_networks() {
    // Simulate scanning for available Wi-Fi networks
    num_networks = 5;
    strcpy(ssid[0], "HomeNetwork");
    signal_strength[0] = -55;
    strcpy(ssid[1], "OfficeNetwork");
    signal_strength[1] = -70;
    strcpy(ssid[2], "CoffeeShop");
    signal_strength[2] = -80;
    strcpy(ssid[3], "HotelWiFi");
    signal_strength[3] = -65;
    strcpy(ssid[4], "AirportWiFi");
    signal_strength[4] = -90;
}

void print_networks() {
    // Display all available Wi-Fi networks and their signal strengths
    printf("Available Wi-Fi Networks:\n");
    for (int i = 0; i < num_networks; i++) {
        printf("%s - Signal Strength: %d dBm\n", ssid[i], signal_strength[i]);
    }
}

void get_avg_signal_strength() {
    // Calculate the average signal strength of all available Wi-Fi networks
    int sum = 0;
    for (int i = 0; i < num_networks; i++) {
        sum += signal_strength[i];
    }
    int avg_signal_strength = sum / num_networks;
    printf("Average Wi-Fi Signal Strength: %d dBm\n", avg_signal_strength);
}

int main() {
    scan_networks();
    print_networks();
    get_avg_signal_strength();
    return 0;
}