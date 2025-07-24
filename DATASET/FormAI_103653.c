//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SSID_LEN 32
#define MAX_SIGNAL_STRENGTH 100

typedef struct {
    char ssid[MAX_SSID_LEN];
    int signal_strength;
} WiFi_network;

int num_networks = 0;
WiFi_network networks[10];

void populate_networks() {
    strcpy(networks[0].ssid, "WiFi1");
    networks[0].signal_strength = 75;
    
    strcpy(networks[1].ssid, "WiFi2");
    networks[1].signal_strength = 90;
    
    strcpy(networks[2].ssid, "WiFi3");
    networks[2].signal_strength = 50;
    
    num_networks = 3;
}

void print_networks() {
    printf("WiFi Networks:\n");
    for (int i = 0; i < num_networks; i++) {
        printf("%s: %d\n", networks[i].ssid, networks[i].signal_strength);
    }
}

int get_average_signal_strength() {
    int sum = 0;
    for (int i = 0; i < num_networks; i++) {
        sum += networks[i].signal_strength;
    }
    
    return sum/num_networks;
}

int get_strongest_signal() {
    int max_strength = -1;
    int index = -1;
    
    for (int i = 0; i < num_networks; i++) {
        if (networks[i].signal_strength > max_strength) {
            max_strength = networks[i].signal_strength;
            index = i;
        }
    }
    
    return index;
}

int main() {
    printf("Populating WiFi networks...\n");
    populate_networks();
    printf("Done.\n\n");
    
    print_networks();
    
    int avg_strength = get_average_signal_strength();
    printf("\nAverage signal strength is: %d\n", avg_strength);
    
    int strongest_signal_index = get_strongest_signal();
    printf("\nStrongest signal is from %s with a strength of %d\n", networks[strongest_signal_index].ssid, networks[strongest_signal_index].signal_strength);
    
    return 0;
}