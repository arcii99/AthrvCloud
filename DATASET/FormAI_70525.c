//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: calm
// Wi-Fi Signal Strength Analyzer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORKS 25 // maximum number of networks to scan
#define MAX_SSID_LEN 32 // maximum length of SSID

typedef struct {
    char ssid[MAX_SSID_LEN + 1];
    int strength;
} Network;

int num_networks = 0;
Network networks[MAX_NETWORKS];

void add_network(char ssid[], int strength) {
    if (num_networks >= MAX_NETWORKS) {
        printf("Maximum number of networks reached. Cannot add new network.\n");
        return;
    }
    strncpy(networks[num_networks].ssid, ssid, MAX_SSID_LEN);
    networks[num_networks].ssid[MAX_SSID_LEN] = '\0'; // ensure null termination
    networks[num_networks].strength = strength;
    num_networks++;
}

int main() {
    printf("Wi-Fi Signal Strength Analyzer\n\n");

    // simulate scanning for networks and their signal strengths
    add_network("MyWifi", -60);
    add_network("CoffeeShop", -85);
    add_network("Library", -70);

    // display list of networks and their signal strengths
    printf("Network\t\tSignal Strength\n");
    for (int i = 0; i < num_networks; i++) {
        printf("%s\t\t%d dBm\n", networks[i].ssid, networks[i].strength);
    }

    return 0;
}