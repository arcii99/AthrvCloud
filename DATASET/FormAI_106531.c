//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SSID_LENGTH 32
#define MAX_WIFI_NETWORKS 10

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} Network;

typedef struct {
    Network networks[MAX_WIFI_NETWORKS];
    int count;
} WifiData;

WifiData scan_wifi_networks() {
    WifiData wifi_data = {0};
    // code to scan available wifi networks and fill `wifi_data`

    // dummy data
    strcpy(wifi_data.networks[0].ssid, "Wifi Network 1");
    wifi_data.networks[0].signal_strength = -80;
    wifi_data.count = 1;
    
    return wifi_data;
}

void print_wifi_networks(WifiData wifi_data) {
    printf("Scanned wifi networks:\n");
    for (int i = 0; i < wifi_data.count; i++) {
        printf("%s (%d dBm)\n", wifi_data.networks[i].ssid, wifi_data.networks[i].signal_strength);
    }
}

void sort_wifi_networks(WifiData* wifi_data) {
    // simple bubble sort based on signal strength
    for (int i = 0; i < wifi_data->count - 1; i++) {
        for (int j = 0; j < wifi_data->count - i - 1; j++) {
            if (wifi_data->networks[j].signal_strength < wifi_data->networks[j+1].signal_strength) {
                Network temp = wifi_data->networks[j];
                wifi_data->networks[j] = wifi_data->networks[j+1];
                wifi_data->networks[j+1] = temp;
            }
        }
    }
}

int main() {
    WifiData wifi_data = scan_wifi_networks();
    print_wifi_networks(wifi_data);
    sort_wifi_networks(&wifi_data);
    printf("\nSorted wifi networks based on signal strength:\n");
    print_wifi_networks(wifi_data);
    return 0;
}