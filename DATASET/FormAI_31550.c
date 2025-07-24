//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SSID_LENGTH 32

struct WiFiNetwork {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
};

typedef struct WiFiNetwork WiFiNetwork;

int main() {
    int num_networks, i, j;
    printf("Enter the number of WiFi networks to analyze: ");
    scanf("%d", &num_networks);

    WiFiNetwork networks[num_networks];
    for(i = 0; i < num_networks; i++) {
        printf("Enter the SSID of network %d: ", i + 1);
        scanf("%s", networks[i].ssid);

        if(strlen(networks[i].ssid) > MAX_SSID_LENGTH) {
            printf("Invalid SSID. Max length is %d. Exiting...\n", MAX_SSID_LENGTH);
            exit(1);
        }

        printf("Enter the signal strength of network %d (in dBm): ", i + 1);
        scanf("%d", &networks[i].signal_strength);
    }

    printf("\nAnalyzing WiFi networks...\n");

    // Bubble Sort the networks based on signal strength
    for(i = 0; i < num_networks; i++) {
        for(j = 0; j < num_networks - i - 1; j++) {
            if(networks[j].signal_strength < networks[j+1].signal_strength) {
                // Swap the positions of the networks
                WiFiNetwork temp = networks[j];
                networks[j] = networks[j+1];
                networks[j+1] = temp;
            }
        }
    }

    printf("\nResults:\n");
    printf("=====================================\n");
    printf("| %-4s | %-10s | %-15s |\n", "Rank", "SSID", "Signal Strength");
    printf("=====================================\n");
    for(i = 0; i < num_networks; i++) {
        printf("| %-4d | %-10s | %-15d |\n", i + 1, networks[i].ssid, networks[i].signal_strength);
    }
    printf("=====================================\n");

    return 0;
}