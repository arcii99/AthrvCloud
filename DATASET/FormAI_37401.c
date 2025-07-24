//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
    char ssid[32];
    int signal_strength;
} wifi_network;

void scan_wifi(wifi_network *networks, int num_networks) {
    printf("Scanning for Wi-Fi networks...\n");
    // Code to scan for Wi-Fi networks goes here. This can be done using a system call to a command line tool like iwlist.
    // Since the details of how to do this are beyond the scope of this example, we'll just generate some random data instead.
    for (int i = 0; i < num_networks; i++) {
        sprintf(networks[i].ssid, "WiFi%d", i);
        networks[i].signal_strength = rand() % 100;
    }
}

void print_networks(wifi_network *networks, int num_networks) {
    printf("Found %d Wi-Fi network(s):\n", num_networks);
    for (int i = 0; i < num_networks; i++) {
        printf("%s (Signal Strength: %d%%)\n", networks[i].ssid, networks[i].signal_strength);
    }
}

int main(int argc, char *argv[]) {
    int num_networks = 0;
    if (argc == 2) {
        num_networks = atoi(argv[1]);
    }
    if (num_networks <= 0) {
        printf("Please enter a valid number of Wi-Fi networks to scan.\n");
        return 1;
    }

    wifi_network *networks = malloc(sizeof(wifi_network) * num_networks);
    if (networks == NULL) {
        printf("Error: failed to allocate memory for Wi-Fi networks.\n");
        return 1;
    }

    scan_wifi(networks, num_networks);
    print_networks(networks, num_networks);
    
    free(networks);
    return 0;
}