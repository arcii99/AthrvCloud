//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SSID_LEN 32
#define MAX_WIFI_NETWORKS 10

typedef struct {
    char ssid[MAX_SSID_LEN];
    int signal_strength;
} wifi_network_t;

wifi_network_t wifi_networks[MAX_WIFI_NETWORKS];
int num_wifi_networks = 0;

void scan_wifi_networks() {
    // perform scanning logic here and store results in wifi_networks array
    // dummy data for now
    strcpy(wifi_networks[0].ssid, "MyWiFiNetwork");
    wifi_networks[0].signal_strength = -60;

    strcpy(wifi_networks[1].ssid, "OtherWiFiNetwork");
    wifi_networks[1].signal_strength = -85;

    num_wifi_networks = 2;
}

void display_wifi_networks() {
    printf("\n");
    printf("Available WiFi Networks:\n");
    printf("------------------------\n");
    for(int i = 0; i < num_wifi_networks; i++) {
        wifi_network_t network = wifi_networks[i];
        printf("%s\t\tSignal Strength: %d dBm\n", network.ssid, network.signal_strength);
    }
    printf("\n");
}

int main() {
    scan_wifi_networks();
    display_wifi_networks();
    return 0;
}