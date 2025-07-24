//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SSID_LENGTH 32
#define MAX_NETWORKS 10

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} Network;

void scan_networks(Network* networks, int* num_networks);
void print_networks(Network* networks, int num_networks);
void sort_networks(Network* networks, int num_networks);
void report_best_network(Network* networks, int num_networks);

int main() {
    Network networks[MAX_NETWORKS];
    int num_networks = 0;
    
    printf("Scanning for Wi-Fi networks...\n");
    scan_networks(networks, &num_networks);
    
    printf("Found %d networks:\n", num_networks);
    print_networks(networks, num_networks);
    
    printf("Sorting networks by signal strength...\n");
    sort_networks(networks, num_networks);
    
    printf("Here are the networks sorted by signal strength:\n");
    print_networks(networks, num_networks);
    
    report_best_network(networks, num_networks);
    
    return 0;
}

void scan_networks(Network* networks, int* num_networks) {
    srand(time(NULL));
    int num_found = rand() % MAX_NETWORKS;
    for (int i = 0; i < num_found; i++) {
        sprintf(networks[i].ssid, "Network %d", i+1);
        networks[i].signal_strength = rand() % 101;
    }
    *num_networks = num_found;
}

void print_networks(Network* networks, int num_networks) {
    for (int i = 0; i < num_networks; i++) {
        printf("%-20s%d%%\n", networks[i].ssid, networks[i].signal_strength);
    }
}

void sort_networks(Network* networks, int num_networks) {
    for (int i = 0; i < num_networks-1; i++) {
        for (int j = i+1; j < num_networks; j++) {
            if (networks[j].signal_strength > networks[i].signal_strength) {
                Network temp = networks[i];
                networks[i] = networks[j];
                networks[j] = temp;
            }
        }
    }
}

void report_best_network(Network* networks, int num_networks) {
    if (num_networks > 0) {
        printf("The best network is %s with %d%% signal strength.\n",
            networks[0].ssid, networks[0].signal_strength);
    } else {
        printf("No networks found!\n");
    }
}