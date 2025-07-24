//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SSID_LENGTH 32
#define MAX_NETWORKS 10

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} Network;

void get_networks(Network *networks, int *num_networks) {
    printf("Scanning for networks...\n");
    // dummy data for demonstration purposes
    strcpy(networks[0].ssid, "Wifi1");
    networks[0].signal_strength = -50;
    strcpy(networks[1].ssid, "Wifi2");
    networks[1].signal_strength = -80;
    strcpy(networks[2].ssid, "Wifi3");
    networks[2].signal_strength = -70;
    *num_networks = 3; // update the number of networks found
}

void display_networks(Network *networks, int num_networks) {
    printf("Found %d networks:\n", num_networks);
    for (int i = 0; i < num_networks; i++) {
        printf("%d) SSID: %s | Signal Strength: %d dBm\n", i+1, networks[i].ssid, networks[i].signal_strength);
    }
}

void analyze_networks(Network *networks, int num_networks) {
    int strongest_index = 0;
    int weakest_index = 0;
    for (int i = 1; i < num_networks; i++) {
        if (networks[i].signal_strength > networks[strongest_index].signal_strength) {
            strongest_index = i;
        }
        if (networks[i].signal_strength < networks[weakest_index].signal_strength) {
            weakest_index = i;
        }
    }
    printf("The strongest network is %s with signal strength %d dBm.\n", networks[strongest_index].ssid, networks[strongest_index].signal_strength);
    printf("The weakest network is %s with signal strength %d dBm.\n", networks[weakest_index].ssid, networks[weakest_index].signal_strength);
}

int main() {
    Network networks[MAX_NETWORKS];
    int num_networks = 0;
    get_networks(networks, &num_networks);
    if (num_networks == 0) {
        printf("No networks found.\n");
        return 0;
    }
    display_networks(networks, num_networks);
    analyze_networks(networks, num_networks);
    return 0;
}