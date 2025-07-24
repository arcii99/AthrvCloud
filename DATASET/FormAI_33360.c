//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SSID_LENGTH 50
#define MAX_WIFI_NETWORKS 10

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} wifi_network;

int compare_signal_strength(const void* a, const void* b) {
    wifi_network* network_a = (wifi_network*) a;
    wifi_network* network_b = (wifi_network*) b;

    return network_b->signal_strength - network_a->signal_strength;
}

int main() {
    wifi_network networks[MAX_WIFI_NETWORKS];
    int num_networks = 0;

    char buffer[MAX_SSID_LENGTH+10];
    while (num_networks < MAX_WIFI_NETWORKS) {
        printf("Enter the SSID and signal strength for network %d (or type 'done' to stop): ", num_networks+1);
        fgets(buffer, sizeof(buffer), stdin);

        if (strcmp(buffer, "done\n") == 0) {
            break;
        }

        char* ssid_end = strchr(buffer, ',');
        if (ssid_end == NULL) {
            printf("Invalid input - could not find comma separator.\n");
            continue;
        }

        *ssid_end = '\0';
        wifi_network network;
        strncpy(network.ssid, buffer, MAX_SSID_LENGTH);
        network.signal_strength = atoi(ssid_end+1);

        networks[num_networks++] = network;
    }

    if (num_networks == 0) {
        printf("No networks entered - exiting program.\n");
        return 0;
    }

    // sort the networks by signal strength
    qsort(networks, num_networks, sizeof(wifi_network), compare_signal_strength);

    // print the network details
    printf("\nWi-Fi Networks (sorted by signal strength):\n");
    for (int i = 0; i < num_networks; i++) {
        printf("%d. %s - %ddBm\n", i+1, networks[i].ssid, networks[i].signal_strength);
    }

    return 0;
}