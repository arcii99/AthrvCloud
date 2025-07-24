//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SSID_LENGTH 32

typedef struct {
    char ssid[MAX_SSID_LENGTH + 1];
    int signal_strength;
} Network;

int main() {
    int num_networks;
    printf("Enter number of Wi-Fi networks: ");
    scanf("%d", &num_networks);

    Network* networks = (Network*) malloc(num_networks * sizeof(Network));
    for (int i = 0; i < num_networks; i++) {
        printf("Enter SSID and signal strength (out of 100) for network %d: ", i + 1);
        scanf("%s %d", networks[i].ssid, &networks[i].signal_strength);
    }

    printf("\nWi-Fi networks sorted by signal strength:\n");
    for (int i = 0; i < num_networks; i++) {
        for (int j = i + 1; j < num_networks; j++) {
            if (networks[i].signal_strength < networks[j].signal_strength) {
                Network temp = networks[i];
                networks[i] = networks[j];
                networks[j] = temp;
            }
        }
        printf("%s: %d\n", networks[i].ssid, networks[i].signal_strength);
    }

    free(networks);
    return 0;
}