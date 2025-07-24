//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure for capturing network information
struct network {
    char ssid[20];
    char security[10];
    int signal_strength;
} available_networks[10];

// Function for printing network information
void print_network_info(struct network nw) {
    printf("SSID: %s\n", nw.ssid);
    printf("Security: %s\n", nw.security);
    printf("Signal Strength: %d\n", nw.signal_strength);
    printf("------------------------\n");
}

int main() {
    // Simulation of available networks
    struct network network1 = {"Network1", "WPA", 70};
    struct network network2 = {"Network2", "Open", 80};
    struct network network3 = {"Network3", "WEP", 60};
    struct network network4 = {"Network4", "WPA2", 90};
    struct network network5 = {"Network5", "Open", 50};

    // Putting available networks in array
    available_networks[0] = network1;
    available_networks[1] = network2;
    available_networks[2] = network3;
    available_networks[3] = network4;
    available_networks[4] = network5;

    // Displaying available networks
    printf("Available Networks:\n");
    for(int i=0; i<5; i++) {
        print_network_info(available_networks[i]);
    }

    return 0;
}