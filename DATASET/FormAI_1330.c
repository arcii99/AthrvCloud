//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// Constants
#define MAX_NETWORKS 10
#define MAX_SSID_LEN 20
#define RSSI_THRESHOLD -70

// Structs
typedef struct {
    char ssid[MAX_SSID_LEN];
    int rssi;
} Network;

// Function prototypes
void scanNetworks(Network *networks, int *numNetworks);
void printNetworks(Network *networks, int numNetworks);
int compareNetworks(const void *a, const void *b);

int main() {
    Network networks[MAX_NETWORKS];
    int numNetworks = 0;

    printf("Scanning for Wi-Fi networks...\n");
    scanNetworks(networks, &numNetworks);

    printf("\n\nFound %d networks:\n", numNetworks);
    printNetworks(networks, numNetworks);

    qsort(networks, numNetworks, sizeof(Network), compareNetworks);

    printf("\n\nSorted by signal strength:\n");
    printNetworks(networks, numNetworks);

    printf("\n\nStrongest network found: %s\n", networks[0].ssid);
    printf("Signal strength: %d dBm\n", networks[0].rssi);

    if (networks[0].rssi < RSSI_THRESHOLD) {
        printf("Alert! Strongest network is weaker than threshold of -70 dBm.\n");
    }

    return 0;
}

void scanNetworks(Network *networks, int *numNetworks) {
    // In a real system, this function would use the Wi-Fi module to scan for networks
    // and populate the networks array with the results. Since we don't have a real
    // Wi-Fi module in this simulation, we'll just hard-code some sample data.
    strcpy(networks[0].ssid, "MyHomeNetwork");
    networks[0].rssi = -50;
    (*numNetworks)++;

    strcpy(networks[1].ssid, "Starbucks");
    networks[1].rssi = -60;
    (*numNetworks)++;

    strcpy(networks[2].ssid, "AirportFreeWifi");
    networks[2].rssi = -70;
    (*numNetworks)++;
}

void printNetworks(Network *networks, int numNetworks) {
    printf("\n");
    for (int i = 0; i < numNetworks; i++) {
        printf("%s: %d dBm\n", networks[i].ssid, networks[i].rssi);
    }
}

int compareNetworks(const void *a, const void *b) {
    return ((Network*)b)->rssi - ((Network*)a)->rssi;
}