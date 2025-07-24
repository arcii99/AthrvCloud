//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NETWORKS 20
#define MAX_SSID_LEN 20

typedef struct Network {
    char ssid[MAX_SSID_LEN];
    int signal_strength;
} Network;

int main() {
    // Initialize variables
    Network networks[MAX_NETWORKS];
    int num_networks = 0;
    char input[100];
    
    // Simulate scanning for networks
    printf("Scanning for wireless networks...\n");
    for (int i = 0; i < 10; i++) {
        // Simulate finding a network
        Network network;
        sprintf(network.ssid, "Network%d", i);
        network.signal_strength = rand() % 101;
        
        // Add network to array if not already added
        bool already_added = false;
        for (int j = 0; j < num_networks; j++) {
            if (strcmp(network.ssid, networks[j].ssid) == 0) {
                already_added = true;
                break;
            }
        }
        if (!already_added) {
            if (num_networks >= MAX_NETWORKS) {
                printf("Maximum number of networks reached\n");
                break;
            } else {
                networks[num_networks] = network;
                num_networks++;
            }
        }
    }
    
    // Print out list of networks
    printf("List of available wireless networks:\n");
    for (int i = 0; i < num_networks; i++) {
        printf("%s : %d%%\n", networks[i].ssid, networks[i].signal_strength);
    }
    
    // Prompt user to connect to a network
    printf("Enter the name of the network you want to connect to:\n");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0;
    
    // Attempt to connect to the network
    bool connected = false;
    for (int i = 0; i < num_networks; i++) {
        if (strcmp(input, networks[i].ssid) == 0) {
            printf("Connecting to %s...\n", networks[i].ssid);
            printf("Successfully connected!\n");
            connected = true;
            break;
        }
    }
    if (!connected) {
        printf("Could not connect to %s\n", input);
    }
    
    return 0;
}