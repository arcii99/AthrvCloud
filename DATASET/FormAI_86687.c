//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_SSID_LENGTH 32
#define MAX_BSSID_LENGTH 18
#define MAX_SIGNAL_STRENGTH 100

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    char bssid[MAX_BSSID_LENGTH];
    int signal_strength;
} WiFiNetwork;

void add_network(WiFiNetwork *networks, int *num_networks, char *ssid, char *bssid, int signal_strength) {
    strcpy(networks[*num_networks].ssid, ssid);
    strcpy(networks[*num_networks].bssid, bssid);
    networks[*num_networks].signal_strength = signal_strength;
    (*num_networks)++;
}

void print_networks(WiFiNetwork *networks, int num_networks) {
    printf("SSID\t\tBSSID\t\tSignal Strength\n");
    for (int i = 0; i < num_networks; i++) {
        printf("%s\t%s\t%d\n", networks[i].ssid, networks[i].bssid, networks[i].signal_strength);
    }
}

int main() {
    int num_networks = 0;
    WiFiNetwork *networks = malloc(sizeof(WiFiNetwork) * 10);

    // Simulating WiFi scanning
    add_network(networks, &num_networks, "MyNetwork", "12:34:56:78:9a:bc", 75);
    add_network(networks, &num_networks, "GuestNetwork", "de:f0:12:34:56:78", 50);
    add_network(networks, &num_networks, "OfficeNetwork", "9a:bc:de:f0:12:34", 90);

    // Printing out the scanned networks
    print_networks(networks, num_networks);

    return 0;
}