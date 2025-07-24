//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_NETWORKS 10
#define MAX_SSID_LENGTH 32

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength; // in dBm
} Network;

void populate_networks(Network* networks, int num_networks) {
    char ssids[MAX_NETWORKS][MAX_SSID_LENGTH] = {"Network1", "Network2", "Network3", "Network4", "Network5", "Network6", "Network7", "Network8", "Network9", "Network10"};
    int signal_strengths[MAX_NETWORKS] = {-75, -80, -70, -68, -65, -68, -72, -73, -76, -78};
    
    for (int i = 0; i < num_networks; i++) {
        strcpy(networks[i].ssid, ssids[i]);
        networks[i].signal_strength = signal_strengths[i];
    }
}

void print_networks(Network* networks, int num_networks) {
    printf("WiFi networks in range:\n");
    for (int i = 0; i < num_networks; i++) {
        printf("%s: %ddBm\n", networks[i].ssid, networks[i].signal_strength);
    }
    printf("\n");
}

void sort_networks(Network* networks, int num_networks) {
    // Bubble sort based on signal strength
    for (int i = 0; i < num_networks-1; i++) {
        for (int j = 0; j < num_networks-i-1; j++) {
            if (networks[j].signal_strength < networks[j+1].signal_strength) {
                Network temp = networks[j];
                networks[j] = networks[j+1];
                networks[j+1] = temp;
            }
        }
    }
}

void display_top_networks(Network* networks, int num_networks, int num_top) {
    sort_networks(networks, num_networks);
    printf("Top %d WiFi networks in range:\n", num_top);
    for (int i = 0; i < num_top && i < num_networks; i++) {
        printf("%s: %ddBm\n", networks[i].ssid, networks[i].signal_strength);
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // Seed for random signal strength values
    Network networks[MAX_NETWORKS];
    int num_networks = rand() % MAX_NETWORKS + 1;
    populate_networks(networks, num_networks);
    print_networks(networks, num_networks);
    int num_top = rand() % num_networks + 1;
    display_top_networks(networks, num_networks, num_top);
    return 0;
}