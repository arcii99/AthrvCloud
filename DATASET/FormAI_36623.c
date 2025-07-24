//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NETWORKS 50
#define MAX_SSID_LENGTH 20

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int rssi;
} Network;

int numberOfNetworks = 0;
Network networks[MAX_NETWORKS];

void addNetwork(char *ssid, int rssi) {
    if (numberOfNetworks >= MAX_NETWORKS) {
        printf("Error: Maximum number of networks reached.\n");
        return;
    }
    strcpy(networks[numberOfNetworks].ssid, ssid);
    networks[numberOfNetworks].rssi = rssi;
    numberOfNetworks++;
}

void printNetworks() {
    printf("SSID\t\tSignal Strength\n");
    for (int i = 0; i < numberOfNetworks; i++) {
        printf("%-20s%d dBm\n", networks[i].ssid, networks[i].rssi);
    }
}

double calculateAverageRssi() {
    if (numberOfNetworks == 0) {
        return 0;
    }
    int sum = 0;
    for (int i = 0; i < numberOfNetworks; i++) {
        sum += networks[i].rssi;
    }
    return (double)sum / numberOfNetworks;
}

int main() {
    printf("Wi-Fi Signal Strength Analyzer\n");

    // Simulate adding discovered networks
    addNetwork("NETGEAR27", -55);
    addNetwork("Linksys", -73);
    addNetwork("Homenetwork", -68);
    addNetwork("OfficeWLAN", -62);

    printf("\nDiscovered Networks:\n");
    printNetworks();

    double averageRssi = calculateAverageRssi();
    printf("\nAverage Signal Strength: %.2f dBm\n", averageRssi);

    return 0;
}