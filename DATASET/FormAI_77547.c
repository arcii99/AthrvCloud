//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_NETWORKS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int signal_strength;
} Network;

void scan_networks(Network networks[MAX_NETWORKS], int *num_networks) {
    printf("Scanning for WiFi networks...\n");
    printf("Found 5 networks:\n");

    strcpy(networks[0].name, "HomeWiFi");
    networks[0].signal_strength = -50;

    strcpy(networks[1].name, "StarbucksWiFi");
    networks[1].signal_strength = -70;

    strcpy(networks[2].name, "AirportWiFi");
    networks[2].signal_strength = -60;

    strcpy(networks[3].name, "LibraryWiFi");
    networks[3].signal_strength = -80;

    strcpy(networks[4].name, "McDonaldsWiFi");
    networks[4].signal_strength = -65;

    *num_networks = 5;
}

int main() {
    Network networks[MAX_NETWORKS];
    int num_networks = 0;

    scan_networks(networks, &num_networks);

    printf("SSID\t\tSignal Strength\n");
    for (int i = 0; i < num_networks; i++) {
        printf("%s\t\t%d dBm\n", networks[i].name, networks[i].signal_strength);
    }

    return 0;
}